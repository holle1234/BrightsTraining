#include <iostream>
#include <vector>
#include <string>



struct UserData{

    int custId {-1};
    std::string name {""};
    std::string address {""};
    std::string phone {""};
    double balance {0.0};
};


struct BankDataBase{
    private:
        std::vector<UserData> db;
        int _nextUnusedUserId {-1};

        // creates a new user id
        int _createUserId(){
            _nextUnusedUserId++;
            return _nextUnusedUserId;
        }

    public:

        // returns account balance
        double add(UserData user, double amount){
            return user.balance;
        }

        // returns account balance
        double withdraw(UserData user, double amount){
            return user.balance;
        }

        // returns account balance
        double checkBalance(UserData user){
            return user.balance;
        }
        // User validation functions
        bool validateName(UserData user){
            return user.name.length() > 0;
        }
        bool validateAdress(UserData user){
            return user.address.length() > 0;
        }
        bool validatePhone(UserData user){
            return user.phone.length() > 0;
        }

        // fill user data via prompts
        UserData fillUserData(){

        }

        // returns freshly created account
        UserData createUser(UserData user){
            
            // check if user is ready to be added
            if (!validateName(user)){

            }
            if (!validateAdress(user)){

            }
            if (!validatePhone(user)){

            }

            user.custId = _createUserId();

            return user;
        }

        // returns saved user object if found otherwise empty
        UserData findUser(int userId){
            const UserData user {};

            for (auto &&i : db){
                if (userId == i.custId){
                    return i;
                }
            }
            
            return user;
        }

};



int main(){

    bool continueTransactions {true};
    while(continueTransactions){


    }

    return 0;
}
