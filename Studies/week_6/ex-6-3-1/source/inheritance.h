#include <string>
#include <ostream>
#include <memory>
#include <iostream>

#if !defined(INHERITANCE)
#define INHERITANCE



enum class AnimalType {dog, parrot, penquine, unknown};



class Eyes
{
public:
    int eysight {10};
    Eyes(int vision) : eysight(vision) {std::cout << "Created Eyes\n";}
    Eyes() : eysight(10) {}
    ~Eyes() {std::cout << "Destroyed Eyes\n";}
};

class Wings
{
public:
    bool flyable {false};
    Wings(bool can_fly) : flyable(can_fly) {std::cout << "Created Wings\n";}
    Wings() : flyable(false){}
    ~Wings() {std::cout << "Destroyed Wings\n";}
};



class Animal : public Eyes
{
public:
    AnimalType animal_type;
    std::string speach;
    std::string name;

    Animal(AnimalType animal) : animal_type(animal) {}
    Animal() = default;
    ~Animal() {}

    // friend functions or operator<< cant be overriden.
    // We can make a virtual function that is called in the friend
    friend std::ostream& operator<<(std::ostream& os, Animal& a);
    virtual std::ostream&  repr(std::ostream& os);

    virtual std::string& speak(){return this->speach;};
    virtual void greet(std::string greeting){};

    void test_print(){std::cout << "test_print() from Animal class\n";}
    virtual void virtual_print(){"virtual_print() from Animal class\n";}
};


class God
{
private:
    const AnimalType creator_type {AnimalType::dog};
    God(AnimalType creator_type) : creator_type(creator_type) {};
    God() = default;

public:
    static God spawn(AnimalType creator_type);
    std::unique_ptr<Animal> create_animal(std::string name);
};


// Base class for all the bird types
class Bird : public Animal, public Wings
{
public:
    Bird(AnimalType animal, bool can_fly=true) : Animal(animal), Wings(can_fly){}
    ~Bird() {}

    std::ostream&  repr(std::ostream& os) override;
};


class Parrot : public Bird
{
private:
    std::string last_greeting;

public:
    Parrot(std::string name) : Bird(AnimalType::parrot, true) {
        this->name = name;
        this->eysight = 5;
        this->speach = "kruakszz";
    }
    ~Parrot() {}

    std::ostream&  repr(std::ostream& os) override;
    void greet(std::string greeting) override;
    std::string& speak() override;
};


class Penquine : public Bird
{

public:

    Penquine(std::string name) : Bird(AnimalType::penquine, false) {
        this->name = name;
        this->eysight = 10;
        this->speach = "g'day..";
    }
    ~Penquine() {}

};

class UnknownAnimal : public Animal
{
public:
    UnknownAnimal(std::string name) : Animal(AnimalType::unknown){
        this->name = name;
        this->eysight = 0;
        this->speach = "--";
    }
    ~UnknownAnimal() {}
};

class Dog : public Animal
{
public:

    bool isagoodboy {true};

    void virtual_print() override;
    void test_print();
    void call_base_method();

    Dog(std::string name, bool goooddog = true) : isagoodboy(goooddog), Animal(AnimalType::dog){
        this->name = name;
        this->eysight = 5;
        this->speach = "wufwuf";
    }
    ~Dog() {}
};




#endif // INHERITANCE