#include "source/tagged_union.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    Data obj;
    std::cout << obj << "\n";

    obj.set("1");
    std::cout << obj << "\n";

    obj.set("p");
    std::cout << obj << "\n";

    obj.set("2.0");
    std::cout << obj << "\n";

    return 0;
}
