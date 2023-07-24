#include "constexpr_decay.h"
#include <iostream>
#include <string>
#include <vector>



int main(int argc, char const *argv[])
{
    std::vector<std::string> a;
    std::vector<std::string> b;
    std::vector<int> c;

    int v = {0};
    int* ip = &v;
    float f {0.0};
    float* flp = &f;


    std::cout << std::boolalpha << is_same_type(a, c); // false
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type(a, b); // true
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type(ip, v); // false
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type(&f, flp); // true
    std::cout << "\n";
    std::cout << std::boolalpha << is_same_type(ip, c); // false
    return 0;
}
