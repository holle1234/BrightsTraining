#include "func_template.h"
#include <iostream>

bool func(int a, int b){
    std::cout << "lol" << '\n';
    return true;
}


int main(int argc, char const *argv[])
{
    MyClass c {func};
    std::cout << typeid(c).name() << '\n';
    std::cout << c.get_size() << " " << c.get_type() << '\n';
    for (auto &&i : c.arguments){
        std::cout << i << '\n';
    }

    // Decltype does not execute anything. It deduces the type from expr.
    std::cout << typeid(decltype(MyClass(func))).name() << '\n';
    std::cout << typeid(decltype(c)::ftype).name() << '\n';

    return 0;
}
