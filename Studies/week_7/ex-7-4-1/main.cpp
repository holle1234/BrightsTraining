#include "crtp.h"
#include <iostream>
#include <vector>


void free_function(Animal& ref){
    std::cout << "get name: " << ref.get_name() << "\n";
    std::cout << "noise: " << ref.make_noise() << " ";
    std::cout << "eat mouse: " << ref.eat_mouse() << " ";
    std::cout << "swim: " << ref.likes_to_swim() << "\n";
}


int main(int argc, char const *argv[])
{

    Dog d {"dog"};
    Cat c {"cat"};

    std::cout << "Pure References\n";
    free_function(d);
    free_function(c);
    std::cout << "\n";

    std::cout << "Vector Pure References\n";
    // Dog and Cat behave like Animal class
    std::vector<Animal> animals1 {Cat("cat"),Dog("dog")};
    for (auto &&i : animals1){
        free_function(i);
    } std::cout << "\n";


    std::cout << "Vector Pointer References\n";
    // With pointers Cat and Dog can function as their own type
    std::vector<Animal*> animals2 {new Cat("cat"), new Dog("dog")};
    for (auto &&i : animals2){
        free_function(*i);
    }

    return 0;
}
