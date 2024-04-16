/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Declarations of the Loan class
 * @bug
 * @see
*/

#include <chrono>
#include <iostream>
#include "book.h"

#pragma once

/**
 * @brief Represents a loan of a book
 */
class Loan {
 public:
  /// CONSTRUCTORS
  Loan(const Book& book_borrowed);

  /// MEMBER FUNCTIONS
  bool IsReturned() const;
  void SetAsReturned();
  bool TimeLimitExceeded() const;

  /// GETTERS & SETTERS
  const Book& GetBookBorrowed() const;

 private:
  const Book& book_borrowed_;
  std::chrono::system_clock::time_point loan_time_;
  bool returned_;
};

std::ostream& operator<<(std::ostream& output, const Loan& loan);