/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Declarations of the Book class
 * @bug
 * @see
 */

#include <iostream>
#include <string>

#include "user.h"
#pragma once

/**
 * @brief Enum to represent the state of a book
 */
enum BookState { lost, available, borrowed, reserved, damaged };

/**
 * @brief Represents a book of a library
 */
class Book {
public:
  /// CONSTRUCTORS
  Book(const std::string& name, const int& identifier,
       const std::string& author, const BookState& book_state);
  /// MEMBER FUNCTIONS
  BookState GetBookState() const;

  /// GETTERS & SETTERS
  std::string GetName() const;
  int GetIdentifier() const;
  std::string GetAuthor() const;
  User GetOwner() const;
  void SetBookState(const BookState& state);
  void SetOwner(const User& owner);

private:
  std::string name_;
  int identifier_;
  BookState book_state_;
  std::string author_;
  User owner_;
};

std::ostream& operator<<(std::ostream& output, const Book& book);