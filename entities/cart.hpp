#ifndef _CART
#define _CART

#include <vector>
#include "./medicine.hpp"

class Cart
{
private:
    std::vector<Medicine *> medicines;
    int size;
    double total;
public:
    Cart();
    ~Cart();
    std::vector<Medicine *> getMedicines();
    void addMedicine(Medicine *);
    void removeMedicine(int);
    int getSize();
    double getTotal();
};

#endif