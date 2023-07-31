#include "source/memory.h"
#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <map>
#include <list>
#include <algorithm>

/* 
Exercise 1
Create a stack variable of any fundamental type in main() function (so just an usual declaration).  
Then print out its memory address.
Create a function in the same program and do the same.  
Compute the difference between the addresses and print that out too.


Exercise 2
std::vector uses heap memory internally to store its contents.  
Create an std::vector, throw in some elements and print out the address of the vector itself and all of its elements.  
Think about what you see.  Is the vector's position in the memory same as its contents?  Why?


Exercise 3
Elements being contiguous in memory is an important concept.  This means they are located in the memory one after another.
Create a (template) function that takes a container as its input, and checks if the elements in the container are next to each other.
Create few container types (list, vector, array, deque) and check if this holds true.  
Try it with different counts of elements (e.g. with 1000, 1000000, 100000000 elements)

 
Exercise 4
Check if std::vector of std::vectors is contiguous.

*/


int main(int argc, char const *argv[])
{
    // 1.
    int a {0};
    int* add_a = &a;
    int* add_func = reinterpret_cast<int*>(ex1_func);

    // you cant count difference between two different kinds of pointers without casting
    std::cout << add_a << " : " << add_func << " diff = " << add_a - add_func << "\n";


    // 2.
    // Vectors position is the same as the first item it contains.
    // Pointing to the first element allows vector to grow and shring without losing the memory position.
    // It also enables fast and straightforward access to the following array elements using pointer artithmetic. 
    ex2_func();

    //3. 
    auto li = std::list<int> (10000);
    auto ve = std::vector<int> (10000);
    auto ar = std::array<int, 10000>();
    auto de = std::deque<int>(10000);

    std::string st (10000, 'y');
    std::map<int, int> ma {{1, 1}, {2,2}, {3,3}};

    std::cout << std::boolalpha;
    std::cout << "deque:  " << ex3_func(de.begin(), de.end()) << '\n';
    std::cout << "map:    " << ex3_func(ma.begin(), ma.end()) << '\n';
    std::cout << "list:   " << ex3_func(li.begin(), li.end()) << '\n';
    std::cout << "vector: " << ex3_func(ve.begin(), ve.end()) << '\n';
    std::cout << "array:  " << ex3_func(ar.begin(), ar.end()) << '\n';
    std::cout << "string: " << ex3_func(st.begin(), st.end()) << '\n';

    return 0;
}
