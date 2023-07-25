#include "source/custom_type.h"
#include <iostream>
#include <tuple>
#include <string>

/* 
Custom template 2D container with vector storage.
Can store and modify different types of data.
Container is resizable.

PRINT:

// STRING
size after init {5,5}: 25

1 i i i i 
i 2 i i i 
i i 3 i i 
i i i 4 i 
i i i i 5 


size after resize(1,5): 100

1 i i i i i i i i i 
i 2 i i i i i i i i 
i i 3 i i i i i i i 
i i i 4 i i i i i i 
i i i i 5 i i i i i 
i i i i i i i i i i 
i i i i i i i i i i 
i i i i i i i i i i 
i i i i i i i i i i 
i i i i i i i i i i 


// INT
size after init {5,5}: 25

1 0 0 0 0 
0 2 0 0 0 
0 0 3 0 0 
0 0 0 4 0 
0 0 0 0 5 


size after resize(1,5): 30

1 0 0 0 0 0 0 0 0 0 
0 2 0 0 0 0 0 0 0 0 
0 0 3 0 0 0 0 0 0 0 

 */


int main(int argc, char const *argv[])
{
    // string
    MyContainer<std::string> cont {5, 5, "i"};
    std::cout << "size after init {5,5}: " << cont.size() << "\n\n";
 
    for (size_t i = 0; i < 5; i++)
    {
        cont.update(i, i, std::to_string(i+1));
    }
    std::cout << cont << "\n\n";

    cont.resize(10, 10);
    std::cout << "size after resize(1,5): " << cont.size() << "\n\n";
    std::cout << cont << "\n\n";



    //int
    MyContainer<int> icont {5, 5, 0};
    std::cout << "size after init {5,5}: " << icont.size() << "\n\n";
 
    for (size_t i = 0; i < 5; i++)
    {
        icont.update(i, i, i + 1);
    }
    std::cout << icont << "\n\n";

    icont.resize(10, 3);
    std::cout << "size after resize(1,5): " << icont.size() << "\n\n";
    std::cout << icont << "\n\n";

    return 0;
}


