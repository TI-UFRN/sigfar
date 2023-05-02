#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

#include "../files.hpp"
#include "../encrypt.hpp"
#include "../constants.hpp"
#include "../../entities/medicine.hpp"
#include "../../entities/user.hpp"
#include "../../entities/userType.hpp"

void writeUserOnFile(std::string path, User *user)
{

    std::ofstream arquivo(path, std::ios::app);

    if (arquivo.is_open())
    {
        arquivo << user->getUsername() << std::endl;
        arquivo << user->getPassword() << std::endl;
        arquivo << user->getUserType() << std::endl;

        arquivo.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo " << path << std::endl;
    }
}

std::vector<User *> readUsers(std::string path)
{
    std::ifstream arquivo(path);
    std::vector<User *> users;
    if (arquivo.is_open())
    {
        std::string username, password;
        int userTypeInt;

        while (std::getline(arquivo, username))
        {
            arquivo >> password >> userTypeInt;
            arquivo.ignore();
            UserType userType = userTypeInt == 0 ? ADMIN : CLIENT;

            User *user = new User(username, encrypt(password, KEY_ENCRYPT), userType);
            users.push_back(user);
        }
        arquivo.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo " << path << std::endl;
    }
    return users;
}

void writeMedicinesOnFile(std::string path, std::vector<Medicine *> medicines)
{

    std::ofstream arquivo(path);

    if (arquivo.is_open())
    {
        for (int i = 0; i < medicines.size(); i++)
        {
            arquivo << " " << medicines[i]->getName() << " ";
            arquivo << medicines[i]->getValue() << " ";
            arquivo << medicines[i]->getAmmount() << std::endl;
        }

        arquivo.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo " << path << std::endl;
    }
}

std::vector<Medicine *> readMedicines(std::string path)
{
    std::ifstream arquivo(path);
    std::vector<Medicine *> mediciners;
    if (arquivo.is_open())
    {

        std::string line;
        while (std::getline(arquivo, line))
        {
            line = trim(line);
            std::string name;
            double value;
            int ammount;

            std::stringstream stream(line);

            stream >> name >> value >> ammount;
            arquivo.ignore();

            Medicine *medicine = new Medicine(name, value, ammount);
            mediciners.push_back(medicine);
        }
        arquivo.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo " << path << std::endl;
    }
    return mediciners;
}

// Remove espaços em branco do início e do final da string
std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }
    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}