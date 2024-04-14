/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author Samuel Rodríguez alu0101545714@ull.edu.es
 * @date 14/04/2024
 * @brief Definitons of the Book class
 * @bug
 * @see
*/

#include "../include/book.h"

/**
 * @brief Overload of the operator << to allow the printing of
 * objets of the class Book
 * @param output reference to output stream
 * @param book book to print
 * @return print of the book and reference to the output stream
 */
std::ostream& operator<<(std::ostream& output, const Book& book) {
  output << book.GetName() << " with identifier " << book.GetIdentifier();
  return output;
}