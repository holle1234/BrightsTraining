#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>


// use these to store csv data
using csvMap = std::map<std::string, std::string>;
using csvVector = std::vector<csvMap>;

// bank structures
struct Account;
struct UserData;
struct BankDataBase;

// bank functions
int optionsDialog();
bool userDetailsDialog(BankDataBase&);
bool createUserDialog(BankDataBase&);
bool quitDialog();
double withdrawDialog();
double depositDialog();
void loginDialog(BankDataBase&);
std::string accountIdDialog(UserData&);

// csv functions
bool csvRead(std::string, csvVector&);
bool csvWrite(std::string, const csvVector&);


// Read csv to map, key is a column name 
// csv must have a header for this to work!
bool csvRead(std::string fileName, csvVector& dest){

    // open filestream
    std::fstream myFile;
    myFile.open(fileName, std::ios::in);

    if(!myFile.is_open()){
        return false;
    }

    std::vector<std::string> header;
    std::vector<std::string> row;
    std::string rawRow {""};
    std::string word {""};
    int rowIndex {0};

    // [word = split(line, ',') for line in stream(rawFileRow)]
    while (std::getline(myFile, rawRow)){
        std::stringstream stream {rawRow};
        while (std::getline(stream, word,  ',')){
            row.push_back(word);
        }

        // unpack non header rows
        if (rowIndex != 0){
            csvMap map;
            for (size_t i = 0; i < header.size(); i++){
                map[header[i]] = row[i];
            }
            dest.push_back(map);
        }
        // unpack header
        else header = row;

        row.clear();
        rowIndex++;
    }
    myFile.close();
    return true;
}


bool csvWrite(std::string fileName, const csvVector& data){

    // open filestream
    std::fstream myFile;
    myFile.open(fileName, std::ios::out);
    
    if(!myFile.is_open()){
        return false;
    }

    // write header first
    auto lastElement {data[0].rbegin()->first};
    for (auto &&i : data[0]){
        bool isLast {i.first == lastElement};
        myFile << i.first << ((isLast) ? "\n" : ",");
    }
    
    // write data rows
    for (auto &&mapObject : data){
        auto lastElement {mapObject.rbegin()->first};
        for (auto &&i : mapObject){
            bool isLast {i.first == lastElement};
            myFile << i.second << ((isLast) ? "\n" : ",");
        }
    }
    
    myFile.close();

    return true;
}



enum class Actions{
    deposit,
    withdraw,
    balanceCheck,
    accoutCreation,
    quit  
};


struct Account{
    std::string accountId {-1};
    double balance {0.0};

    // prints account balance
    void showBalance(){
        std::cout << "Account " << accountId
                    << " has balance of: " << balance << "\n\n";
    }
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

        // dummy data validation functions
        bool validateName(){
            return name.length() > 0;
        }
        bool validateAdress(){
            return address.length() > 0;
        }
        bool validatePhone(){
            return phone.length() > 0;
        }

};



struct BankDataBase{
    private:
        UserData currentUser {};
        std::map<std::string, UserData> db;
        int nextUnusedId {-1};

        // creates a new user id
        std::string _createId(){
            nextUnusedId++;
            return std::to_string(nextUnusedId);
        }

    public:
        // returns weather theres a logged user
        bool hasActiveUser(){
            return db.find(currentUser.custId) != db.end();
        }

        // If requested account exists
        bool isExistingAccount(std::string accountId){
            auto accounts {currentUser.accounts};
            return accounts.find(accountId) != accounts.end();
        }

        // sets new account balance
        void deposit(){
            std::string accountId {accountIdDialog(currentUser)};
            if(isExistingAccount(accountId)){
                double amount {depositDialog()};
                Account& account {currentUser.accounts[accountId]};
                account.balance += amount;
                account.showBalance();
            }
        }
        // sets new account balance
        void withdraw(){
            std::string accountId {accountIdDialog(currentUser)};
            if(isExistingAccount(accountId)){
                double amount {withdrawDialog()};
                Account& account {currentUser.accounts[accountId]};
                account.balance -= amount;
                account.showBalance();
            }
        }
        // prints balances of all user accounts
        void checkBalance(){
            auto accounts = currentUser.accounts;
            for (auto it = accounts.begin(); it != accounts.end(); it++) {
                std::cout << "Account " << it->first
                          << " has balance of: " << it->second.balance << "e\n";
            }
            std::cout << "\n";
        }

        // fill user data via prompts
        std::string addCustomer(UserData user){
            // add userid and add user to database
            user.custId = _createId();
            db[user.custId] = user;
            // log in as current user
            currentUser = {db[user.custId]};
            return user.custId;
        }

        // new account for current user
        void createNewAccount(){
            std::string accountId {currentUser.createNewAccountId()};
            Account account {accountId, 0.0};
            currentUser.accounts[accountId] = account;
            std::cout << "New account with id: " << accountId << " created\n\n";
        }

        // login to bank
        bool login(std::string userId, std::string password){
            if(db.find(userId) != db.end()){
                if (db[userId].passWord == password){
                    currentUser = db[userId];
                    return true;
                }
            }
            return false;
        }

        // logout
        void logout(){
            currentUser = {};
        }

};


int optionsDialog(){

    int action {0};
    std::cout << "What would you like to do?\n";
    std::cout << "0: deposit\n1: withdraw\n2: balance\n3: new account\n4: quit\n";
    std::cout << "Please select an action: ";
    std::cin >> action;
    std::cout << "\n";
    return action;
}


bool userDetailsDialog(BankDataBase& bankDB){

    UserData user {};
    int step {0};

    while (true){
        switch (step){
        case 0:{
            std::cout << "name: ";
            std::cin >> user.name;
            if(user.validateName()){++step;}
        }
        case 1:{
            std::cout << "address: ";
            std::cin >> user.address;
            if(user.validateAdress()){++step;}
        }
        case 2:{
            std::cout << "phone: ";
            std::cin >> user.phone;
            if(user.validatePhone()){++step;}
        }
        case 3:{
            std::cout << "password: ";
            std::cin >> user.passWord;
            ++step;
        }
        case 4:{
            std::string newId {bankDB.addCustomer(user)};
            std::cout << "New user added!\nYour id is: " << newId << "\n\n";
            return true;
        }
        default: break;
        
        }
    }
}


bool createUserDialog(BankDataBase& bankDB){
    char createNewCustomer {'n'}; 
    std::cout << "Create new customer? (y/n): ";
    std::cin >> createNewCustomer;

    if(createNewCustomer == 'y'){
        std::cout << "\n\n";
        return userDetailsDialog(bankDB);
    }

    return false;

}

void loginDialog(BankDataBase& bankDB){
    std::string passWord {0};
    std::string userId {""};

    std::cout << "Login to use your accounts\n";
    std::cout << "Give user ID: ";
    std::cin >> userId;
    
    std::cout << "Give password: ";
    std::cin >> passWord;

    if(bankDB.login(userId, passWord)){
        std::cout << "Successfully logged in!\n\n";
    }
    else{
        std::cout << "Invalid id or password!\n";
        createUserDialog(bankDB);
    }
}


std::string accountIdDialog(UserData& user){

    int accountId {0};
    std::map<int, std::string> remappedCopy;

    if(user.accounts.size() == 0){
        std::cout << "You have no accounts, please create one first.:\n\n";
        return "";
    }
    else std::cout << "You have following accounts:\n";
    
    int index {0};
    // remap account ids so user can pick one with index only
    for (auto it = user.accounts.begin(); it != user.accounts.end(); it++) {
        std::cout << index << ") " << it->first << "\n";
        remappedCopy[index] = it->first;
        ++index;
    }

    std::cout << "Which account would you like to use (number): ";
    std::cin >> accountId;
    return remappedCopy[accountId];
    
}

double withdrawDialog(){

    double amount {0.0};
    std::cout << "How much would you like to withdraw?: ";
    std::cin >> amount;
    
    if(amount < 0.0){
        std::cout << "Invalid amount inserted!\n";
    }

    std::cout << "\n";
    return amount;
}


double depositDialog(){
    double amount {0.0};

    std::cout << "How much would you like to deposit?: ";
    std::cin >> amount;
    
    if(amount < 0.0){
        std::cout << "Invalid amount inserted!\n";
    }
    std::cout << "\n";
    return amount;
}


bool quitDialog(){
    char doExit {'n'};
    std::cout << "Exit? (y/n): ";
    std::cin >> doExit;
    return doExit == 'y';
}



int main(){

    BankDataBase bankDB {};
    
    bool continueTransactions {true};
    while(continueTransactions){

        if(!bankDB.hasActiveUser()){
            loginDialog(bankDB);
        }
        else {
            Actions action {optionsDialog()};
            switch (action){

                case Actions::deposit: {
                    bankDB.deposit();
                    break;
                }
                case Actions::withdraw:{
                    bankDB.withdraw();
                    break;
                }
                case Actions::balanceCheck:{
                    bankDB.checkBalance();
                    break;
                }
                case Actions::accoutCreation:{
                    bankDB.createNewAccount();
                    break;
                }
                case Actions::quit:{
                    if(quitDialog()){
                        bankDB.logout();
                    }
                    break;
                }
                default: break;
            }
        }

    }

    return 0;
}