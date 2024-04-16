/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 15/04/2024
 * @brief Development of tools functions
 * @bug
 * @see
*/
#include "../include/tools.h"

/**
 * @brief Change password of an user
*/
void Password(System& system, User& user) {
  std::string username = user.GetName();
  std::string password;
  std::string new_password;
  std::cout << "\n###### Change password ######\n\n";
  /// Check if the user exist
  if (system.ExistentUser(username)) {
    /// Security check
    std::cout << "\nPassword: ";
    std::cin >> password;
    if (system.VerifyPassword(username, password)) {
      /// Getting the new password
      do {
        std::cout << "\nNew password: ";
        std::cin >> new_password;
      } while (new_password.size() < 4);
      system.ChangePassword(user, new_password);
      std::cout << "\nPassword changed successfully\n";
    } else {
      std::cout << "\nIncorrect password\n";
    }
  } else {
    std::cout << "\nUser not found\n";
  }
}

/**
 * @brief Search for a book
 * @param system reference to the system
*/
void Search(System& system) {
  std::string name;
  std::cout << "\n###### Search ######\n\n";
  std::cout << "\nWhat are you looking for?: ";
  std::cin >> name;
  std::transform(name.begin(), name.end(), name.begin(),
                   [](unsigned char c) -> unsigned char { return std::tolower(c); });
  system.ExistentReference(name);
}

/**
 * @brief Register a new user
 * @param system reference to the system
*/
void SignIn(System& system) {
  std::string username;
  std::string password;
  std::cout << "\n###### Sign in ######\n\n";
  std::cout << "\nUsername: ";
  std::cin >> username;
  if (system.ExistentUser(username) && !system.GetAuthenticatedUser(username)) { 
    do {
      std::cout << "\nPassword: ";
      std::cin >> password;
      if (system.VerifyPassword(username, password)) {
        std::cout << "\nWelcome!" << username << "!\n";
      } else {
        std::cout << "\nPassword is incorrect\n";
      }
    } while(!system.VerifyPassword(username, password));
    system.AddAuthenticatedUser(system.GetUser(username));
    return;
  } else if (system.ExistentUser(username) && system.GetAuthenticatedUser(username)) {
    std::cout << "\nWelcome" << username << "!\n";
  } else {
    std::cout << "\nUser not found\n";
  }
}

/**
 * @brief Unauthenticated user menu
*/
void CurrentUserMenu(System& systema) {
  system("clear");
  int option;
  bool verify_option = true;
  bool sing_in = false;
  while(verify_option || !sing_in) {
    std::cout << "\n###### Library Management ######\n";
    std::cout << "\nChoose one of the following options:\n";
    std::cout << "[0] Exit\n";
    std::cout << "[1] Register\n";
    std::cout << "[2] Sign in\n";
    std::cout << "\nOption: ";
    std::cin >> option;
    if (option < 0 || option > 3) {
      std::cout << "\nInvalid option\n";
    } else {
      switch(option) {
        case 0:
          verify_option = false;
          break;
        case 1:
          system("clear");
          systema.AddUser(NewUser());
          break;
        case 2:
          system("clear");
          SignIn(systema);
          break;
      }
    }
  }
}

/**
 * @brief Authenticated user menu
*/
void PostUserMenu(System& systema, User& user) {
  int option;
  bool verify_option = true;
  while(verify_option) {
    std::cout << "\n###### Library Management ######\n";
    std::cout << "\nChoose one of the following options:\n";
    std::cout << "[0] Exit Sesion\n";
    std::cout << "[1] Search\n";
    std::cout << "[2] Change password\n";
    std::cout << "\nOption: ";
    std::cin >> option;
    if (option < 0 || option > 3) {
      std::cout << "\nInvalid option\n";
    } else {
      switch(option) {
        case 0:
          verify_option = false;
          break;
        case 1:
          system("clear");
          Search(systema);
          break;
        case 2:
          system("clear");
          Password(systema, user);
          break;
      }
    }
  }
}

/**
 * @brief Process the input file
 * @param file_name name of the file to process
*/
void ProcessFileInput(const std::string& file_name, System& system) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Error opening the file\n";
    exit(EXIT_FAILURE);
  }
  std::string line;
  while (std::getline(file, line)) {
    // Process the line: Name, Identifier, Author, Letter (L: lost, D: damaged, B: borrowed, R: reserved, A: available)
    std::string name;
    int identifier;
    std::string author;
    char letter;
    // Extract the name
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ',') {
        name = line.substr(0, i);
        std::transform(name.begin(), name.end(), name.begin(),
                   [](unsigned char c) -> unsigned char { return std::tolower(c); });
        line = line.substr(i + 1);
      }
    }
    // Extract the identifier
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ',') {
        identifier = std::stoi(line.substr(0, i));
        line = line.substr(i + 1);
      }
    }
    // Extract the author
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ',') {
        author = line.substr(0, i);
        std::transform(author.begin(), author.end(), author.begin(),
                   [](unsigned char c) -> unsigned char { return std::tolower(c); });
        line = line.substr(i + 1);
      }
    }
    // Extract the letter
    letter = line[0];
    Book book(name, identifier, author);
    switch(letter) {
      case 'L':
        system.AddBook(book);
        system.AddLostBook(book);
        break;
      case 'D':
        system.AddBook(book);
        system.AddDamagedBook(book);
        break;
      case 'B':
        system.AddBook(book);
        system.AddBorrowedBook(book);
        break;
      case 'R':
        system.AddBook(book);
        system.AddReservedBook(book);
        break;
      case 'A':
        system.AddBook(book);
        system.AddAvailableBook(book);
        break;
    }
  }
  file.close();
}

/**
 * @brief Create a New User 
 */
User NewUser() {
  bool wrong_answer = false;
  /// Asking for username
  std::string username;
  do {
    std::cout << "Write an username: ";
    std::cin >> username;
    if (UsernameExist(username)) {
      std::cout << "That username is alredy in use. Try again" << std::endl;
    }
  } while (UsernameExist(username));
  /// Asking for password
  std::string password;
  do {
    std::cout << "Choose your password: ";
    std::cin >> password;
    if (password.length() < 4) {
      wrong_answer =  true;
      std::cout << "Password must have at least 4 characters. Try again:";
    } else {
      wrong_answer = true;
    }
  } while(wrong_answer);
  /// Searching for an identifier
  std::string line;
  std::string id_str;
  std::ifstream users_file("users.txt");
  while (std::getline(users_file, line)) {
    std::istringstream iss(line);
    iss >> id_str; /// Skipping username
    iss >> id_str;  /// Current ID
  }
  int id = std::stoi(id_str);
  ++id;
  /// Writing the new user in the file
  std::ofstream users_file_out("users.txt", std::ios::app); // Ensure that the users_file object is of type std::ofstream
  users_file_out << username << " " << id << " " << password << std::endl; // Use the users_file_out object for writing to the file
  return User(username, id, password);
}

/**
 * @brief Check if an username already exist
 * @param username is the username to check
 */
bool UsernameExist(const std::string& username) {
  std::string line;
  std::string current_username;
  std::ifstream users_file("users.txt");
  while (std::getline(users_file, line)) {
    std::istringstream iss(line);
    iss >> current_username; /// Skipping username
    if (current_username == username) {
      return true;
    }
  }
  return false;
} 
