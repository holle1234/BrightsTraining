#include "source/inheritance.h"
#include <iostream>



int main(int argc, char const *argv[])
{

    // Base class and Derived class has identically named functions
    // Dog class hides base class function. 

    Dog dogtest {"fifi"};
    Animal animal;
    animal.test_print(); // prints: test_print() from Animal class
    dogtest.test_print(); // prints: test_print() from Dog class

    // calls method from base class from the child class
    dogtest.call_base_method(); // prints: Dog calling Animal class test_print() using 'Animal::'
    std::cout << "\n\n";        //         test_print() from Animal class

    // Creating a factory class that returns different types of Animal subclasses.
    // In this example factory is set to return only one type based on spawn() argument.
    // All the created objects are pointers of Animal pointing to a subclass object. 
    // Any variables defined in the subclass are now unavailable.

    God dog_god = God::spawn(AnimalType::dog);
    God parrot_god = God::spawn(AnimalType::parrot);
    God penquine_god = God::spawn(AnimalType::penquine);

    // demo dog greeting
    auto dog = dog_god.create_animal("vuffe");

    // this calls base class implementation because test_print is not virtual function.
    // object does not know about subclass implementation
    dog->test_print();  //prints test_print() from Animal class

    // only virtual functions of a Dog class are available.
    // they themselves can access Dogs internal variables though.
    dog->virtual_print(); //prints virtual_print() from Dog class. Access to Dog 'isagoodboy' bool member: 1

    std::cout << "\n\n";
    dog->greet("hello!");
    std::cout << "dog says " << dog->speak() << "\n";

    // demo parrot before and after greeting
    auto parrot = parrot_god.create_animal("pena");
    std::cout << "parrot says " << parrot->speak() << "\n";

    std::cout << "greeting parrot with 'hello!'\n";
    parrot->greet("hello!");
    std::cout << "parrot responds " << parrot->speak() << "\n";

    // demo pengquine greeting
    auto penqu = penquine_god.create_animal("pingu");
    std::cout << "penquine says " << penqu->speak() << "\n";

    // print object members
    std::cout << animal << "\n";
    std::cout << *dog << "\n";
    std::cout << *parrot << "\n";
    std::cout << *penqu << "\n";


    return 0;
}
