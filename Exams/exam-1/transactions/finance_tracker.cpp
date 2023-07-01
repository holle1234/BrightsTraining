#include "finance_tracker.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;


namespace logger {

    void writeTransactions(TransActionsVector& t, std::string filename){
        std::fstream file;
        file.open(filename, std::ios::app);

        if (file.is_open()){
            for (auto &&i : t){
                file << i << "\n";
            }
        }
        
        file.close();
    }

    void readTransactions(std::string filename, TransActionsVector& dest){

        std::fstream file;
        if (!fs::exists(filename)){
            return;
        }
        
        file.open(filename, std::ios::in);

        if (!file.is_open()){
            return;
        }

        std::string temp;
        while (std::getline(file, temp)){
            try{
                dest.push_back(std::stod(temp));
            }
            catch(const std::invalid_argument& e){
                throw std::invalid_argument("Cant convert string '" + temp + "' to double\n");
            }
            
        }

        file.close();
    }


};

double preprocess_withdraw(double amount){

    if (amount > 0){
        amount *= -1;
    }
    return amount;
}

double preprocess_deposit(double amount){
    if (amount < 0){
        amount *= -1;
    }
    return amount;
}



void withdraw(double amount, Transaction& tr){
    amount = preprocess_withdraw(amount);
    tr.transactions.push_back(amount);
}

void deposit(double amount, Transaction& tr){
    amount = preprocess_deposit(amount);
    tr.transactions.push_back(amount);
}




void viewHistory(Transaction& tr){
    for (auto &&action : tr.transactions){
        if (action < 0){
            std::cout << "User spend " << std::fixed
                      << std::setprecision(3) << std::abs(action);
        }
        else{
            std::cout << "User gained " << std::fixed
                      << std::setprecision(2) << std::abs(action);
        }
    }
    
}

double calculateTotalExpenses(Transaction tr){
    auto &trVect = tr.transactions;
    double sum = std::accumulate(trVect.begin(), trVect.end(), 0);
    return sum;
}

void viewTotalExpenses(double total){
    std::cout << "Total expenses are: "<< std::setprecision(3)  << total;
}