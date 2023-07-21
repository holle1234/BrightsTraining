#include "source/inheritance.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    Parrot parrot = Parrot::create_parrot("pentti");
    std::cout << parrot;
    return 0;
}
