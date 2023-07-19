#include "tagged_union.h"
#include <string>


Data::Data(int value){
    last = TaggedAccess::robot;
    robot = value;
}

Data::Data(char value){
    last = TaggedAccess::person;
    person = value;
}

Data::Data(float value){
    last = TaggedAccess::alien;
    alien = value;
}

Data::Data(double value){
    last = TaggedAccess::alien;
    alien = static_cast<float>(value);
}

Data::Data(std::string value){
    last = TaggedAccess::person;
    if(value.size() > 0){
        person = std::tolower(value[0]);
    }
}


// Getters
char Data::get(char value){
    if (last == TaggedAccess::person){
        value = person;
    }
    return value;
}

int Data::get(int value){
    if (last == TaggedAccess::robot){
        value = robot;
    }
    return value;
}

float Data::get(float value){
    if (last == TaggedAccess::alien){
        value = alien;
    }
    return value;
}


char Data::type(){
    return TaggedAccess_to_char(last);
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