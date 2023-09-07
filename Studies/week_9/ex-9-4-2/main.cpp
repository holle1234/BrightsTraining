#include "factory.hpp"
#include <iostream>
#include <optional>
#include <string>
#include "expected.hpp"


void printer(std::optional<Factory>& fac){
    if(fac.has_value()){
        std::cout << fac.value() << '\n';
    }
    else std::cout << "Empty optional \n";
}

void printer(tl::expected<Factory, std::string> & fac){
    if(fac.has_value()){
        std::cout << fac.value() << '\n';
    }
    else std::cout << fac.error() << '\n';
}


int main(int argc, char const *argv[])
{
    // Ex 1.
    std::optional<Factory> fac0 = Factory::create(0);
    std::optional<Factory> fac1 = Factory::create(1);
    printer(fac0);
    printer(fac1);


    // Ex 2.
    auto fac3 = Factory::create_exp(0);
    auto fac4 = Factory::create_exp(1);
    printer(fac3);
    printer(fac4);

    return 0;
}
