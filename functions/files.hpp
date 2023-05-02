#include <vector>
#include "../entities/user.hpp"
#include "../entities/medicine.hpp"

void writeUserOnFile(std::string, User*);
std::vector<User*> readUsers(std::string);
std::vector<Medicine*> readMedicines(std::string);
void writeMedicinesOnFile(std::string, std::vector<Medicine *>);
std::string trim(const std::string&);