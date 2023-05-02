#include <iostream>

#include "../print.hpp"
#include "../mainMenuFunctions.hpp"
#include "../files.hpp"
#include "../encrypt.hpp"
#include "../constants.hpp"

#include "../../entities/user.hpp"
#include "../../entities/userType.hpp"

User *doLogin(std::vector<User *> allUsers)
{
    printPresentation();
    printLoginNav();
    while (true)
    {
        printLabel("Username");
        std::string username("");
        std::getline(std::cin, username);
        bool isContinue = false;
        if (username == "*")
            return NULL;
        if (username.find(" ") != std::string::npos)
        {
            printMessageError("Username não pode conter espaços");
            isContinue = true;
        }
        else if (username.size() < 5)
        {
            printMessageError("Username tem que ter ao menos 5 caracteres");
            isContinue = true;
        }
        else if (!existsUsernameOnVector(allUsers, username))
        {
            printMessageError("Username não cadastrado");
            isContinue = true;
        }

        if(isContinue) continue;

        printLabel("Password"); // Vou ficar devendo a opção de esconder os caracteres da senha
        std::string password("");
        std::getline(std::cin, password);

        if (password == "*")
            return NULL;

        User *user = loginScript(allUsers, username, password);

        if (user == NULL)
        {
            printPresentation();
            printLoginNav();
            printMessageError("Username e/ou password inválidos");
        }
        else
        {
            return user;
        }
    }

    return NULL;
}

User *doRegister(std::vector<User *> allUsers)
{
    printPresentation();
    printRegisterNav();
    printLabel("Username");
    std::string username("");
    std::getline(std::cin, username);

    while (true)
    {
        if (username == "*")
            return NULL;
        if (username.find(" ") != std::string::npos)
        {
            printMessageError("Username não pode conter espaços");
        }
        else if (username.size() < 5)
        {
            printMessageError("Username tem que ter ao menos 5 caracteres");
        }
        else if (existsUsernameOnVector(allUsers, username))
        {
            printMessageError("Username já existente");
        }
        else
        {
            break;
        }
        printLabel("Username");
        std::getline(std::cin, username);
    }

    printLabel("Password"); // Vou ficar devendo a opção de esconder os caracteres da senha
    std::string password("");
    std::getline(std::cin, password);

    while (true)
    {
        if (password == "*")
            return NULL;
        if (password.size() < 5)
        {
            printMessageError("Password tem que ter ao menos 5 caracteres");
        }
        else
        {
            break;
        }
        printLabel("Password");
        std::getline(std::cin, password);
    }

    User *user = new User(username, password, CLIENT);

    writeUserOnFile(USERS_PATH, user);
    return user;
}

bool existsUsernameOnVector(std::vector<User *> users, std::string username)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getUsername() == username)
            return true;
    }
    return false;
}

User *loginScript(std::vector<User *> users, std::string username, std::string password)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getUsername() == username) {
            if(users[i]->getPassword() == encrypt(password, KEY_ENCRYPT)){
                return users[i];
            } else {
                return NULL;
            }
        }
    }

    return NULL;
}