#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../loggedState.hpp"

#include "../../entities/user.hpp"
#include "../../entities/medicine.hpp"
#include "../../entities/userType.hpp"
#include "../../entities/cart.hpp"

#include "../print.hpp"

void loginState(User *user, std::vector<Medicine *> storage)
{
    Cart cart;
    std::string messageError("");
    char choiceBefore = ' ';
    while (true)
    {
        printPresentation();
        printUserNav(user);

        printUserLoggedMenu(user->getUserType());
        if (messageError != "")
        {
            printMessageError(messageError);
        }

        char choice;
        if (choiceBefore == ' ')
        {
            std::cout << "\033[1;37m> \033[1;37m";
            std::cin >> choice;
            std::cin.ignore();
        }
        else
        {
            choice = choiceBefore;
            choiceBefore = ' ';
        }

        if (choice == '*')
        {
            return;
        }
        else if (choice == '#')
        {
            messageError = "";
            std::string messageErrorChoiceCart("");
            while (true)
            {
                printPresentation();
                printUserNav(user);
                printCart(cart);
                printSupportMenu("cart");
                if (messageErrorChoiceCart != "")
                {
                    printMessageError(messageErrorChoiceCart);
                }
                std::string choice2;
                std::cout << "\033[1;37m> \033[1;37m";
                std::getline(std::cin, choice2);

                if (choice2[0] == '*')
                {
                    messageErrorChoiceCart = "";
                    break;
                }
                else if (choice2.substr(0, 6) == "remove")
                {
                    std::vector<std::string> command = split(choice2, ' ');
                    int index = std::stoi(command[1]) - 1;
                    if (index >= cart.getSize())
                    {
                        messageErrorChoiceCart = "Medicamento inexistente";
                    }
                    else
                    {
                        cart.removeMedicine(index);
                    }
                }
                else if (choice2.substr(0, 7) == "comprar")
                {
                }
            }
        }
        else if (choice == '1')
        {
            messageError = "";
            std::string messageErrorChoice1("");
            while (true)
            {
                printPresentation();
                printUserNav(user);
                printStorage(storage);
                printSupportMenu("storageClient");
                if (messageErrorChoice1 != "")
                {
                    printMessageError(messageErrorChoice1);
                }
                std::string choice2;
                std::cout << "\033[1;37m> \033[1;37m";
                std::getline(std::cin, choice2);
                if (choice2[0] == '*')
                {
                    messageErrorChoice1 = "";
                    break;
                }
                else if (choice2[0] == '#')
                {
                    messageErrorChoice1 = "";
                    choiceBefore = '#';
                    break;
                }
                else if (choice2[0] == '@')
                {
                    messageErrorChoice1 = "";
                }
                else if (choice2.substr(0, 3) == "add")
                {
                    messageErrorChoice1 = "";

                    try
                    {
                        std::vector<std::string> command = split(choice2, ' ');
                        int index = std::stoi(command[1]) - 1;
                        int quant = std::stoi(command[2]);
                        if (quant > storage[index]->getAmmount())
                        {
                            messageErrorChoice1 = "Não temos esta quantidade de medicamentos!";
                        }
                        else
                        {
                            Medicine *med = new Medicine(storage[index]->getName(), storage[index]->getValue(), quant);
                            cart.addMedicine(med);
                            storage[index]->setAmmount(storage[index]->getAmmount() - quant);
                        }
                    }
                    catch (const char *msg)
                    {
                        messageErrorChoice1 = "Comando inválido!";
                    }
                }
                else if (choice2.substr(0, 6) == "search")
                {
                    messageErrorChoice1 = "";
                    std::string searchString = choice2.substr(7, choice2.size());
                    printPresentation();
                    printStorageSearch(storage, searchString);
                    char pause;
                    std::cout << "\033[0;37mPressione enter para continuar...\033[0;37m";
                    std::cin.get();
                }
                else
                {
                    messageErrorChoice1 = "Comando inválido!";
                }
            }
        }
        else if (choice == '2' && user->getUserType() == ADMIN)
        {
            messageError = "";
        }
        else if (choice == '3' && user->getUserType() == ADMIN)

        {
            messageError = "";
        }
        else
        {
            messageError = "Escolha inexistente, digite novamente!";
        }
    }
}

std::vector<std::string> split(const std::string &str, char delim)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delim))
    {
        tokens.push_back(token);
    }
    return tokens;
}