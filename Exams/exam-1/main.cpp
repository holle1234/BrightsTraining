#include "transactions/finance_tracker.h"
#include <iostream>
#include <string>



int main(int argc, char const *argv[])
{
    
    Transaction t;
    deposit(10, t);
    withdraw(15, t);
    viewHistory(t);
    auto sum = calculateTotalExpenses(t);
    viewTotalExpenses(sum);

    logger::writeTransactions(t.transactions, "test.log");
    t.transactions.clear();
    logger::readTransactions("test.log", t.transactions);

    for (auto &&i : t.transactions){
        std::cout << i << "\n";
    }
    
}