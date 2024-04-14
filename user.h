/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author Samuel Rodríguez alu0101545714@ull.edu.es
 * @date 14/04/2024
 * @brief Declarations of the User class
 * @bug
 * @see
 */
#ifndef USER_H_
#define USER_H_
#include <iostream>
#include <string>
#include <vector>

#include "loan.h"
class Loan;
class Catalog;
/**
 * @brief Represents a user of a library
 */
class User {
public:
  User(const std::string& name, const int indentifier,
       const std::string& password)
      : name_(name),
        password_(password),
        identifier_(indentifier),
        is_authenticated_(false){};
  bool IsAuthenticated() const { return is_authenticated_; };
  bool Login(const std::string& users_data);
  bool BorrowBook(const Catalog& catalog, const std::string& book_name);
  bool ReturnBook(const Catalog& catalog, const std::string& book_name);
  std::string GetName() const { return name_; };
  int GetIdentifier() const { return identifier_; };

private:
  std::string name_;
  std::string password_;
  int identifier_;
  bool is_authenticated_;
  std::vector<Loan> borrowed_books_list_;
};
std::ostream& operator<<(std::ostream& output, const User& user);

#endif  // USER_H_
