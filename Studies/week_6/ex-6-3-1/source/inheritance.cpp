#include "inheritance.h"
#include <string>




std::ostream &operator<<(std::ostream &os, const Animal &a){

    os << "Animal type ";
    if (a.animal_type == AnimalType::dog){
        os << "Dog: ";
    }
    else if (a.animal_type == AnimalType::parrot){
        os << "Parrot: ";
    }
    
    os << "name: " << a.name << " ";
    os << "eye sight: " << a.eye_sight << " ";
    os << "can fly: " << std::boolalpha << a.can_fly << " ";
    os << "says : " << a.speach;
    return os;
}

// Spawns a factory object that can create only certain type of objects
God God::spawn(AnimalType creator_type){
    return God {creator_type};
}

// interaction method for creating objects
Animal God::create_animal(std::string name){
    if (creator_type == AnimalType::dog){
        return;
    }
    else if (creator_type == AnimalType::parrot){
        return;
    }
}
