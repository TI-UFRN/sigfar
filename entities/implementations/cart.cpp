
#include <iostream>
#include <vector>
#include "../cart.hpp"
#include "../medicine.hpp"

Cart::Cart()
{
    this->size = 0.0;
    this->total = 0.0;
}

Cart::~Cart()
{
}

std::vector<Medicine *> Cart::getMedicines()
{
    return this->medicines;
}

void Cart::addMedicine(Medicine *medicine)
{
    size++;
    this->medicines.push_back(medicine);
    total += medicine->getValue() * medicine->getAmmount();
}

void Cart::removeMedicine(int index)
{
    size--;
    this->total = this->total - (medicines[index]->getValue() * medicines[index]->getAmmount());
    auto it = std::next(getMedicines().begin(), index);

    if (index >= 0 && index < getMedicines().size())
    {
        getMedicines().erase(it);
    }
}

int Cart::getSize()
{
    return this->size;
}

double Cart::getTotal()
{
    return this->total;
}