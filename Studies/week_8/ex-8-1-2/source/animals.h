#if !defined(ANIMALS)
#define ANIMALS

#include <string>
#include <iostream>


class Animal
{
public:
    std::string noise {"generic animal noises"};
    const std::string type {"animal"};
    virtual const std::string speak(){return noise + " from " + type;};
    virtual void greet(std::string&& greeting){};
    Animal(std::string animaltype) : type(animaltype) {}
    Animal() = default;
    ~Animal(){}
};


class Parrot : public Animal
{
private:
    std::string mock;
public:
    std::string noise {"I am a parrot"};
    std::string type {"parrot"};
    const std::string speak() override;
    void greet(std::string&& greeting) final;
    Parrot(){}
    ~Parrot(){}
};

class Dog : public Animal
{
public:
    std::string noise {"I am a dog"};
    std::string type {"dog"};
    const std::string speak() override;
    void greet(std::string&& greeting) final {};
    Dog(/* args */) {}
    ~Dog() {}
};


class Cat : public Animal
{
public:
    std::string noise {"I am a cat"};
    std::string type {"cat"};
    const std::string speak() override;
    void greet(std::string&& greeting) final {};
    Cat(/* args */) {}
    ~Cat() {}
};

#endif // ANIMALS
