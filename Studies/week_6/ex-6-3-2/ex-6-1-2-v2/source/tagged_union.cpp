#include "tagged_union.h"


// Setters
void Data::set(char value){
    person = value;
    last = TaggedAccess::person;
}

void Data::set(int value){
    robot = value;
    last = TaggedAccess::robot;
}

void Data::set(float value){
    alien = value;
    last = TaggedAccess::alien;
}

// Getters
void Data::get(char& value, bool& status){
    if (last == TaggedAccess::person){
        value = person;
        status = true;
    }else status = false;
}

void Data::get(int& value, bool& status){
    if (last == TaggedAccess::robot){
        value = robot;
        status = true;
    }else status = false;
}

void Data::get(float& value, bool& status){
    if (last == TaggedAccess::alien){
        value = alien;
        status = true;
    }else status = false;
}


char Data::type(){
    return TaggedAccess_to_char(last);
}

bool Data::is_set(){
    return last == TaggedAccess::not_set;
}


char Data::TaggedAccess_to_char(TaggedAccess t){
    switch (t)
    {
    case TaggedAccess::alien :
        return 'f';
    case TaggedAccess::person :
        return 'c';
    case TaggedAccess::robot :
        return 'i';
    }
    return ' ';
}