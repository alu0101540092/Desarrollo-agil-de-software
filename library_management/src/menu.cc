/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 15/04/2024
 * @brief User menu
 * @bug
 * @see
 */
#include "../include/book.h"
#include "../include/system.h"
#include "../include/tools.h"
#include "../include/user.h"

int main(int argc, char* argv[]) {
  const std::string KBooksDataFilename{"books.txt"};
  const std::string KUsersDataFilename{"users.txt"};
  System system;
  ProcessUserFileInput(KUsersDataFilename, system);
  ProcessBookFileInput(KBooksDataFilename, system);

  UserMenu(system);
  
  WriteBooksData(KBooksDataFilename, system);
  WriteUsersData(KUsersDataFilename, system);
  return 0;
}