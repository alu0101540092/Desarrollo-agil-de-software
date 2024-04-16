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

/**
 * @brief Constructor of the class System
 * 
 */
System::System() {}

/**
 * @brief Constructor of the class System
 * 
 */
System::System(std::vector<Book> books, std::vector<User> users, std::vector<Book> borrowed_books,
               std::vector<Book> available_books, std::vector<Book> reserved_books,
               std::vector<Book> lost_books, std::vector<Book> damaged_books) {
  books_ = books;
  users_ = users;
  borrowed_books_ = borrowed_books;
  available_books_ = available_books;
  reserved_books_ = reserved_books;
  lost_books_ = lost_books;
  damaged_books_ = damaged_books;
}

/**
 * @brief Function to add a book to the system
 * 
 * @param book 
 */
void System::AddBook(const Book& book) {
  books_.push_back(book);
}

/**
 * @brief Function to add a user to the system
 * 
 * @param user 
 */
void System::AddUser(const User& user) {
  users_.push_back(user);
}

/**
 * @brief Function to add an authenticated user to the system
 * 
 * @param user 
 */
void System::AddAuthenticatedUser(const User& user) {
  authenticated_users_.push_back(user);
}

/**
 * @brief Function to add a borrowed book to the system
 * 
 * @param book 
 */
void System::AddBorrowedBook(const Book& book) {
  borrowed_books_.push_back(book);
}

/**
 * @brief Function to add an available book to the system
 * 
 * @param book 
 */
void System::AddAvailableBook(const Book& book) {
  available_books_.push_back(book);
}

/**
 * @brief Function to add a reserved book to the system
 * 
 * @param book 
 */
void System::AddReservedBook(const Book& book) {
  reserved_books_.push_back(book);
}

/**
 * @brief Function to add a lost book to the system
 * 
 * @param book 
 */
void System::AddLostBook(const Book& book) {
  lost_books_.push_back(book);
}

/**
 * @brief Function to add a damaged book to the system
 * 
 * @param book 
 */
void System::AddDamagedBook(const Book& book) {
  damaged_books_.push_back(book);
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
 * @brief Function to remove a borrowed book from the system
 * 
 * @param book 
 */
void System::RemoveBorrowedBook(const Book& book) {
  for (int i = 0; i < borrowed_books_.size(); i++) {
    if (borrowed_books_[i].GetName() == book.GetName()) {
      borrowed_books_.erase(borrowed_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to remove an available book from the system
 * 
 * @param book 
 */
void System::RemoveAvailableBook(const Book& book) {
  for (int i = 0; i < available_books_.size(); i++) {
    if (available_books_[i].GetName() == book.GetName()) {
      available_books_.erase(available_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to remove a reserved book from the system
 * 
 * @param book 
 */
void System::RemoveReservedBook(const Book& book) {
  for (int i = 0; i < reserved_books_.size(); i++) {
    if (reserved_books_[i].GetName() == book.GetName()) {
      reserved_books_.erase(reserved_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to remove a lost book from the system
 * 
 * @param book 
 */
void System::RemoveLostBook(const Book& book) {
  for (int i = 0; i < lost_books_.size(); i++) {
    if (lost_books_[i].GetName() == book.GetName()) {
      lost_books_.erase(lost_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to remove a damaged book from the system
 * 
 * @param book 
 */
void System::RemoveDamagedBook(const Book& book) {
  for (int i = 0; i < damaged_books_.size(); i++) {
    if (damaged_books_[i].GetName() == book.GetName()) {
      damaged_books_.erase(damaged_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to get the books of the system
 * 
 * @return std::vector<Book> 
 */
std::vector<Book> System::GetBooks() {
  return books_;
}

/**
 * @brief Function to get the users of the system
 * 
 * @return std::vector<User> 
 */
std::vector<User> System::GetUsers() {
  return users_;
}

/**
 * @brief Function to get a user of the system
 * 
 * @param user 
 * @return bool 
 */
User System::GetUser(const std::string& user) {
  for (int i = 0; i < users_.size(); i++) {
    if (users_[i].GetName() == user) {
      return users_[i];
    }
  }
}

/**
 * @brief Function to get an authenticated user of the system
 * 
 * @param user 
 * @return bool 
 */
bool System::GetAuthenticatedUser(const std::string& user) {
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
std::vector<User> System::GetAuthenticatedUsers() {
  return authenticated_users_;
}

/**
 * @brief Function to get the borrowed books of the system
 * 
 * @return std::vector<Book> 
 */
std::vector<Book> System::GetBorrowedBooks() {
  return borrowed_books_;
}

/**
 * @brief Function to get the available books of the system
 * 
 * @return std::vector<Book> 
 */
std::vector<Book> System::GetAvailableBooks() {
  return available_books_;
}

/**
 * @brief Function to get the reserved books of the system
 * 
 * @return std::vector<Book> 
 */
std::vector<Book> System::GetReservedBooks() {
  return reserved_books_;
}

/**
 * @brief Function to get the lost books of the system
 * 
 * @return std::vector<Book> 
 */
std::vector<Book> System::GetLostBooks() {
  return lost_books_;
}

/**
 * @brief Function to get the damaged books of the system
 * 
 * @return std::vector<Book> 
 */
std::vector<Book> System::GetDamagedBooks() {
  return damaged_books_;
}

/**
 * @brief Function to borrow a book
 * 
 * @param book 
 * @param user 
 */
void System::BorrowBook(const Book& book, const User& user) {
  borrowed_books_.push_back(book);
  for (int i = 0; i < available_books_.size(); i++) {
    if (available_books_[i].GetName() == book.GetName()) {
      available_books_.erase(available_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to return a book
 * 
 * @param book 
 */
void System::ReturnBook(const Book& book) {
  available_books_.push_back(book);
  for (int i = 0; i < borrowed_books_.size(); i++) {
    if (borrowed_books_[i].GetName() == book.GetName()) {
      borrowed_books_.erase(borrowed_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to reserve a book
 * 
 * @param book 
 * @param user 
 */
void System::ReserveBook(const Book& book, const User& user) {
  reserved_books_.push_back(book);
  for (int i = 0; i < available_books_.size(); i++) {
    if (available_books_[i].GetName() == book.GetName()) {
      available_books_.erase(available_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to cancel a reservation
 * 
 * @param book 
 */
void System::CancelReservation(const Book& book) {
  available_books_.push_back(book);
  for (int i = 0; i < reserved_books_.size(); i++) {
    if (reserved_books_[i].GetName() == book.GetName()) {
      reserved_books_.erase(reserved_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to report a lost book
 * 
 * @param book 
 */
void System::ReportLostBook(const Book& book) {
  lost_books_.push_back(book);
  for (int i = 0; i < borrowed_books_.size(); i++) {
    if (borrowed_books_[i].GetName() == book.GetName()) {
      borrowed_books_.erase(borrowed_books_.begin() + i);
    }
  }
}

/**
 * @brief Function to report a damaged book
 * 
 * @param book 
 */
void System::ReportDamagedBook(const Book& book) {
  damaged_books_.push_back(book);
  for (int i = 0; i < borrowed_books_.size(); i++) {
    if (borrowed_books_[i].GetName() == book.GetName()) {
      borrowed_books_.erase(borrowed_books_.begin() + i);
    }
  }
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
bool System::VerifyPassword(const std::string& user, const std::string& password) {
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
 * @return true 
 * @return false 
 */
void System::ExistentReference(const std::string& book) {
  if (book == "") {
    return;
  }

  std::istringstream iss(book);
  std::string word;
  std::vector<Book> books;

  while (iss >> word) {
    /// Search by name
    for (int i = 0; i < books_.size(); i++) {
      std::istringstream iss1(books_[i].GetName());
      std::string word1;
      while (iss1 >> word1) {
        if (word == word1) {
          books.push_back(books_[i]);
        }
      }
    }
    /// Search by author
    for (int i = 0; i < books_.size(); i++) {
      std::istringstream iss2(books_[i].GetAuthor());
      std::string word2;
      while (iss2 >> word2) {
        if (word == word2) {
          books.push_back(books_[i]);
        }
      }
    }
  }
  
  /// Print occurrences
  if (books.size() == 0) {
    std::cout << "\nBook not found\n";
  } else {
    if (books.size() == 1) {
      std::cout << "\nBook found\n";
      std::cout << books[0] << std::endl;
    } else {
      std::cout << "\nBooks found\n";
      for (int i = 0; i < books.size(); i++) {
        std::cout << "Book number: " << i+1 << books[i] << std::endl;
      }
    }
  }
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
    std::cout << "Book nº: " << i+1 << books_[i] << std::endl;
  }
}

/**
 * @brief Function to print the users of the system
 * 
 */
void System::PrintUsers() {
  for (int i = 0; i < users_.size(); i++) {
    std::cout << "User nº: " << i+1 << users_[i] << std::endl;
  }
}

/**
 * @brief Function to print the borrowed books of the system
 * 
 */
void System::PrintBorrowedBooks() {
  for (int i = 0; i < borrowed_books_.size(); i++) {
    std::cout << "Borrowed book nº: " << i+1 << borrowed_books_[i] << std::endl;
  }
}

/**
 * @brief Function to print the available books of the system
 * 
 */
void System::PrintAvailableBooks() {
  for (int i = 0; i < available_books_.size(); i++) {
    std::cout << "Available book nº: " << i+1 << available_books_[i] << std::endl;
  }
}

/**
 * @brief Function to print the reserved books of the system
 * 
 */
void System::PrintReservedBooks() {
  for (int i = 0; i < reserved_books_.size(); i++) {
    std::cout << "Reserved book nº: " << i+1 << reserved_books_[i] << std::endl;
  }
}

/**
 * @brief Function to print the lost books of the system
 * 
 */
void System::PrintLostBooks() {
  for (int i = 0; i < lost_books_.size(); i++) {
    std::cout << "Lost book nº: " << i+1 << lost_books_[i] << std::endl;
  }
}

/**
 * @brief Function to print the damaged books of the system
 * 
 */
void System::PrintDamagedBooks() {
  for (int i = 0; i < damaged_books_.size(); i++) {
    std::cout << "Damaged book nº: " << i+1 << damaged_books_[i] << std::endl;
  }
}