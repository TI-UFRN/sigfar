
#include <vector>
#include "../cart.hpp"
#include "../medicine.hpp"

Cart::Cart()
{
    this->size = 0;
    this->total = 0;
}

Cart::~Cart()
{
}

std::vector<Medicine*> Cart::getMedicines()
{
    return this->medicines;
}

void Cart::addMedicine(Medicine* medicine)
{
    getMedicines().push_back(medicine);
}

void Cart::removeMedicine(int index)
{
    if (index >= 0 && index < getMedicines().size())
    {
        getMedicines().erase(getMedicines().begin() + index);
    }
}
