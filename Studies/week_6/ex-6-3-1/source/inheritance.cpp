#include "inheritance.h"
#include <string>
#include <memory>


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

// All derived classes can use this
std::ostream &operator<<(std::ostream &os, Animal &a){
    return a.repr(os);
}

// Common to all derived classes of Animal
std::ostream& Animal::repr(std::ostream &os){
    os << "Animal type: Animal ";
    os << "Name: " << this->name  << " ";
    os << "Eye sight: " << this->eysight << " ";
    os << "Says: '" << this->speach << "'";
    return os;
}
// Common to all derived classes of Bird
std::ostream& Bird::repr(std::ostream &os){
    os << "Animal type: Bird ";
    os << "Name: " << this->name << " ";
    os << "Eye sight: " << this->eysight << " ";
    os << "Says: '" << this->speach << "'";
    return os;
}

// Parrot specific implentation
std::ostream& Parrot::repr(std::ostream &os){
    os << "Animal type: Parrot ";
    os << "Name: " << this->name << " ";
    os << "Eye sight: " << this->eysight << " ";
    os << "Says: '" << this->speach << "'";
    return os;
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

void Dog::virtual_print()
{
    std::cout << "virtual_print() from Dog class. "
                << "Access to Dog 'isagoodboy' bool member: " << isagoodboy << "\n";
}

void Dog::test_print()
{
    std::cout << "test_print() from Dog class\n";
}

void Dog::call_base_method()
{
    std::cout << "Dog calling Animal class test_print() using 'Animal::'\n";
    Animal::test_print();
}

