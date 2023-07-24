#include "tagged_union.h"
#include <charconv>




bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

 
// Setter
bool Data::set(std::string_view value){

    if (is_int(value)){
        last = TaggedAccess::robot;
        robot = std::stoi(value.data());
    }
    else if (is_float(value)){
        last = TaggedAccess::alien;
        alien = std::stof(value.data());
    }
    else if (!value.empty()){
        last = TaggedAccess::person;
        person = std::tolower(value.data()[0]);
    }
    else return false;

    return true;
}

// Getter
TaggedResult Data::get() const{

    switch (last)
    {
    case TaggedAccess::alien :
        return {std::to_string(alien), true};
    case TaggedAccess::person :
        return {std::string(1, person), true};
    case TaggedAccess::robot :
        return {std::to_string(robot), true};
    case TaggedAccess::not_set :
        return {"class Data: tagged union not set", false};
    default: return {"", false};
    }
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


std::ostream &operator<<(std::ostream &os, const Data &d){
    TaggedResult res = d.get();
    return os << res.value;
}
