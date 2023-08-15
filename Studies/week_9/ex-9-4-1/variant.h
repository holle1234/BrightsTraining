#if !defined(VARIANT)
#define VARIANT

#include <string>


class Animal
{
public:
    Animal() {}
    ~Animal() {}
    std::string type {"animal"};
    std::string& get_type(){return type;}
};


class Dog
{
public:
    Dog() {}
    ~Dog() {}
    std::string type {"dog"};
    std::string& get_type(){return type;}
};


class Cat
{
public:
    Cat() {}
    ~Cat() {}
    std::string type {"cat"};
    std::string& get_type(){return type;}
};


class Parrot
{
public:
    Parrot() {}
    ~Parrot() {}
    std::string type {"parrot"};
    std::string& get_type(){return type;}
};


#endif // VARIANT
