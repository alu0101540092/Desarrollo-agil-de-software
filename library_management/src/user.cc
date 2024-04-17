/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Fundamentos de Ingeniería del Sofware 2023-2024
 * Práctica 6 : Desarrollo ágil de software
 *
 * @author
 * @date 14/04/2024
 * @brief Definitons of the User class
 * @bug
 * @see
 */

#include "../include/user.h"

/**
 * @brief Constructor of the class User
 * @param name name of the user
 * @param identifier identifier of the user
 * @param password password of the user
 */
User::User(const std::string& name, const int identifier,
           const std::string& password)
    : name_(name),
      password_(password),
      identifier_(identifier),
      is_authenticated_(false) {}

/**
 * @brief Function to check if the user is authenticated
 * @return true if the user is authenticated, false otherwise
 */
bool User::IsAuthenticated() const { return is_authenticated_; }

/**
 * @brief Function to check if the password is correct
 * @param password password to check
 * @return true if the password is correct, false otherwise
 */
bool User::Login(const std::string& password) {
  is_authenticated_ = (password == password_);
  return (password == password_);
}

/**
 * @brief Function to change the password of the user
 * @param password new password
 */
void User::SetPassword(const std::string& password) { password_ = password; }

/**
 * @brief Function to get the name of the user
 * @return name of the user
 */
std::string User::GetName() const { return name_; }

/**
 * @brief Function to get the identifier of the user
 * @return identifier of the user
 */
int User::GetIdentifier() const { return identifier_; }
/**
 * @brief Function to get the identifier of the user
 * @return password of the user
 */
std::string User::GetPassword() const { return password_; }
/**
 * @brief Overload of the operator << to allow the printing of
 * objets of the class User
 * @param output reference to output stream
 * @param user user to print
 * @return print of the user and reference to the output stream
 */
std::ostream& operator<<(std::ostream& output, const User& user) {
  output << user.GetName() << " " << user.GetIdentifier() << " "
         << user.GetPassword();
  return output;
}