#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>
#include "../print.hpp"

void printPresentation()
{
    system("clear");
    std::cout << "\033[1;36m==============================================================\033[1;36m" << std::endl;
    std::cout << "\033[1;36m                            SIGFAR                            \033[1;36m" << std::endl;
    std::cout << "\033[1;36m           Sistema Integrado de Gestão de Farmácias           \033[1;36m" << std::endl;
    std::cout << "\033[1;36m==============================================================\033[1;36m" << std::endl;
}

void printMainMenu()
{
    std::cout << "\033[1;33m                        Menu do sistema                       \033[1;33m" << std::endl;
    std::cout << "\033[1;33m                          1 - Login                           \033[1;33m" << std::endl;
    std::cout << "\033[1;33m                          2 - Cadastro                        \033[1;33m" << std::endl;
    std::cout << "\033[1;33m                          3 - Sair                            \033[1;33m" << std::endl;
}

void printMessageError(std::string message)
{
    std::string spaces("");
    int nSpaces = 63 - message.size();
    for (int i = 1; i <= nSpaces; i++)
        spaces += " ";
    std::cout << "\033[1;31m" + spaces + message + "\033[1;31m" << std::endl;
}

void printRegisterNav()
{
    std::cout << "\033[1;33m                          CADASTRO                    * voltar\033[1;33m" << std::endl;
}

void printUserNav(User *user)
{
    std::string information("@" + user->getUsername());
    int nSpaces = 52 - information.size();
    std::string spaces("");
    for (int i = 1; i <= nSpaces; i++)
    {
        spaces += " ";
    }
    std::cout << "\033[1;33m                        Bem vindo (a)                 * voltar\033[1;33m" << std::endl;
    std::cout << "\033[1;33m" + information + spaces + "# Carrinho\033[1;33m" << std::endl;
}

void printUserLoggedMenu(UserType userType)
{
    std::cout << std::endl;
    std::cout << "\033[1;33m                        1 - Listar Medicamentos               \033[1;33m" << std::endl;
    if (userType == ADMIN)
    {
        std::cout << "\033[1;33m                        2 - Estoque                           \033[1;33m" << std::endl;
        std::cout << "\033[1;33m                        3 - Usuários                          \033[1;33m" << std::endl;
    }
}

void printLabel(std::string label)
{
    std::cout << "\033[1;33m                          " + label + ": \033[1;33m";
}

void printLoginNav()
{
    std::cout << "\033[1;33m                            LOGIN                     * voltar\033[1;33m" << std::endl;
}

void printOut()
{
    std::cout << "\n\033[1;33m                        Muito obrigado!                       \033[1;33m" << std::endl;
    std::cout << "\033[1;36m______________________________________________________________\033[1;36m" << std::endl;
}

void printStorage(std::vector<Medicine *> storage)
{
    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
    std::cout << "\033[1;33m                         Medicamentos                         \033[1;33m" << std::endl;
    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
    std::cout << "\033[1;33mIdentificador                       |    Preço    |  Estoque  \033[1;33m" << std::endl;
    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
    for (int i = 0; i < storage.size(); i++)
    {
        std::string nome(storage[i]->getName());
        std::ostringstream streamId;
        streamId << i + 1;
        nome = streamId.str() + " - " + nome;
        int nNomeSpaces = 36 - nome.size();

        std::string spacesName("");
        for (int i = 1; i <= nNomeSpaces; i++, spacesName += " ")
            ;

        std::string value("R$");
        std::ostringstream streamValue;
        std::locale loc("pt_BR.utf8");
        streamValue.imbue(loc);
        streamValue << std::fixed << std::setprecision(2) << storage[i]->getValue();
        std::string valorString = streamValue.str();

        value += valorString;
        std::string spaceValue("");
        for (int i = 1; i <= (14 - value.size()) / 2; i++, spaceValue += " ")
            ;
        value = spaceValue + value;
        spaceValue = "";

        int nSpaceAfter = (15 - value.size()) / 2;
        if ((15 - value.size()) % 2 != 0)
        {
            nSpaceAfter++;
        }
        for (int i = 1; i <= nSpaceAfter; i++, spaceValue += " ")
            ;

        value = value + spaceValue;

        std::ostringstream streamAmmount;
        streamAmmount.imbue(loc);
        streamAmmount << storage[i]->getAmmount();
        std::string ammountStr = streamAmmount.str();
        ammountStr += " unid";

        std::cout << "\033[1;33m" + nome + spacesName + "|" + value + "| " + ammountStr + "\033[1;33m" << std::endl;
    }

    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
}

void printSupportMenu(std::string type)
{
    if (type == "storageClient")
    {
        std::cout << "\033[1;33m> add [id] [quantidade]______Adicionar medicamento no carrinho\033[1;33m" << std::endl;
        std::cout << "\033[1;33m> search [string]______________Pesquisar medicamento pelo nome\033[1;33m" << std::endl
                  << std::endl;
    }
}

void printStorageSearch(std::vector<Medicine *> storage, std::string filter) {
    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
    std::cout << "\033[1;33m                         Medicamentos                         \033[1;33m" << std::endl;
    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
    std::cout << "\033[1;33mIdentificador                       |    Preço    |  Estoque  \033[1;33m" << std::endl;
    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
    for (int i = 0; i < storage.size(); i++)
    {
        if(storage[i]->getName().find(filter) == std::string::npos) continue;
        std::string nome(storage[i]->getName());
        std::ostringstream streamId;
        streamId << i + 1;
        nome = streamId.str() + " - " + nome;
        int nNomeSpaces = 36 - nome.size();

        std::string spacesName("");
        for (int i = 1; i <= nNomeSpaces; i++, spacesName += " ")
            ;

        std::string value("R$");
        std::ostringstream streamValue;
        std::locale loc("pt_BR.utf8");
        streamValue.imbue(loc);
        streamValue << std::fixed << std::setprecision(2) << storage[i]->getValue();
        std::string valorString = streamValue.str();

        value += valorString;
        std::string spaceValue("");
        for (int i = 1; i <= (14 - value.size()) / 2; i++, spaceValue += " ")
            ;
        value = spaceValue + value;
        spaceValue = "";

        int nSpaceAfter = (15 - value.size()) / 2;
        if ((15 - value.size()) % 2 != 0)
        {
            nSpaceAfter++;
        }
        for (int i = 1; i <= nSpaceAfter; i++, spaceValue += " ")
            ;

        value = value + spaceValue;

        std::ostringstream streamAmmount;
        streamAmmount.imbue(loc);
        streamAmmount << storage[i]->getAmmount();
        std::string ammountStr = streamAmmount.str();
        ammountStr += " unid";

        std::cout << "\033[1;33m" + nome + spacesName + "|" + value + "| " + ammountStr + "\033[1;33m" << std::endl;
    }

    std::cout << "\033[1;33m______________________________________________________________\033[1;33m" << std::endl;
}

void printCart()