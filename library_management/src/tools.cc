/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author Paulo Padilla Domingues alu0101571836@ull.edu.es
 * @date 15/04/2024
 * @brief Development of tools functions
 * @bug
 * @see
*/
#include "../include/tools.h"

/**
 * @brief Unauthenticated user menu
*/
void CurrentUserMenu(void) {
  system("clear");
  char option;
  bool verify_option = true;
  while(verify_option) {
    std::cout << "\n###### Library Management ######\n";
    std::cout << "\nChoose one of the following options:\n";
    std::cout << "1. Sign in\n";
    std::cout << "2. Search\n";
    std::cout << "3. Change password\n";
    std::cout << "0. Exit\n";
    std::cout << "\nOption: ";
    std::cin >> option;
    if(option < 48 || option >= 52) {
      system("clear");
      std::cout << "\n## Wrong option. Choose a valid option##\n";
    }
    switch(option) {
      case '1':
        system("clear");
        break;
      case '2':
        system("clear");
        break;
      case '3':
        system("clear");
        break;
      case '0':
        verify_option = false;
        std::cout << "\nLeaving the system...\n\n";
        break;
    }
  }
}