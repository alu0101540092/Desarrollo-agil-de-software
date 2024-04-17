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
    std::cout << "\nOld password: ";
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
 * @return vector of pointers pointing to books found
 */
std::vector<Book*> Search(System& system) {
  std::string name;
  std::cout << "\n###### Search ######\n\n";
  std::cout << "\nWhat are you looking for?: " << std::endl;
  std::cin >> name;
  std::transform(
      name.begin(), name.end(), name.begin(),
      [](unsigned char c) -> unsigned char { return std::tolower(c); });
  return system.ExistentReference(name);
}

/**
 * @brief Register a new user
 * @param system reference to the system
 * @return reference to user registered or nullopt if no user was found
 */
User* SignIn(System& system) {
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
        std::cout << "\nWelcome! " << username << "!\n";
      } else {
        std::cout << "\nPassword is incorrect\n";
      }
    } while (!system.VerifyPassword(username, password));
    system.AddAuthenticatedUser(system.GetUser(username));
    return &system.GetUser(username);
  } else if (system.ExistentUser(username) &&
             system.GetAuthenticatedUser(username)) {
    std::cout << "\nWelcome " << username << "!\n";
    return &system.GetUser(username);
  } else {
    std::cout << "\nUser not found\n";
    return nullptr;
  }
}

/**
 * @brief Initial system menu
 * @param systema reference to system object
 */
void UserMenu(System& systema) {
  system("clear");
  int option;
  bool not_authenticated = true;
  User* sign_in_result{};
  bool continue_loop{true};
  while (continue_loop) {
    while (not_authenticated) {
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
        switch (option) {
        case 0:
          return;
        case 1:
          system("clear");
          systema.AddUser(NewUser());
          break;
        case 2:
          system("clear");
          sign_in_result = SignIn(systema);
          if (sign_in_result != nullptr) {
            not_authenticated = false;
          }
          break;
        }
      }
    }
    continue_loop = PostUserMenu(systema, *sign_in_result);
  }
}

/**
 * @brief Authenticated user menu
 * @return true if user wants to continue, false if he wants to exit
 */
bool PostUserMenu(System& systema, User& user) {
  int option;
  bool continue_flag = true;
  while (continue_flag) {
    std::cout << "\n###### Library Management ######\n";
    std::cout << "\nChoose one of the following options:\n";
    std::cout << "[0] Exit Sesion\n";
    std::cout << "[1] Search for a book\n";
    std::cout << "[2] Change password\n";
    std::cout << "[3] Borrow book\n";
    std::cout << "\nOption: ";
    std::cin >> option;
    if (option < 0 || option > 3) {
      std::cout << "\nInvalid option\n";
    } else {
      switch (option) {
      case 0:
        return false;
      case 1: {
        system("clear");
        std::vector<Book*> results{Search(systema)};
        /// Print occurrences
        if (results.size() == 0) {
          std::cout << "\nBook not found\n";
        } else {
          if (results.size() == 1) {
            std::cout << "\nBook found\n";
            std::cout << *results[0] << std::endl;
          } else {
            std::cout << "\nBooks found\n";
            for (int i = 0; i < results.size(); i++) {
              std::cout << "Book number: " << i + 1 << *results[i] << std::endl;
            }
          }
        }
        break;
      }
      case 2:
        system("clear");
        Password(systema, user);
        break;
      case 3:
        system("clear");
        std::vector<Book*> results{Search(systema)};
        /// Print occurrences
        if (results.size() == 0) {
          std::cout << "\nBook not found\n";
        } else {
          if (results.size() == 1) {
            std::cout << "\nBook found\n";
            std::cout << *results[0] << std::endl;
          } else {
            std::cout << "\nBooks found\n";
            for (int i = 0; i < results.size(); i++) {
              std::cout << "Book number: " << i + 1 << *results[i] << std::endl;
            }
          }
        }
        int book_to_borrow{-1};
        while (0 > book_to_borrow || book_to_borrow >= results.size()) {
          std::cin >> book_to_borrow;
        }
        systema.BorrowBook(*results[book_to_borrow]);
        break;
      }
    }
  }
  return true;
}

/**
 * @brief Process the input file
 * @param file_name name of the file to process
 */
void ProcessBookFileInput(const std::string& file_name, System& system) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Error opening the file\n";
    exit(EXIT_FAILURE);
  }
  std::string line;
  while (std::getline(file, line)) {
    // Process the line: Name, Identifier, Author, Letter (L: lost, D: damaged,
    // B: borrowed, R: reserved, A: available)
    std::string name;
    int identifier;
    std::string author;
    char letter;
    // Extract the name
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ',') {
        name = line.substr(0, i);
        std::transform(
            name.begin(), name.end(), name.begin(),
            [](unsigned char c) -> unsigned char { return std::tolower(c); });
        line = line.substr(i + 1);
        break;
      }
    }
    // Extract the identifier
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ',') {
        identifier = std::stoi(line.substr(0, i));
        line = line.substr(i + 1);
        break;
      }
    }
    // Extract the author
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ',') {
        author = line.substr(0, i);
        std::transform(
            author.begin(), author.end(), author.begin(),
            [](unsigned char c) -> unsigned char { return std::tolower(c); });
        line = line.substr(i + 1);
        break;
      }
    }
    // Extract the letter
    letter = line[0];
    BookState state;
    switch (letter) {
    case 'L':
      state = BookState::lost;
      break;
    case 'D':
      state = BookState::damaged;
      break;
    case 'B':
      state = BookState::borrowed;
      break;
    case 'R':
      state = BookState::reserved;
      break;
    case 'A':
      state = BookState::available;
      break;
    }
    Book book(name, identifier, author, state);
    system.AddBook(book);
  }
  file.close();
}
/**
 * @brief Process the input file
 * @param file_name name of the file to process
 */
void ProcessUserFileInput(const std::string& file_name, System& system) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Error opening the file\n";
    exit(EXIT_FAILURE);
  }
  std::string line;
  while (std::getline(file, line)) {
    // Process the line: Name Identifier Password
    std::string name;
    std::string identifier;
    std::string password;
    // Extract the name, identifier and password
    std::stringstream user_data{line};
    user_data >> name >> identifier >> password;
    User user_to_add{name, std::stoi(identifier), password};
    system.AddUser(user_to_add);
  }
  file.close();
}
/**
 * @brief Saves all the users data into a file
 * @param file_name name of the file to save the data
 * @param system reference to system object
 */
void WriteUsersData(const std::string& filename, const System& system) {
  std::ofstream output(filename);
  if (!output) {
    std::cerr << "Unable to open file: " << filename << "\n";
    return;
  }
  for (const auto& user : system.GetUsers()) {
    output << user << "\n";
  }
}
void WriteBooksData(const std::string& filename, const System& system) {
  std::ofstream output(filename);
  if (!output) {
    std::cerr << "Unable to open file: " << filename << "\n";
    return;
  }
  for (const auto& book : system.GetBooks()) {
    output << book << "\n";
  }
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
      wrong_answer = true;
      std::cout << "Password must have at least 4 characters. Try again:"
                << std::endl;
    } else {
      wrong_answer = false;
    }
  } while (wrong_answer);
  /// Searching for an identifier
  std::string line;
  std::string id_str;
  std::ifstream users_file("users.txt");
  while (std::getline(users_file, line)) {
    std::istringstream iss(line);
    iss >> id_str;  /// Skipping username
    iss >> id_str;  /// Current ID
  }
  int id = std::stoi(id_str);
  ++id;
  /// Writing the new user in the file
  std::ofstream users_file_out(
      "users.txt", std::ios::app);  // Ensure that the users_file object is of
                                    // type std::ofstream
  users_file_out
      << username << " " << id << " " << password
      << std::endl;  // Use the users_file_out object for writing to the file
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
    iss >> current_username;  /// Skipping username
    if (current_username == username) {
      return true;
    }
  }
  return false;
}
