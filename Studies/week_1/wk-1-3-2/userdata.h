#ifndef USERDATA_H
#define USERDATA_H

#include <string>


struct UserData
{
    private:
        std::string name {""};
        std::string address {""};
        std::string phone {""};
        std::string custId {""};
        double balance {0.0};

    public:
        double add(double amount){
            return 0.0;
        }

        double withdraw(double amount){
            return 0.0;
        }

        double checkBalance(double amount){
            return 0.0;
        }
};

#endif