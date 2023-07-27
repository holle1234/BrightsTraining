#if !defined(CRTP)
#define CRTP

#include <string>


// Base class
class Animal
{
public:
    std::string noise {"animal"};
    std::string name  {""};

    virtual std::string make_noise(){return noise;}
    virtual std::string get_name(){return name;}
    virtual bool likes_to_swim(){return false;}
    virtual bool eat_mouse(){return false;}

    Animal() {}
    ~Animal() {}
};


/* This class is not ever directly interacted with
- Makes base class pointer arrays work
- Override base class functions (with final)
- Makes common functionality to all derived classes (get_name())
  */
template <typename T>
class AnimalCrtp : public Animal
{

private:
    const T* derived_type = static_cast<T*>(this);
public:
    
    // common to all animals
    std::string make_noise() override {
        return derived_type->noise;
    }
    std::string get_name() final {
        return derived_type->name;
    }
};



class Cat : public AnimalCrtp<Cat>
{
public:
    std::string name  {"-c"};
    std::string noise {"miauu"};
    Cat(std::string&& name) : name(name) {}
    ~Cat(){}

    std::string make_noise() final {
        return "Cat overrides AnimalCrtp's make_noise() function because it was not 'final' | - mouuuu";
    }

    bool eat_mouse() final {return true;}
};


class Dog : public AnimalCrtp<Dog>
{
public:
    std::string name  {"-d"};
    std::string noise {"-vuff"};
    Dog(std::string&& name) : name(name){}
    ~Dog() {}

    bool likes_to_swim() final {return true;}
};


#endif // CRTP
