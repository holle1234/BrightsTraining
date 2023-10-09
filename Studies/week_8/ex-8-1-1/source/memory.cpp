#include "memory.h"
#include <array>
#include <iostream>



void ex1_func(){}

void ex2_func(){
    std::array<int, 4> a {1,2,3,1};
    std::cout << "address of array: " << &a << "\n";
    for (auto &&i : a){
        std::cout << &i << "\n";
    }
    
}