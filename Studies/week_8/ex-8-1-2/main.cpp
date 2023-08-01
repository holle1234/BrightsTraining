#include "source/animals.h"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>


/* 
Dynamic polymorphisim is used because the order and count of needed objects is not known at compile time.
Vector of tagged unions can be used but it might be too easy to overwrite them by accident.
It may also become cumbersome to set up and handle getters and setter for multiple classes.

 */

int main(int argc, char const *argv[])
{
    std::fstream reader;
    reader.open("animals.txt", std::ios_base::in);
    std::string row;

    std::vector<std::unique_ptr<Animal>> animal_vector;
    while (std::getline(reader, row))
    {
        std::unique_ptr<Animal> animal;

        if (row == "Parrot"){
            animal = std::make_unique<Parrot>();
        }
        else if (row == "Cat"){
            animal = std::make_unique<Cat>();
        }
        else if (row == "Dog"){
            animal = std::make_unique<Dog>();
        }
        else
            animal = std::make_unique<Animal>(row);
        
        animal_vector.push_back(std::move(animal));
    }

    for (auto &&i : animal_vector){
        i->greet("hello you!");
        std::cout << i->speak() << "\n";
    }
    
    return 0;
}
