#include "debug.h"
#include "source/uint.h"
#include <iostream>
#include <cstdint>

/* 
Creating custom unsigned int type with plus/minus operators using templates.
Type is able to be constructed via intgral types and via other instances.
Static variable of Uint count is defined in debug to track its instance count.
 */


int main(int argc, char const *argv[])
{
    // Uint c {'c'}; //not valid!
    Uint a {1L};
    Uint b {0LL};
    Uint c {static_cast<std::int8_t>(2)};
    Uint d {c};
    Uint e = a;
    Uint f = 1;

    #if defined(DEBUG)
    std::cout << "Uint count: " << debug::Uint_count << "\n";      // 6
    {
        Uint tmp1, tmp2, tmp3;
        std::cout << "Uint count: " << debug::Uint_count << "\n";  // 6 + 3
    }
    std::cout << "Uint count: " << debug::Uint_count << "\n";      // 6
    #endif // DEBUG

    // should pass
    std::cout << "a + b  : " << a + b << "\n";              // 1
    std::cout << "c - a  : " << c - a << "\n";              // 1
    std::cout << "b + 1  : " << b + 1 << "\n";              // 1
    std::cout << "d + -1 : " << d + -1 << "\n";             // 1
    std::cout << "e      : " << e << "\n";                  // 1
    std::cout << "f      : " << f << "\n";                  // 1

    // error cases
    try{
        std::cout << b - a  << "\n";                        // -1
        std::cout << b + (-5) << "\n";                      // -5
        std::cout << b - 2  << "\n";                        // -2
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


