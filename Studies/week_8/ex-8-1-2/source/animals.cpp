#include "animals.h"

const std::string Parrot::speak()
{
    if(!this->mock.empty()){
        return this->mock;
    } return this->noise + " skruaatz";
}

void Parrot::greet(std::string &&greeting)
{
    mock = noise + " '" + greeting + "'";
}

const std::string Dog::speak()
{
    return this->noise + " vuf";
}

const std::string Cat::speak()
{
    return this->noise + " miauu";
}
