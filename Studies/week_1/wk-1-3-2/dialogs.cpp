#include <iostream>
#include "dialogs.h"
#include "structs.h"



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
        std::cout << "Successfully logged in!\n\n";}
    else{
        std::cout << "Invalid id or password!\n";
        createUserDialog(bankDB);}
}



int optionsDialog(){

    int action {0};
    std::cout << "What would you like to do?\n";
    std::cout << "0: deposit\n1: withdraw\n2: balance\n3: new account\n4: quit\n";
    std::cout << "Please select an action: ";
    std::cin >> action;
    std::cout << "\n";
    return action;
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