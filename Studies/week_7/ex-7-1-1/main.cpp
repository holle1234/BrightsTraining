#include "constexpr_decay.h"
#include <iostream>
#include <string>
#include <vector>



int main(int argc, char const *argv[])
{
    const std::vector<std::string> a;
    std::vector<std::string> b;
    std::vector<int> c;

    // ex-1
    std::cout << std::boolalpha << is_same_type<int, int>; // false
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type<int, const int>; // true
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type<int, float>; // false
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type<int, int*>; // true
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type<int, int&>; // false
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type<int, int&&>; // true
    std::cout << "\n\n";

    // ex-2
    std::cout << std::boolalpha << can_decay<const int*&>; // true
    std::cout << "\n";
    std::cout << std::boolalpha << can_decay<const int*>; // false

    return 0;
}
