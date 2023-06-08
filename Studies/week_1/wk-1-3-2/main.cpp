#include <iostream>
#include <vector>
#include <string>
#include <map>


 /*
 Flow:
    if not credentials
        sign in with id and password
    else
        pass id and credentials to db when
        interacting with functions
 
 */



// random integer between low and high
int randomBetween(int low=0, int high=10){
	std::srand((unsigned) time(NULL));
	return low + (rand() % high);
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


struct Account{
    int accountId {-1};
    double balance {0.0};
};


struct UserData{

    int custId {-1};
    std::string passWord {""};
    std::string name {""};
    std::string address {""};
    std::string phone {""};
    std::map<int, Account> accounts;
};


struct BankDataBase{
    private:
        std::map<int, UserData> db;
        const UserData emptyUser {};
        int _nextUnusedUserId {-1};

        // creates a new user id
        int _createUserId(){
            _nextUnusedUserId++;
            return _nextUnusedUserId;
        }

    public:

        // sets new account balance
        void deposit(int credentials, int id, double amount){
        }
        // sets new account balance
        void withdraw(int credentials, int id, double amount){
        }
        // shows account balance
        void checkBalance(int credentials, int id){
        }

        // fill user data via prompts
        int fillUserData(){
            UserData user {};

            // check if user is ready to be added
            if (!validateName(user)){

            }
            if (!validateAdress(user)){

            }
            if (!validatePhone(user)){

            }

            // add userid and add user to database
            int newId {_createUserId()};
            db[newId] = user;
            return newId;
        }

        // returns credentials
        int login(int userId, std::string password){
            if (db.find(userId) != db.end()){
                // return credentials
            }
            // return -1
        }
};



int main(){


    bool continueTransactions {true};
    while(continueTransactions){

        std::cout << randomBetween(0, 10);
    }

    return 0;
}
