#include <iostream>

double getTotalPriceSingleVisits(double visits, double price){
    return visits * price;
}


int main(){
    double priceMembership {0.0};
    double priceSingleVisit {0.0};
    double plannedVisits {0.0};
    double totalPriceSingle {0.0};
    const double epsilon {0.01}; // smallest meaningfull amount of currency

    char terminateProgram {'n'};
    while (terminateProgram != 'y'){
        std::cout << "Price of membership card? ";
        std::cin >> priceMembership;

        std::cout << "Price of single visit? ";
        std::cin >> priceSingleVisit;

        std::cout << "How many times you plan to go? ";
        std::cin >> plannedVisits;

        totalPriceSingle = getTotalPriceSingleVisits(plannedVisits, priceSingleVisit);

        if (std::abs(totalPriceSingle - priceMembership) < epsilon)
            std::cout << "Cost of membership is equal to pay per use!" << std::endl;
        else if (totalPriceSingle < priceMembership)
            std::cout << "Pay per visit is cheaper!" << std::endl;
        else if (priceMembership < totalPriceSingle)
            std::cout << "Membership is cheaper!" << std::endl;
            
        std::cout << "Close program? (y/n) ";
        std::cin >> terminateProgram;
        std::cout << std::endl;
    }


    return 0;
}