#ifndef _MEDICINE
#define _MEDICINE

#include <string>

class Medicine {
    private:
        std::string name;
        double value;
        int ammount;
    public:
        Medicine(std::string, double, int);
        ~Medicine();

        std::string getName();
        void setName(std::string);

        double getValue();
        void setValue(double);

        int getAmmount();
        void setAmmount(int);
};

#endif