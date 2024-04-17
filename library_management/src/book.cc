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

#include "../include/book.h"

// CONSTRUCTORS
Book::Book(const std::string& name, const int& identifier,
           const std::string& author, const BookState& book_state)
    : name_(name),
      identifier_(identifier),
      author_(author),
      book_state_(book_state) {}

// MEMBER FUNCTIONS
/**
 * @brief Function to check if the book is available
 * @return true if the book is available, false otherwise
 */
BookState Book::GetBookState() const { return book_state_; }

/**
 * @brief Function to set the availability of the book
 * @param value value to set
 */
void Book::SetBookState(const BookState& value) { book_state_ = value; }

// GETTERS & SETTERS
/**
 * @brief Function to get the name of the book
 * @return name of the book
 */
std::string Book::GetName() const { return name_; }

/**
 * @brief Function to get the identifier of the book
 * @return identifier of the book
 */
int Book::GetIdentifier() const { return identifier_; }

/**
 * @brief Function to get the author of the book
 * @return author of the book
 */
std::string Book::GetAuthor() const { return author_; }
/**
 * @brief Overload of the operator << to allow the printing of
 * objets of the class Book
 * @param output reference to output stream
 * @param book book to print
 * @return print of the book and reference to the output stream
 */
std::ostream& operator<<(std::ostream& output, const Book& book) {
  output << book.GetName() << "," << book.GetIdentifier() << ","
         << book.GetAuthor() << ",";
  switch (book.GetBookState()) {
  case lost:
    output << "L";
    break;
  case damaged:
    output << "D";
    break;
  case borrowed:
    output << "B";
    break;
  case reserved:
    output << "R";
    break;
  case available:
    output << "A";
    break;
  default:
    std::cerr << "This should never happen" << std::endl;
    break;
  }
  return output;
}