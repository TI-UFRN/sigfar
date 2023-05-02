#ifndef _USER
#define _USER

#include <string>
#include "userType.hpp"

class User {
    private:
        std::string username;
        std::string password;
        UserType userType;
    public:

        User(std::string, std::string, UserType);
        ~User();

        std::string getUsername();
        void setUsername(std::string);

        std::string getPassword();
        void setpassword(std::string);

        UserType getUserType();
        void setUserType(UserType);
};

#endif