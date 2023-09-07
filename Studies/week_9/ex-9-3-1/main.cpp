#include "iterators.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <type_traits>
#include <bitset>

// Ex 1.
void print_string(std::string&& str){
    for (auto it = str.begin(); it != str.end(); it++){
        std::cout << int(*it)<< '(' << *it << ')' << (it == str.end() - 1 ? "\n" : ", ");
    }
}


int main(int argc, char const *argv[])
{

    print_string("hello");
    print_string("hellå"); // two chars instead of expected one
    print_string("🍍");    // four chars
    print_string("π");


    const std::string st {"h🍍π"};
    for (MyIterator it = st.begin(); it != st.end(); ++it){
        std::cout << static_cast<uint32_t>(*it) << '\n';
    }

    return 0;
}
