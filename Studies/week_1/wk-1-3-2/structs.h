#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>


#include "dialogs.h"




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

#endif