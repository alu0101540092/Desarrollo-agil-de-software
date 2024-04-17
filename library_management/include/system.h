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

  void RemoveBook(const Book& book);
  void RemoveUser(const User& user);
  void RemoveAuthenticatedUser(const User& user);

  void BorrowBook(Book& book);
  void ReturnBook(Book& book);
  void ReserveBook(Book& book);
  void CancelReservation(Book& book);
  void ReportLostBook(Book& book);
  void ReportDamagedBook(Book& book);

  bool ExistentUser(const std::string& user);
  bool VerifyPassword(const std::string& user, const std::string& password);
  std::vector<Book*> ExistentReference(const std::string& book);
  void ChangePassword(User& user, const std::string& password);
  
  /// GETTERS && SETTERS
  std::vector<Book> GetBooks() const;
  std::vector<User> GetUsers() const;
  User& GetUser(const std::string& user) const;
  bool GetAuthenticatedUser(const std::string& user) const;
  std::vector<User> GetAuthenticatedUsers() const;

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
  
};