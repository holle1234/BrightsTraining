#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "dialogs.h"
#include "structs.h"


enum class Actions{
    deposit,
    withdraw,
    balanceCheck,
    accoutCreation,
    quit  
};


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
