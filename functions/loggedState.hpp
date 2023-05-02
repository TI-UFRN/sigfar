#ifndef _LOGGEDSTATE
#define _LOGGEDSTATE

#include <vector>
#include "../entities/medicine.hpp"
#include "../entities/user.hpp"

void loginState(User*, std::vector<Medicine *>);
std::vector<std::string> split(const std::string&, char);

#endif