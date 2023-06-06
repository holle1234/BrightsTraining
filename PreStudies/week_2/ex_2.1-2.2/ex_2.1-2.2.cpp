#include "constants.h"
#include <iostream>
#include <math.h>
#include <string>


double getTotalConsumption(double distkm, double consumption100km){
    double consumption {consumption100km * (distkm / 100)};
    return consumption;

}

double getFuelPrice(std::string fuelType){
    double cost {-1.0};

    if (fuelType == "petrol")
        cost = Fuelprices::pricePetrol;
    else if (fuelType == "diesel")
        cost = Fuelprices::priceDiesel;
    else if (fuelType == "electric")
        cost = Fuelprices::pricekWh;
    return cost;

}

double getConsumptionCost(double totalFuel, double cost){
    return totalFuel * cost;
    
}

int main(){
    double distance {};
    double consumption {};
    double fuelPrice {};
    std::string fuelType {};
    double totalFuel {};
    double cost {};
    
    char continueProgram {'y'};
    int programStatus {0};

    while (continueProgram != 'n'){

        switch (programStatus){
            case 0:
                std::cout << "Enter fuel type (diesel/petrol/electric): ";
                std::cin >> fuelType;
                fuelPrice = getFuelPrice(fuelType);

                if (fuelPrice < 0)
                    std::cout << "Invalid fueltype entered! Try again.. " << std::endl;
                else 
                    programStatus = 1;
                break;
            
            case 1:
                std::cout << "Enter distance in km: ";
                std::cin >> distance;
                programStatus = 2;
                break;
            
            case 2:
                std::cout << "Enter consumption in per 100km: ";
                std::cin >> consumption;
                programStatus = 3;
                break;
            
            case 3:
                totalFuel = getTotalConsumption(distance, consumption);
                cost = getConsumptionCost(totalFuel, fuelPrice);
                std::cout << "Consumption cost: " << cost << std::endl;
                std::cout << "Calculate again? (y/n): ";
                std::cin >> continueProgram;
                if (continueProgram == 'y')
                    programStatus = 0;
                break;

            default:
                break;
        }
              
    }


    return 0;
}
