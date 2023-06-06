#include <iostream>


int main(){
    long int finnId {};

    char exitProgram {'n'};
    while (exitProgram != 'y'){   
        std::cout << "Enter finnish person id: ";
        std::cin >> finnId;

        std::cout << "You are a " << ((finnId % 2 == 0) ? "female" : "male") << std::endl;
        
        std::cout << "Close Program? (y/n) ";
        std::cin >> exitProgram;
        std::cout << std::endl;
    }

    return 0;
}