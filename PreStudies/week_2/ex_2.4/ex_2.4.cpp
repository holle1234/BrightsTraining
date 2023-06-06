#include "constants.h"
#include <iostream>
#include <cmath>
#include <string>


double getBMI(double w, double h){
    return w / std::pow(h / 100, 2.0);
}

std::string rankBMI(double bmi){
    if (bmi < BMIrank::BMILower)
        return "underweight";
    else if (bmi > BMIrank::BMIUpper)
        return "overweight";
    else
        return "healthy";
}


int main(){
    double weight {};
    double height {};
    double bmi {};
    std::string bmiRank {""};

    char exitProgram {'n'};
    while (exitProgram != 'y'){   
        std::cout << "Enter weight in kg: ";
        std::cin >> weight;

        std::cout << "Enter height in cm: ";
        std::cin >> height;

        bmi = getBMI(weight, height);
        bmiRank = rankBMI(bmi);
        
        std::cout << "Your BMI is: " << bmi << " which is ranked as " << bmiRank << std::endl;
        std::cout << "Close Program? (y/n) ";
        std::cin >> exitProgram;
        std::cout << std::endl;
    }

    return 0;
}