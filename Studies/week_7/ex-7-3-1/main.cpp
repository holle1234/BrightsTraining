#include "crtp.h"
#include <iostream>
#include <vector>
#include <memory>


int main(int argc, char const *argv[])
{
    //Ex 1.
    std::unique_ptr<Cat> acat = std::make_unique<Cat>(1);
    std::unique_ptr<Cat> bcat = std::make_unique<Cat>(2);
    std::unique_ptr<Dog> adog = std::make_unique<Dog>(1);
    std::cout << ((*acat) == (*bcat)) << "\n";


    std::vector<Animal*> animals {new Cat, new Dog};
    for (auto &&i : animals){
        // Virtual make_noise() is declared in class Animal and inherited by AnimalCRTP.
        // It is overridden there so it is common to all classes inheriting from it.
        i->make_noise();

    }

    // type_of() is declared in class AnimalType that gets inherited directely by the Cat and Dog classes.
    // It is not available to base class (Animal) pointer type.

    acat->type_of();
    adog->type_of();

    for (auto &&i : animals){
        delete i;
    }
    
    return 0;
}
