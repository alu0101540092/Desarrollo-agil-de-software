/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 15/04/2024
 * @brief Function declaration tools
 * @bug
 * @see
 */

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "book.h"
#include "system.h"
#include "user.h"

#pragma once

void UserMenu(System& system);
bool PostUserMenu(System& systema, User& user);
void ProcessBookFileInput(const std::string& file_name, System& system);
void ProcessUserFileInput(const std::string& file_name, System& system);
void WriteUsersData(const std::string& file_name, const System& system);
void WriteBooksData(const std::string& file_name, const System& system);
User NewUser();
bool UsernameExist(const std::string& username);
User* SignIn(System& system);
std::vector<Book*> Search(System& system);
void Password(System& system, const User& user);