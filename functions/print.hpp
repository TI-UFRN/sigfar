#ifndef _PRINT
#define _PRINT

#include <string>
#include <vector>
#include "../entities/user.hpp"
#include "../entities/cart.hpp"
#include "../entities/medicine.hpp"
#include "../entities/userType.hpp"

void printPresentation();
void printMainMenu();
void printMessageError(std::string);
void printLoginNav();
void printUserNav(User *);
void printUserLoggedMenu(UserType);
void printRegisterNav();
void printLabel(std::string);
void printOut();
void printStorage(std::vector<Medicine *>);
void printStorageSearch(std::vector<Medicine *>, std::string);
void printSupportMenu(std::string);
void printCart(Cart cart);

#endif