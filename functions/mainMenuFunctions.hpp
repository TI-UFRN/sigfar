#ifndef _MAINMENUFUNCTIONS
#define _MAINMENUFUNCTIONS

#include <vector>

#include "../entities/user.hpp"

User *doLogin(std::vector<User *>);
User *doRegister(std::vector<User *>);
bool existsUsernameOnVector(std::vector<User *>, std::string);
User *loginScript(std::vector<User *>, std::string, std::string);

#endif