/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Definitons of the Loan class
 * @bug
 * @see
*/

#include "../include/loan.h"

/**
 * @brief Constructor of the class Loan
 * @param book_borrowed book borrowed
 */
Loan::Loan(const Book& book_borrowed) : book_borrowed_(book_borrowed) {
  returned_ = false;
  loan_time_ = std::chrono::system_clock::now();
}

/**
 * @brief Tells whether a loan has been returned
 * @return true if it has false otherwise
 */
bool Loan::IsReturned() const {
  return returned_;
}

/**
 * @brief Sets a loan as returned
 */
void Loan::SetAsReturned() {
  returned_ = true;
}

/**
 * @brief Getter of the book borrowed
 * @return book borrowed
 */
const Book& Loan::GetBookBorrowed() const {
  return book_borrowed_;
}

/**
 * @brief Overload of the operator << to allow the printing of
 * objets of the class Loan
 * @param output reference to output stream
 * @param loan loan to print
 * @return print of the loan and reference to the output stream
 */
std::ostream& operator<<(std::ostream& output, const Loan& loan) {
  output << "Borrowed book named " << loan.GetBookBorrowed();
  return output;
}

/**
 * @brief Tells whether a loan has its time limit exceeded
 * @return true if it has false otherwise
 */
bool Loan::TimeLimitExceeded() const {
  const int KHoursInADay{24};
  const int KDaysAfterTimeExceeded{90};
  std::chrono::system_clock::time_point current_time =
      std::chrono::system_clock::now();
  std::chrono::system_clock::time_point three_months_later =
      current_time + std::chrono::hours(KHoursInADay * KDaysAfterTimeExceeded);
  if (std::chrono::system_clock::now() >= three_months_later) {
    return true;
  }
  return false;
}