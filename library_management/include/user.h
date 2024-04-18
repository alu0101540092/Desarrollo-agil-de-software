/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Declarations of the User class
 * @bug
 * @see
 */

#include <iostream>
#include <string>
#include <vector>

#pragma once

/**
 * @brief Represents a user of a library
 */
class User {
public:
  /// CONSTRUCTORS
  User();
  User(const std::string& name, const int indentifier,
       const std::string& password);
  /// MEMBER FUNCTIONS
  bool IsAuthenticated() const;
  bool Login(const std::string& password);

  /// GETTERS & SETTERS
  std::string GetName() const;
  int GetIdentifier() const;
  std::string GetPassword() const;
  void SetPassword(const std::string& password);

private:
  std::string name_;
  std::string password_;
  int identifier_;
  bool is_authenticated_;
};
std::ostream& operator<<(std::ostream& output, const User& user);
bool operator==(const User& user_1, const User& user_2);
bool operator!=(const User& user_1, const User& user_2);
