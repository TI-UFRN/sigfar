#include <iostream>
#include <string>

#include "functions/print.hpp"
#include "functions/files.hpp"
#include "functions/constants.hpp"
#include "functions/mainMenuFunctions.hpp"
#include "functions/loggedState.hpp"

#include "entities/medicine.hpp"
#include "entities/user.hpp"
#include "entities/userType.hpp"

int main()
{
    std::vector<User *> allUsers = readUsers(USERS_PATH);
    std::vector<Medicine *> storage = readMedicines(MEDICINES_PATH);

    std::string callbackError("");
    while (true)
    {
        printPresentation();
        printMainMenu();
        if (callbackError != "")
        {
            printMessageError(callbackError);
        }

        char choice = 0;
        std::cout << "\033[1;37m> \033[1;37m";
        std::cin >> choice;
        std::cin.ignore();

        while (choice < '1' || choice > '3')
        {
            printPresentation();
            printMainMenu();
            printMessageError("Escolha inexistente, digite novamente! ");
            std::cout << "\033[1;37m> \033[1;37m";
            std::cin >> choice;
        }

        if (choice == '1')
        {
            User *user = doLogin(allUsers);
            callbackError = "";
            if (user != NULL)
            {
                loginState(user, storage);
            }
        }
        else if (choice == '2')
        {
            User *user = doRegister(allUsers);

            if (user == NULL)
            {
                callbackError = "Cadastro cancelado pelo usuário";
            }
            else
            {
                allUsers = readUsers(USERS_PATH);
                callbackError = "";
            }
        }
        else if (choice == '3')
        {
            printPresentation();
            printOut();
            break;
        }
    }
    return 0;
}