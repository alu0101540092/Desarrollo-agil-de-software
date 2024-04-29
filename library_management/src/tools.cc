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
        std::cout << "\nNew password (must be longer than 3 characters and "
                     "different to the old one): ";
        std::cin >> new_password;
      } while ((new_password == user.GetPassword()) ||
               (new_password.size() < 4));
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
  std::cout << "\nWhat are you looking for?: ";
  // To remove the posible newline characters remaining in stream
  std::cin.ignore();
  getline(std::cin, name);
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
User* SignIn(System& systema) {
  std::string username;
  std::string password;
  std::cout << "\n###### Sign in ######\n\n";
  std::cout << "\nUsername: ";
  std::cin >> username;
  if (systema.ExistentUser(username) &&
      !systema.GetAuthenticatedUser(username)) {
    do {
      std::cout << "\nPassword: ";
      std::cin >> password;
      if (systema.VerifyPassword(username, password)) {
        system("clear");
        std::cout << "\nWelcome " << username << "!\n";
      } else {
        std::cout << "\nPassword is incorrect\n";
      }
    } while (!systema.VerifyPassword(username, password));
    systema.AddAuthenticatedUser(systema.GetUser(username));
    return &systema.GetUser(username);
  } else if (systema.ExistentUser(username) &&
             systema.GetAuthenticatedUser(username)) {
    system("clear");
    std::cout << "\nWelcome " << username << "!\n";
    return &systema.GetUser(username);
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
  while (true) {
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
    PostUserMenu(systema, *sign_in_result);
    not_authenticated = true;
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
    std::cout << "[4] Return book\n";
    std::cout << "[5] Reserve book\n";
    std::cout << "[6] Cancel reservation of book\n";
    std::cout << "\nOption: ";
    std::cin >> option;
    if (option < 0 || option > 7) {
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
              std::cout << "Book number  " << i + 1 << ": " << *results[i]
                        << std::endl;
            }
          }
        }
        break;
      }
      case 2:
        system("clear");
        Password(systema, user);
        break;
      case 3: {
        system("clear");
        std::vector<Book*> available_books;
        for (const auto& element : Search(systema)) {
          if (element->GetBookState() == available) {
            available_books.emplace_back(element);
          }
        }
        /// Print occurrences
        if (available_books.size() == 0) {
          std::cout << "\nBook not found\n";
        } else {
          if (available_books.size() == 1) {
            std::cout << "\nBook found\n";
            std::cout << *available_books[0] << std::endl;
          } else {
            std::cout << "\nBooks found\n";
            for (int i = 0; i < available_books.size(); i++) {
              std::cout << "Book number: " << i + 1 << *available_books[i]
                        << std::endl;
            }
          }
          int book_to_borrow{-1};
          while (0 > book_to_borrow ||
                 book_to_borrow >= available_books.size()) {
            std::cout << "Enter the number of the book you want to borrow, "
                         "starting from 0: ";
            std::cin >> book_to_borrow;
          }
          systema.BorrowBook(*available_books[book_to_borrow], user);
        }
        break;
      }
      case 4: {
        system("clear");
        std::vector<Book*> borrowed_books;
        for (const auto& element : Search(systema)) {
          if (element->GetBookState() == borrowed) {
            borrowed_books.emplace_back(element);
          }
        }
        /// Print occurrences
        if (borrowed_books.size() == 0) {
          std::cout << "\nBook not found\n";
        } else {
          if (borrowed_books.size() == 1) {
            std::cout << "\nBook found\n";
            std::cout << *borrowed_books[0] << std::endl;
          } else {
            std::cout << "\nBooks found\n";
            for (int i = 0; i < borrowed_books.size(); i++) {
              std::cout << "Book number: " << i + 1 << *borrowed_books[i]
                        << std::endl;
            }
          }
          int book_to_return{-1};
          while (0 > book_to_return ||
                 book_to_return >= borrowed_books.size()) {
            std::cout << "Enter the number of the book you want to return, "
                         "starting from 0: ";
            std::cin >> book_to_return;
          }
          systema.ReturnBook(*borrowed_books[book_to_return], user);
        }
        break;
      }
      case 5: {
        system("clear");
        std::vector<Book*> available_books;
        for (const auto& element : Search(systema)) {
          if (element->GetBookState() == available) {
            available_books.emplace_back(element);
          }
        }
        /// Print occurrences
        if (available_books.size() == 0) {
          std::cout << "\nBook not found\n";
        } else {
          if (available_books.size() == 1) {
            std::cout << "\nBook found\n";
            std::cout << *available_books[0] << std::endl;
          } else {
            std::cout << "\nBooks found\n";
            for (int i = 0; i < available_books.size(); i++) {
              std::cout << "Book number: " << i + 1 << *available_books[i]
                        << std::endl;
            }
          }
          int book_to_reserve{-1};
          while (0 > book_to_reserve ||
                 book_to_reserve >= available_books.size()) {
            std::cout << "Enter the number of the book you want to reserve, "
                         "starting from 0: ";
            std::cin >> book_to_reserve;
          }
          systema.ReserveBook(*available_books[book_to_reserve], user);
        }
        break;
      }
      case 6: {
        system("clear");
        std::vector<Book*> reserved_books;
        for (const auto& element : Search(systema)) {
          if (element->GetBookState() == reserved) {
            reserved_books.emplace_back(element);
          }
        }
        /// Print occurrences
        if (reserved_books.size() == 0) {
          std::cout << "\nBook not found\n";
        } else {
          if (reserved_books.size() == 1) {
            std::cout << "\nBook found\n";
            std::cout << *reserved_books[0] << std::endl;
          } else {
            std::cout << "\nBooks found\n";
            for (int i = 0; i < reserved_books.size(); i++) {
              std::cout << "Book number: " << i + 1 << *reserved_books[i]
                        << std::endl;
            }
          }
          int book_to_cancel_reservation{-1};
          while (0 > book_to_cancel_reservation ||
                 book_to_cancel_reservation >= reserved_books.size()) {
            std::cout << "Enter the number of the book you want to cancel the "
                         "reserve of, starting from 0: ";
            std::cin >> book_to_cancel_reservation;
          }
          systema.CancelReservation(*reserved_books[book_to_cancel_reservation],
                                    user);
        }
        break;
      }
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
    if (letter == 'R' || letter == 'B') {
      line = line.substr(2);
    }
    User owner_of_book{};
    BookState state;
    switch (letter) {
    case 'L':
      state = BookState::lost;
      break;
    case 'D':
      state = BookState::damaged;
      break;
    case 'B': {
      state = BookState::borrowed;
      // Process the line: Name Identifier Password
      std::string name;
      std::string identifier;
      // Extract the name, identifier and password
      std::stringstream user_data{line};
      user_data >> name >> identifier;
      owner_of_book = User(name, std::stoi(identifier), std::string());
      break;
    }
    case 'R': {
      state = BookState::reserved;
      // Process the line: Name Identifier Password
      std::string name;
      std::string identifier;
      std::string password;
      // Extract the name, identifier and password
      std::stringstream user_data{line};
      user_data >> name >> identifier;
      owner_of_book = User(name, std::stoi(identifier), std::string());
      break;
    }
    case 'A':
      state = BookState::available;
      break;
    }
    Book book(name, identifier, author, state);
    if (letter == 'R' || letter == 'B') {
      book.SetOwner(owner_of_book);
    }
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
    output << user << " " << user.GetPassword() << "\n";
  }
}

/**
 * @brief Saves all the books data into a file
 * @param file_name name of the file to save the data
 * @param system reference to system object
 */
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
