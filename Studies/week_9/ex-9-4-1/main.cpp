#include "monadic.h"
#include "variant.h"
#include <iostream>
#include <vector>
#include <variant>



int main(int argc, char const *argv[])
{
    // Ex 1.
    variant::Object obj;
    obj.set("human");
    auto f = obj.get<std::string>();
    std::cout << f << '\n';  

    // Ex 2.
    using AnimalType = std::variant<Animal, Cat, Dog, Parrot>;
    std::vector<AnimalType> animals;

    animals.push_back(AnimalType(Dog()));
    animals.push_back(AnimalType(Cat()));
    animals.push_back(AnimalType(Parrot()));
    animals.push_back(AnimalType(Animal()));
    
    
    for (auto &&i : animals){
        std::cout << std::visit([&](auto& arg){
            return arg.get_type();}, i) << '\n';
    }

    return 0;
}
