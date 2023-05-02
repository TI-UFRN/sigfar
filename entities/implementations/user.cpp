#include "../userType.hpp"
#include "../user.hpp"
#include "../../functions/encrypt.hpp"
#include "../../functions/constants.hpp"

User::User(std::string username, std::string password, UserType userType)
{
    setUsername(username);
    setpassword(password);
    setUserType(userType);
}

User::~User() {}

std::string User::getUsername()
{
    return this->username;
}

void User::setUsername(std::string username)
{
    this->username = username;
}

std::string User::getPassword()
{
    return this->password;
}

void User::setpassword(std::string password)
{
    this->password = encrypt(password, KEY_ENCRYPT);
}

UserType User::getUserType()
{
    return this->userType;
}

void User::setUserType(UserType userType)
{
    this->userType = userType;
}