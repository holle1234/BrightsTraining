#if !defined(TRANSA)
#define TRANSA

#include <string>
#include <vector>


// Alias for clarity
using TransActionsVector = std::vector<double>;


struct Transaction {
    // stores transactions (-/+)
    TransActionsVector transactions;
};

double preprocess_withdraw(double amount);

double preprocess_deposit(double amount);

void withdraw(double amount, Transaction &tr);

void deposit(double amount, Transaction &tr);

void viewHistory(Transaction &tr);

double calculateTotalExpenses(Transaction tr);

void viewTotalExpenses(double total);


namespace logger{

    void writeTransactions(TransActionsVector& t, std::string filename);

    void readTransactions(std::string filename, TransActionsVector &dest);
}

#endif // TRANSA

