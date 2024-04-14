#include "book.h"
#include "loan.h"
#include "user.h"
#include <iostream>
class Author {
public:
  Author(const std::string& name) : name_(name) {}

private:
  std::string name_;
};
int main() {
  Author author("Miguel de Cervantes");
  Book book("El Quijote", 1, author);
  User user("Pepe", 1, "password");
  Loan loan(book, user);
  std::cout << loan  << std::endl;
  std::cout << "Loan returned status: " << (loan.IsReturned() ? "Yes" : "No")
            << std::endl;

  return 0;
}