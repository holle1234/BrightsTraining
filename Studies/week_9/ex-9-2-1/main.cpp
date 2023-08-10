#include "bitsnpieces.h"
#include <iostream>
#include <bitset>



int main(int argc, char const *argv[])
{
    unsigned int a {0xCAFE};
    unsigned int b {0x1};
    std::cout << std::boolalpha << is_set_bit(b, 0) << '\n';
    std::cout << std::hex << std::uppercase << a << " " << byte_swap(a) << "\n\n";

    uint8_t t = 0b10000001;
    std::cout << show_comb_flags(t) << '\n';


    // Ex 5.
    std::string str("", 10);
    std::cout << "Give string to bitmask with: ";
    std::getline(std::cin, str);
    std::cout << find_commas(str) << '\n';

    return 0;
}

