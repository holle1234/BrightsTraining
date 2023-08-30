#if !defined(CRTP)
#define CRTP

#include <iostream>
#include <ostream>
#include <typeinfo>


// Base class
class Animal
{
public:
    std::string noise {"animal"};
    Animal() {}
    ~Animal() {}
    virtual void make_noise(){std::cout << noise << "\n";};
};

template <typename T>
class AnimalType
{

public:
    void type_of(){
        std::cout << "Object type of: " << typeid(T).name() << "\n";
    }
};


template <typename T>
class AnimalCrtp : public Animal
{

private:
    T* derived_type = static_cast<T*>(this);
public:
    
    void make_noise() override {
        std::cout << derived_type->noise << "\n";
    }

    bool operator==(const T& other) const{
        T other_c = static_cast<T>(other);
        return !(((*derived_type) < other_c) || (other_c < (*derived_type)));
    }
};



class Cat : public AnimalCrtp<Cat>, public AnimalType<Cat>
{
public:
    std::string noise {"miauu"};
    int value;
    Cat(int value=0) : value(value) {}
    ~Cat() {}

    bool operator<(const Cat& other){
        return value < other.value;
    }
};


class Dog : public AnimalCrtp<Dog>, public AnimalType<Dog>
{
public:
    std::string noise {"vuff"};
    int value;
    Dog(int value = 0) : value(value) {}
    ~Dog() {}

    bool operator<(const Cat& other){
        return value < other.value;
    }

};


#endif // CRTP
