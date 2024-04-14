/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author Samuel Rodríguez alu0101545714@ull.edu.es
 * @date 14/04/2024
 * @brief Declarations of the Book class
 * @bug
 * @see
*/

#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string>

#include "loan.h"

class Author;

/**
 * @brief Represents a book of a library
 */
class Book {
  public:
    Book(const std::string& name, const int identifier, const Author& author)
        : name_(name),
          identifier_(identifier),
          is_available_(true),
          author_(author){};
    bool IsAvailable() const { return is_available_; };
    void SetAvailability(const bool value) { is_available_ = value; };
    std::string GetName() const { return name_; };
    int GetIdentifier() const { return identifier_; };

  private:
    std::string name_;
    int identifier_;
    bool is_available_;
    const Author& author_;
};

std::ostream& operator<<(std::ostream& output, const Book& book);

#endif  // BOOK_H_