#include "source/inheritance.h"
#include <iostream>


/* 
SAMPLE PRINT:

dog says wufwuf
parrot says kruakszz
parrot says hello!
penquine says g'day..
Animal type Dog: name: vuffe eye sight: 0 can fly: false says : wufwuf
Animal type Parrot: name: pena eye sight: 5 can fly: true says : kruakszz
Animal type Penquine: name: pingu eye sight: 10 can fly: false says : g'day..


 */


int main(int argc, char const *argv[])
{
    God dog_god = God::spawn(AnimalType::dog);
    God parrot_god = God::spawn(AnimalType::parrot);
    God penquine_god = God::spawn(AnimalType::penquine);

    // demo dog greeting
    auto dog = dog_god.create_animal("vuffe");
    dog->greet("hello!");
    std::cout << "dog says " << dog->speak() << "\n";

    // demo parrot before and after greeting
    auto parrot = parrot_god.create_animal("pena");
    std::cout << "parrot says " << parrot->speak() << "\n";

    parrot->greet("hello!");
    std::cout << "parrot says " << parrot->speak() << "\n";

    // demo pengquine greeting
    auto penqu = penquine_god.create_animal("pingu");
    std::cout << "penquine says " << penqu->speak() << "\n";

    // print object members
    std::cout << *dog << "\n";
    std::cout << *parrot << "\n";
    std::cout << *penqu << "\n";


    return 0;
}
