/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Declarations of the System class
 * @bug
 * @see
*/

#include <vector>
#include <sstream>
#include "book.h"
#include "user.h"

#pragma once

/**
 * @brief Represents a library system
 */
class System {
 public:
  /// CONSTRUCTORS
  System();
  System(std::vector<Book> books, std::vector<User> users, std::vector<Book> borrowed_books,
         std::vector<Book> available_books, std::vector<Book> reserved_books,
         std::vector<Book> lost_books, std::vector<Book> damaged_books);
  
  /// MEMBER FUNCTIONS
  void AddBook(const Book& book);
  void AddUser(const User& user);
  void AddAuthenticatedUser(const User& user);
  void AddBorrowedBook(const Book& book);
  void AddAvailableBook(const Book& book);
  void AddReservedBook(const Book& book);
  void AddLostBook(const Book& book);
  void AddDamagedBook(const Book& book);

  void RemoveBook(const Book& book);
  void RemoveUser(const User& user);
  void RemoveAuthenticatedUser(const User& user);
  void RemoveBorrowedBook(const Book& book);
  void RemoveAvailableBook(const Book& book);
  void RemoveReservedBook(const Book& book);
  void RemoveLostBook(const Book& book);
  void RemoveDamagedBook(const Book& book);

  void BorrowBook(const Book& book, const User& user);
  void ReturnBook(const Book& book);
  void ReserveBook(const Book& book, const User& user);
  void CancelReservation(const Book& book);
  void ReportLostBook(const Book& book);
  void ReportDamagedBook(const Book& book);

  bool ExistentUser(const std::string& user);
  bool VerifyPassword(const std::string& user, const std::string& password);
  void ExistentReference(const std::string& book);
  void ChangePassword(User& user, const std::string& password);
  
  /// GETTERS && SETTERS
  std::vector<Book> GetBooks();
  std::vector<User> GetUsers();
  User GetUser(const std::string& user);
  bool GetAuthenticatedUser(const std::string& user);
  std::vector<User> GetAuthenticatedUsers();
  std::vector<Book> GetBorrowedBooks();
  std::vector<Book> GetAvailableBooks();
  std::vector<Book> GetReservedBooks();
  std::vector<Book> GetLostBooks();
  std::vector<Book> GetDamagedBooks();

  /// PRINTERS
  void PrintBooks();
  void PrintUsers();
  void PrintBorrowedBooks();
  void PrintAvailableBooks();
  void PrintReservedBooks();
  void PrintLostBooks();
  void PrintDamagedBooks();
  
 private:
  static std::vector<Book> books_;
  static std::vector<User> users_;
  static std::vector<User> authenticated_users_;
  static std::vector<Book> borrowed_books_;
  static std::vector<Book> available_books_;
  static std::vector<Book> reserved_books_;
  static std::vector<Book> lost_books_;
  static std::vector<Book> damaged_books_;
};