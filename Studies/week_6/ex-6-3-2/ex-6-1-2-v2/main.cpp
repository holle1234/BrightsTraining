#include "source/tagged_union.h"
#include <iostream>

/* Exercise 1

Our tagged union will represent either a person, a robot or an alien.  The robots are
identified using an ID (integer value), persons are identified by the first letter of their
name (a char), and aliens are identified by the approximate wavelength of the light
their eyes emit. (a floating point value)

Create a header file where you declare the type and its member function prototypes,
requirements are
A way to check what type of object is stored
A way to access each of the different value types
A member function to set the stored value (overloading will be your friend here)
The type should be an union-like class (i.e. a class or struct with anonymous union member)
Pay attention to the const-ness of member functions and return values
Make sure you use references where needed! */



int main(int argc, char const *argv[])
{
    Data data;
    bool operation_status {false};

    data.set(20);
    int test1;
    data.get(test1, operation_status);
    std::cout << "testing int: 20 " << test1 << "\n";
    std::cout << "enum type is: " << data.type() << "\n";
    std::cout << "operation status: " << std::boolalpha << operation_status << "\n\n";

    data.set('j');
    char test2;
    data.get(test2, operation_status);
    std::cout << "testing char: 'j' " << test2 << "\n";
    std::cout << "enum type is: " << data.type() << "\n";
    std::cout << "operation status: " << std::boolalpha << operation_status << "\n\n";

    data.set(3.14f);
    float test3;
    data.get(test3, operation_status);
    std::cout << "testing float: 3.14f " << test3 << "\n";
    std::cout << "enum type is: " << data.type() << "\n";
    std::cout << "operation status: " << std::boolalpha << operation_status << "\n\n";

    // constant test
    char const_char {'f'};
    data.set(const_char);
    char test6;
    data.get(test6, operation_status);
    std::cout << "testing const char: 'f' " << test6 << "\n";
    std::cout << "enum type is: " << data.type() << "\n";
    std::cout << "operation status: " << std::boolalpha << operation_status << "\n\n";
    
    // user error
    data.set(20);
    char test4;
    data.get(test4, operation_status);
    std::cout << "testing int: 20 " << test4 << "\n";
    std::cout << "enum type is: " << data.type() << "\n";
    std::cout << "operation status: " << std::boolalpha << operation_status << "\n\n";

    // user error
    data.set('f');
    int test5;
    data.get(test5, operation_status);
    std::cout << "testing char: 'f' " << test5 << "\n";
    std::cout << "enum type is: " << data.type() << "\n";
    std::cout << "operation status: " << std::boolalpha << operation_status << "\n\n";


    // Assignment part 2
    // Not able to detect any errornous use. No asserts needed?

    return 0;
}
