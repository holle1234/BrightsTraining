#include "variadic.h"
#include <iostream>
#include <vector>
#include <list>


int main(int argc, char const *argv[])
{
    // same types
    std::cout << sum(true, 1, 1, '0') << "\n";
    std::cout << std::boolalpha << all_the_same(true, false, true) << "\n"; // true
    std::cout << std::boolalpha << all_the_same(0, 10, 2.0f) << "\n"; // false

    // products
    std::cout << size_product(2.5, 2.5) << "\n"; // 12.5
    //std::cout << size_product(2, 2.5) << "\n"; // 12.5 error: must be same type
    std::cout << std::boolalpha << product(true, true, true) << "\n"; // true
    std::cout << std::boolalpha << product(true, false, true) << "\n"; // false


    // Concat Containers
    std::vector<int> dest {};
    std::vector<int> test {1,2};
    concat(dest, test, std::vector<int>{0}, std::list<int>{5,5,5});
    for (auto &&i : dest)
    {
        std::cout << i << (&i != &dest.back() ? "," : "");
    }

    return 0;
}
