#include <string>
#include <ostream>
#include <memory>


#if !defined(INHERITANCE)
#define INHERITANCE



enum class AnimalType {dog, parrot, penquine, unknown};



class Eyes
{
public:
    int eysight {10};
    Eyes(int vision) : eysight(vision) {}
    Eyes() : eysight(10) {}
    ~Eyes() {}
    friend std::ostream& operator<<(std::ostream& os, const Eyes& e);
};

class Wings
{
public:
    bool flyable {false};
    Wings(bool can_fly) : flyable(can_fly) {}
    Wings() : flyable(false){}
    ~Wings() {}
    friend std::ostream& operator<<(std::ostream& os, const Wings& w);
};



class Animal
{


public:
    AnimalType animal_type;

    bool can_fly;
    Eyes eyes;
    std::string speach;
    std::string name;

    Animal(AnimalType animal) : animal_type(animal) {}
    ~Animal() {}

    friend std::ostream& operator<<(std::ostream& os, const Animal& p);
    virtual std::string& speak(){return this->speach;};
    virtual void greet(std::string greeting){};
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


class UnknownAnimal : public Animal
{
public:
    UnknownAnimal(std::string name) : Animal(AnimalType::unknown){
        this->name = name;
        this->eyes = Eyes(0);
        this->speach = "--";
        this->can_fly = false;
    }
    ~UnknownAnimal() {}
};

class Dog : public Animal
{
public:
    bool isagoodboy {true};

    Dog(std::string name, bool goooddog = true) : isagoodboy(goooddog), Animal(AnimalType::dog){
        this->name = name;
        this->eyes = Eyes(0); // blind dog
        this->speach = "wufwuf";
        this->can_fly = false;
    }
    ~Dog() {}
};


class Bird : public Animal
{
public:
    Wings wings;
    Bird(AnimalType animal) : Animal(animal) {}
    ~Bird() {}
};


class Parrot : public Bird
{
private:
    std::string last_greeting;

public:
    Parrot(std::string name) : Bird(AnimalType::parrot) {
        this->name = name;
        this->eyes = Eyes(5);
        this->speach = "kruakszz";
        this->can_fly = true;
        this->wings = Wings(true);
    }
    ~Parrot() {}

    void greet(std::string greeting) override;
    std::string& speak() override;

};


class Penquine : public Bird
{

public:

    Penquine(std::string name) : Bird(AnimalType::penquine) {
        this->name = name;
        this->eyes = Eyes(10);
        this->speach = "g'day..";
        this->can_fly = false;
        this->wings = Wings(false);
    }
    ~Penquine() {}

};



#endif // INHERITANCE