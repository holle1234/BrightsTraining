#include <string>
#include <ostream>



enum class AnimalType {dog, parrot};



class God
{
private:
    const AnimalType creator_type {AnimalType::dog};
    God(AnimalType creator_type) : creator_type(creator_type) {};
    God() = default;

public:
    static God spawn(AnimalType creator_type);
    Animal create_animal(std::string name);
};




class Animal
{
public:
    AnimalType animal_type;
    bool can_fly;
    int eye_sight;
    std::string speach;
    std::string name;

    Animal() {}
    ~Animal() {}
    void speak();
    friend std::ostream& operator<<(std::ostream& os, const Animal& p);

};

class Dog
{
public:
    bool isagoodboy {true};
    std::string speach {"wuf"};
    Dog(bool goodness = true) : isagoodboy(goodness) {}
    ~Dog() {}
};

class Parrot
{
public:
    Parrot() {}
    ~Parrot() {}
    void speak(std::string repeat);
};

class Bird
{
public:
    bool can_fly {false};
    Bird(bool can_fly) : can_fly(can_fly) {}
    ~Bird() {}
};

class Eyes
{
public:
    int eysight {10};
    Eyes(int vision) : eysight(vision) {}
    ~Eyes() {}
};

class Wings
{
public:
    bool flyable {false};
    Wings(bool can_fly) : flyable(can_fly) {}
    ~Wings() {}
};