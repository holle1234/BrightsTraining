#include "crtp.h"
#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    //Ex 1.
    Cat* acat = new Cat(1);
    Cat* bcat = new Cat(2);
    Dog* adog = new Dog;
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

    return 0;
}
