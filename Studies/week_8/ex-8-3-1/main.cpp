#include "source/custom_type.h"
#include <iostream>
#include <tuple>
#include <string>




int main(int argc, char const *argv[])
{
    // int
    MyContainer<5, int> icont1 {0};
    MyContainer<5, int> icont2 {1};

    // string
    MyContainer<5, std::string> scont1 {"0"};
    MyContainer<5, std::string> scont2 {"-"};


    // copy assignment
    icont2 = icont1; // to zeros
    std::cout << icont1 << '\n';

    // move assignment
    icont2 = MyContainer<5, int> {1}; // to ones
    std::cout << icont2 << '\n';

    // copy const
    MyContainer<5, std::string> scont3 {scont1}; // to 'zeros'
    std::cout << scont3 << '\n';

    // move const
    MyContainer<5, std::string> scont4 = std::move(scont2); // to '-'
    std::cout << scont4 << '\n';

    // value assignment
    scont1[0] = "?";

    // loop
    for (auto &&v : scont1){
        std::cout << v << " ";
    }std::cout << '\n';
    
    // swap
    std::cout << scont1.begin() << " " << scont4.begin() << '\n';
    scont1.swap(scont4);
    std::cout << scont1.begin() << " " << scont4.begin() << '\n';

    return 0;
}


