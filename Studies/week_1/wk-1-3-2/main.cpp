#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <filesystem>


// use these to store csv data
using csvMap = std::map<std::string, std::string>;
using csvVector = std::vector<csvMap>;

// bank structures
struct Account;
struct Client;
struct BankDataBase;

// bank functions
int optionsDialog();
Client userDetailsDialog(BankDataBase&);
bool quitDialog();
double withdrawDialog();
double depositDialog();
void createUserDialog(BankDataBase&);
void loginDialog(BankDataBase&);
std::string accountIdDialog(const Client&);
void continuePrompt();

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


bool csvWrite(std::string fileName, const csvVector& data, char mode='a'){

    // if file exists we dont want to write header
    bool fileExists {std::filesystem::exists(fileName)};

    // open filestream
    auto fileMode {std::ios::app}; 
    if (mode == 'w'){
        // overwrite previous file
        fileMode = std::ios::out; 
    }

    std::fstream myFile;
    myFile.open(fileName, fileMode);
    
    if(!myFile.is_open()){
        return false;
    }

    // write header first
    if (!fileExists){
        auto lastElement {data[0].rbegin()->first};
        for (auto &&i : data[0]){
            bool isLast {i.first == lastElement};
            myFile << i.first << ((isLast) ? "\n" : ",");
        }
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
    std::string accountId {};
    std::string custId {};
    double balance {0.0};

    // prints account balance
    void showBalance(){
        std::cout << "Account " << accountId
                    << " has balance of: " << balance << "\n";
    }
};


struct Client{

    std::string custId {""};
    std::string passWord {""};
    std::string name {""};
    std::string address {""};
    std::string phone {""};
    std::map<std::string, Account> accounts;

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

    std::string clientsCSV;
    std::string accountsCSV;

    BankDataBase(std::string clientsPath="clients.csv", 
        std::string accountsPath="accounts.csv"){
        clientsCSV = clientsPath;
        accountsCSV = accountsPath;
        readClientsFromDataBase();
        readAccountsFromDataBase();
    }

    private:
        std::string currentUser;
        std::map<std::string, Client> db;
        int nextUnusedUserId {-1};
        int nextUnusedAccountId {-1};

        // creates a new user id
        std::string _createUserId(){
            nextUnusedUserId++;
            return std::to_string(nextUnusedUserId);
        }
        // creates a new accouny id
        std::string _createAccountId(){
            nextUnusedAccountId++;
            return std::to_string(nextUnusedAccountId);
        }

    public:

        // reads all entries from clients.csv
        void readClientsFromDataBase(){

            // structure csv-reader accepts
            csvVector ClientData;
            // 1. read client.csv
            csvRead(clientsCSV, ClientData);

            // 2. loop through client-maps
            for (auto &&mapData : ClientData){
                // 3. convert map to client
                Client client{
                    mapData.find("custId")->second,
                    mapData.find("passWord")->second,
                    mapData.find("name")->second,
                    mapData.find("address")->second,
                    mapData.find("phone")->second,
                };

                // 4. add client to db
                db[client.custId] = client;

                // 5. avoid giving used ids to new clients
                int icustId {std::stoi(client.custId)};
                if (icustId > nextUnusedUserId){
                    nextUnusedUserId = icustId;
                }
            }
        }

       // reads all entries from clients.csv
        void readAccountsFromDataBase(){

            // structure csv-reader accepts
            csvVector AccountData;
            // 1. read accounts.csv
            csvRead(accountsCSV, AccountData);

            // 2. loop through accounts-maps
            for (auto &&mapData : AccountData){

                // 3. convert map to account
                std::string custId {mapData.find("custId")->second};
                std::string accountId {mapData.find("accountId")->second};
                double balance {std::stod(mapData.find("balance")->second)};

                // 4. add account to a client
                Account account {accountId, custId, balance};
                db[custId].accounts[accountId] = account;

                // 5. avoid giving used ids to new accounts
                int iaccId {std::stoi(accountId)};
                if (iaccId > nextUnusedAccountId){
                    nextUnusedAccountId = iaccId;
                }
            }
        }

        // writes a new client to clients.csv
        void writeClientToDataBase(Client& client, char mode='a'){

            // structure csv-writer accepts
            csvVector ClientData;

            // 1. convert client to map
            csvMap clientMap{

                {"custId",   client.custId},
                {"passWord", client.passWord},
                {"name",     client.name},
                {"address",  client.address},
                {"phone",    client.phone}
            };

            // 2. add client-map to vector
            ClientData.push_back(clientMap);

            // 3. write client to file
            csvWrite(clientsCSV, ClientData, mode);
            
        }

        // writes a new account to accounts.csv
        void writeAccountToDataBase(Account& account, char mode='a'){

            // structure csv-writer accepts
            csvVector AccountData;

            // 1. convert account to map
            csvMap accountMap{

                {"custId",    account.custId},
                {"accountId", account.accountId},
                {"balance",   std::to_string(account.balance)},
            };

            // 2. add client-map to vector
            AccountData.push_back(accountMap);

            // 3. write client to file
            csvWrite(accountsCSV, AccountData, mode);
        }


// todo 
// rewrite all data with w mode
        // overwrite clients
        void updateDataBase(){
            for (auto &&cust : db){
                writeClientToDataBase(cust.second, 'w');
                for (auto &&i : cust.second.accounts){
                    writeAccountToDataBase(i.second);
                }
            }
        }

        // returns weather theres a logged user
        bool hasActiveUser(){
            return db.find(currentUser) != db.end();
        }

        // If requested account exists
        bool isExistingAccount(std::string accountId){
            auto accounts {db[currentUser].accounts};
            return accounts.find(accountId) != accounts.end();
        }

        // sets new account balance
        void deposit(){
            Client& user {db[currentUser]};
            std::string accountId {accountIdDialog(user)};
            if(isExistingAccount(accountId)){
                double amount {depositDialog()};
                Account& account {user.accounts[accountId]};
                account.balance += amount;
                account.showBalance();
                continuePrompt();
            }
        }
        // sets new account balance
        void withdraw(){
            Client& user {db[currentUser]};
            std::string accountId {accountIdDialog(user)};
            if(isExistingAccount(accountId)){
                double amount {withdrawDialog()};
                Account& account {user.accounts[accountId]};
                account.balance -= amount;
                account.balance = (account.balance < 0 ) ? 0: account.balance;
                account.showBalance();
                continuePrompt();
            }
        }
        // prints balances of all user accounts
        void checkBalance(){

            auto& accounts {db[currentUser].accounts};
            for (auto it = accounts.begin(); it != accounts.end(); it++) {
                std::cout << "Account " << it->first << " "
                          << "has balance of: " << it->second.balance << " e\n";
            }
            if (accounts.size() == 0){
                std::cout << "You have no accounts, please create one first.\n";
            }
            
            continuePrompt();
        }

        // fill user data via prompts
        void addCustomer(Client user){
            // add userid and add user to database
            currentUser = _createUserId();
            user.custId = currentUser;
            db[currentUser] = user;
            std::cout << "Welcome " << user.name << "!\n\n";
            writeClientToDataBase(user);
            continuePrompt();
        }

        // new account for current user
        void createNewAccount(){
            std::string accountId {_createAccountId()};
            Account account {accountId, currentUser, 0.0};
            Client& user {db[currentUser]};
            user.accounts[accountId] = account;
            writeAccountToDataBase(account);

            std::cout << "Created a new account with id: " << accountId << "\n";
            continuePrompt();
        }

        // login to bank
        bool login(std::string userId, std::string password){
            if(db.find(userId) != db.end()){
                if (db[userId].passWord == password){
                    currentUser = userId;
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


void continuePrompt(){
    char anyKey;
    std::cout << "Continue? (y/n): ";
    while (anyKey != 'y'){
        std::cin >> anyKey;
    }
    system("clear");
}

int optionsDialog(){

    int action {0};
    std::cout << "What would you like to do?\n";
    std::cout << "0: deposit\n1: withdraw\n2: balance\n3: new account\n4: quit\n";
    std::cout << "Please select an action: ";
    std::cin >> action;
    std::cout << "\n";
    system("clear");
    return action;
}


Client userDetailsDialog(){

    Client user {};
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
            break;
        }
        default:return user;
        }
    }
    return user;
}


void createUserDialog(BankDataBase& bankDB){
    char createNewCustomer {'n'}; 
    std::cout << "Create new customer? (y/n): ";
    std::cin >> createNewCustomer;
    system("clear");

    if(createNewCustomer == 'y'){
        Client user {userDetailsDialog()};
        bankDB.addCustomer(user);
    }
}


std::string accountIdDialog(const Client& user){

    int accountId {0};
    std::map<int, std::string> remappedCopy {};

    if(user.accounts.size() == 0){
        std::cout << "You have no accounts, please create one first.:\n\n";
        continuePrompt();
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
        std::cout << "Invalid amount inserted!";
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

void loginDialog(BankDataBase& bankDB){
    std::string passWord {0};
    std::string userId {""};

    std::cout << "Login to use your accounts\n\n";
    std::cout << "Give user ID: ";
    std::cin >> userId;
    
    std::cout << "Give password: ";
    std::cin >> passWord;

    if(bankDB.login(userId, passWord)){
        std::cout << "Successfully logged in!\n\n";
    }
    else{
        std::cout << "Invalid id or password!\n";
    }
    system("clear");
}


bool quitDialog(){
    char doExit {'n'};
    std::cout << "Exit? (y/n): ";
    std::cin >> doExit;
    std::cout << "\n";
    system("clear");
    return doExit == 'y';
}


bool mainDialog(BankDataBase& bankDB){

    int step {0};
    std::cout << "0: Login\n1: Subscribe\n2: Quit\n"
              << "What is it gonna be: ";

    std::cin >> step;
    system("clear");

    switch (step){
        case 0:{
            loginDialog(bankDB);
            break;
        }
        case 1:{
            createUserDialog(bankDB);
            break;
        }
        case 2:{
            if (quitDialog()){
                return true;
            }
        }
        default: break;
    }
    return false;
}



int main(){

    BankDataBase bankDB {};
    
    bool continueTransactions {true};
    while(continueTransactions){

        // main dialog
        if(!bankDB.hasActiveUser()){
            if(mainDialog(bankDB)){
                return 1;
            };
        }
        else {
            // logged in dialog
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