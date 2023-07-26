#include "printf.h"
#include <iostream>
#include <string>


int main(int argc, char const *argv[])

{
    std::string a = {"lol"};
    auto &b = a;

    std::cout << std::boolalpha << check_format(print_formats[0], 'a', 'b') << "\n"; // char
    std::cout << std::boolalpha << check_format(print_formats[1], 0, 1L, 1LU) << "\n"; // integer
    std::cout << std::boolalpha << check_format(print_formats[2], 1.0f, 1.0) << "\n"; // float
    std::cout << std::boolalpha << check_format(print_formats[3], a, b) << "\n"; // string
    std::cout << std::boolalpha << check_format(print_formats[4], 1U, 2LU) << "\n"; // unsigned int  

    Example ex {2,3,3,5};
    std::cout << ex.parameter_count();


    return 0;
}
