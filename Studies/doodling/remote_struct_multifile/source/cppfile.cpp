#include <string>
#include <iostream>
#include "struct.h"


// MyStruct structFunc defenition
void MyStruct::structFunc(std::string input){
    std::cout << "Hello from MyStruct! arg: " << input << "\n";
    std::cout << "MyStruct member var value is now: " << privateVar << "\n";

}

