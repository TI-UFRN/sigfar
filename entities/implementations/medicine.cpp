#include "../medicine.hpp"

Medicine::Medicine(std::string name, double value, int ammount)
{
    setName(name);
    setValue(value);
    setAmmount(ammount);
}

Medicine::~Medicine()
{
}

std::string Medicine::getName()
{
    return this->name;
}

void Medicine::setName(std::string name)
{
    this->name = name;
}

double Medicine::getValue()
{
    return this->value;
}

void Medicine::setValue(double value)
{
    this->value = value;
}

int Medicine::getAmmount()
{
    return this->ammount;
}

void Medicine::setAmmount(int ammount)
{
    this->ammount = ammount;
}