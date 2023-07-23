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
    Data data1 {1};
    int out = data1.get(out);
    std::cout << "Integer type: " << out << "\n";
    
    Data data2 {'c'};
    char out2 = data2.get(out2);
    std::cout << "Char type: " << out2 << "\n";

    Data data3 {1.0f};
    float out3 = data3.get(out3);
    std::cout << "Float type: " << out3 << "\n";

    Data data4 {"Asd"};
    char out4 = data4.get(out4);
    std::cout << "String type: " <<out4 << "\n";


    // explicit keyword blocks the use of copy initialization

    //Data data = 1;        // not ok
    //Data data_i = {2};    // not ok
    Data data_c = 's';      // ok
    Data data_f = {2.0f};   // ok


    return 0;
}
