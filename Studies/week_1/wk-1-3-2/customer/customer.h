#if !defined(CUSTOMER_H)
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>


namespace customer{

    struct Account{
        std::string accountId {-1};
        double balance {0.0};
    };

    struct UserData{

        std::string custId {""};
        std::string passWord {""};
        std::string name {""};
        std::string address {""};
        std::string phone {""};
        std::map<std::string, Account> accounts;

        private:
            int nextUnusedId {-1};
        public:
            std::string createNewAccountId(){
                nextUnusedId++;
                return std::to_string(nextUnusedId);
    }
    };

    // prints account balance
    void showBalance(Account& account){
        std::cout << "Account " << account.accountId
                  << " has balance of: " << account.balance << "\n\n";
    }

    // data validation functions
    bool validateName(UserData& user){
        return user.name.length() > 0;
    }
    bool validateAdress(UserData& user){
        return user.address.length() > 0;
    }
    bool validatePhone(UserData& user){
        return user.phone.length() > 0;
    }
}

#endif // CUSTOMER_H
