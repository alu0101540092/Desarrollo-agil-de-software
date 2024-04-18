/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Definitons of the Book class
 * @bug
 * @see
 */

#include "../include/system.h"

/// Declarations of static members of System class
std::vector<Book> System::books_;
std::vector<User> System::users_;
std::vector<User> System::authenticated_users_;

/**
 * @brief Constructor of the class System
 *
 */
System::System() {}

/**
 * @brief Constructor of the class System
 *
 */
System::System(std::vector<Book> books, std::vector<User> users,
               std::vector<Book> borrowed_books,
               std::vector<Book> available_books,
               std::vector<Book> reserved_books, std::vector<Book> lost_books,
               std::vector<Book> damaged_books) {
  books_ = books;
  users_ = users;
}

/**
 * @brief Function to add a book to the system
 *
 * @param book
 */
void System::AddBook(const Book& book) { books_.push_back(book); }

/**
 * @brief Function to add a user to the system
 *
 * @param user
 */
void System::AddUser(const User& user) { users_.push_back(user); }

/**
 * @brief Function to add an authenticated user to the system
 *
 * @param user
 */
void System::AddAuthenticatedUser(const User& user) {
  authenticated_users_.push_back(user);
}

/**
 * @brief Function to remove a book from the system
 *
 * @param book
 */
void System::RemoveBook(const Book& book) {
  for (int i = 0; i < books_.size(); i++) {
    if (books_[i].GetName() == book.GetName()) {
      books_.erase(books_.begin() + i);
    }
  }
}

/**
 * @brief Function to remove a user from the system
 *
 * @param user
 */
void System::RemoveUser(const User& user) {
  for (int i = 0; i < users_.size(); i++) {
    if (users_[i].GetName() == user.GetName()) {
      users_.erase(users_.begin() + i);
    }
  }
}

/**
 * @brief Function to remove an authenticated user from the system
 *
 * @param user
 */
void System::RemoveAuthenticatedUser(const User& user) {
  for (int i = 0; i < authenticated_users_.size(); i++) {
    if (authenticated_users_[i].GetName() == user.GetName()) {
      authenticated_users_.erase(authenticated_users_.begin() + i);
    }
  }
}

/**
 * @brief Function to get the books of the system
 *
 * @return std::vector<Book>
 */
std::vector<Book> System::GetBooks() const { return books_; }

/**
 * @brief Function to get the users of the system
 *
 * @return std::vector<User>
 */
std::vector<User> System::GetUsers() const { return users_; }

/**
 * @brief Function to get a user of the system
 *
 * @param user
 * @return reference of user
 */
User& System::GetUser(const std::string& user) const {
  for (int i = 0; i < users_.size(); i++) {
    if (users_[i].GetName() == user) {
      return users_[i];
    }
  }
  std::cerr << "Error: user not found" << std::endl;
  exit(EXIT_FAILURE);
  return users_[0];
}

/**
 * @brief Function to get an authenticated user of the system
 *
 * @param user
 * @return bool
 */
bool System::GetAuthenticatedUser(const std::string& user) const {
  for (int i = 0; i < authenticated_users_.size(); i++) {
    if (authenticated_users_[i].GetName() == user) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Function to get the authenticated users of the system
 *
 * @return std::vector<User>
 */
std::vector<User> System::GetAuthenticatedUsers() const {
  return authenticated_users_;
}
/**
 * @brief Function to borrow a book
 *
 * @param book
 * @param user
 */
void System::BorrowBook(Book& book, const User& user) {
  book.SetBookState(BookState::borrowed);
  book.SetOwner(user);
}

/**
 * @brief Function to return a book
 *
 * @param book
 */
void System::ReturnBook(Book& book, const User& user) {
  if (user != book.GetOwner()) {
    std::cerr << "Error: you do not have permission to return this book"
              << std::endl;
    return;
  }
  book.SetBookState(BookState::available);
}

/**
 * @brief Function to reserve a book
 *
 * @param book
 * @param user
 */
void System::ReserveBook(Book& book, const User& user) {
  book.SetBookState(BookState::reserved);
  book.SetOwner(user);
}

/**
 * @brief Function to cancel a reservation
 *
 * @param book
 */
void System::CancelReservation(Book& book, const User& user) {
  book.SetBookState(BookState::available);
  if (user != book.GetOwner()) {
    std::cerr << "Error: you do not have permission to cancel the reservation"
              << std::endl;
    return;
  }
  book.SetBookState(BookState::available);
}

/**
 * @brief Function to report a lost book
 *
 * @param book
 */
void System::ReportLostBook(Book& book) { book.SetBookState(BookState::lost); }

/**
 * @brief Function to report a damaged book
 *
 * @param book
 */
void System::ReportDamagedBook(Book& book) {
  book.SetBookState(BookState::damaged);
}

/**
 * @brief Function to check if a user exists in the system
 *
 * @param user
 */
bool System::ExistentUser(const std::string& user) {
  for (int i = 0; i < users_.size(); i++) {
    if (users_[i].GetName() == user) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Function to verify the password of a user
 *
 * @param user
 * @param password
 * @return true
 * @return false
 */
bool System::VerifyPassword(const std::string& user,
                            const std::string& password) {
  for (int i = 0; i < users_.size(); i++) {
    if (users_[i].GetName() == user) {
      return users_[i].Login(password);
    }
  }
  return false;
}

/**
 * @brief Function to check if a book exists in the system
 *
 * @param book
 * @return vector of pointers to book objects found
 */
std::vector<Book*> System::ExistentReference(const std::string& book) {
  std::vector<Book*> books;
  if (book == "") {
    return books;
  }
  std::istringstream iss(book);
  std::string word;

  while (iss >> word) {
    /// Search by name
    for (int i = 0; i < books_.size(); i++) {
      std::istringstream iss1(books_[i].GetName());
      std::string word1;
      while (iss1 >> word1) {
        if (word == word1) {
          books.push_back(&books_[i]);
        }
      }
    }
    /// Search by author
    for (int i = 0; i < books_.size(); i++) {
      std::istringstream iss2(books_[i].GetAuthor());
      std::string word2;
      while (iss2 >> word2) {
        if (word == word2) {
          books.push_back(&books_[i]);
        }
      }
    }
  }
  return books;
}

/**
 * @brief Function to change the password of a user
 *
 * @param user
 * @param password
 */
void System::ChangePassword(User& user, const std::string& password) {
  user.SetPassword(password);
}

/**
 * @brief Function to print the books of the system
 *
 */
void System::PrintBooks() {
  for (int i = 0; i < books_.size(); i++) {
    std::cout << "Book nº: " << i + 1 << books_[i] << std::endl;
  }
}

/**
 * @brief Function to print the users of the system
 *
 */
void System::PrintUsers() {
  for (int i = 0; i < users_.size(); i++) {
    std::cout << "User nº: " << i + 1 << users_[i] << std::endl;
  }
}

/**
 * @brief Function to print the borrowed books of the system
 *
 */
void System::PrintBorrowedBooks() {
  for (int i = 0; i < books_.size(); i++) {
    if (books_[i].GetBookState() == BookState::borrowed) {
      std::cout << "Borrowed book nº: " << i + 1 << books_[i] << std::endl;
    }
  }
}

/**
 * @brief Function to print the available books of the system
 *
 */
void System::PrintAvailableBooks() {
  for (int i = 0; i < books_.size(); i++) {
    if (books_[i].GetBookState() == BookState::available) {
      std::cout << "Available book nº: " << i + 1 << books_[i] << std::endl;
    }
  }
}

/**
 * @brief Function to print the reserved books of the system
 *
 */
void System::PrintReservedBooks() {
  for (int i = 0; i < books_.size(); i++) {
    if (books_[i].GetBookState() == BookState::reserved) {
      std::cout << "Reserved book nº: " << i + 1 << books_[i] << std::endl;
    }
  }
}

/**
 * @brief Function to print the lost books of the system
 *
 */
void System::PrintLostBooks() {
  for (int i = 0; i < books_.size(); i++) {
    if (books_[i].GetBookState() == BookState::lost) {
      std::cout << "Lost book nº: " << i + 1 << books_[i] << std::endl;
    }
  }
}

/**
 * @brief Function to print the damaged books of the system
 *
 */
void System::PrintDamagedBooks() {
  for (int i = 0; i < books_.size(); i++) {
    if (books_[i].GetBookState() == BookState::damaged) {
      std::cout << "Damaged book nº: " << i + 1 << books_[i] << std::endl;
    }
  }
}