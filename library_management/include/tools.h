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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "system.h"
#include "book.h"
#include "user.h"

#pragma once

void CurrentUserMenu(System& system);
void ProcessFileInput(const std::string& file_name, System& system);
User NewUser();
void SignIn(System& system);
void Search(System& system);
void Password(System& system, const User& user);