/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author Samuel Rodríguez alu0101545714@ull.edu.es
 * @date 14/04/2024
 * @brief Declarations of the Loan class
 * @bug
 * @see
*/

#ifndef LOAN_H_
#define LOAN_H_

#include <chrono>
#include <iostream>

class Book;
class User;
/**
 * @brief Represents a loan of a book
 */
class Loan {
  public:
    Loan(const Book& book_borrowed, const User& borrower)
        : borrower_(borrower),
          book_borrowed_(book_borrowed),
          loan_time_(std::chrono::system_clock::now()),
          returned_(false){};
    bool IsReturned() const { return returned_; };
    void SetAsReturned() { returned_ = true; };
    bool TimeLimitExceeded() const;
    const User& GetBorrower() const { return borrower_; };
    const Book& GetBookBorrowed() const { return book_borrowed_; };

  private:
    const User& borrower_;
    const Book& book_borrowed_;
    std::chrono::system_clock::time_point loan_time_;
    bool returned_;
};

std::ostream& operator<<(std::ostream& output, const Loan& loan);

#endif  // LOAN_H_