#include "inheritance.h"
#include <string>
#include <memory>


std::ostream &operator<<(std::ostream &os, const Eyes &e)
{
    return os << e.eysight;
}

std::ostream &operator<<(std::ostream &os, const Wings &w)
{
    return os << std::boolalpha << w.flyable;
}

// not able get derived class member variables cause its not virtual
std::ostream &operator<<(std::ostream &os, const Animal &a)
{

    os << "Animal type ";
    if (a.animal_type == AnimalType::dog){
        os << "Dog: ";
    }
    else if (a.animal_type == AnimalType::parrot){
        os << "Parrot: ";
    }
    else if (a.animal_type == AnimalType::penquine){
        os << "Penquine: ";
    }
    
    os << "name: " << a.name << " ";
    os << "eye sight: " << a.eyes << " ";
    os << "can fly: " << std::boolalpha << a.can_fly << " ";
    os << "says : " << a.speach;
    return os;
}


// Spawns a factory object that can create only certain type of objects
God God::spawn(AnimalType creator_type){
    return God {creator_type};
}

// interaction method for creating objects
auto God::create_animal(std::string name) -> std::unique_ptr<Animal>{

    if (creator_type == AnimalType::dog){
        return std::make_unique<Dog>(name);
    }
    else if (creator_type == AnimalType::parrot){
        return std::make_unique<Parrot>(name);
    }
    else if (creator_type == AnimalType::penquine){
        return std::make_unique<Penquine>(name);
    }

    return std::make_unique<UnknownAnimal>(name);
}

std::string& Parrot::speak()
{
    if(last_greeting.empty()){
        return Animal::speak();
    }
    return Parrot::last_greeting;
}

void Parrot::greet(std::string greeting)
{
    this->last_greeting = greeting;
}
