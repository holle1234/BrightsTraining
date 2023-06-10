#include <string>
#include <iostream>
#include "functions.h"
#include "struct.h"


// print function defenition (note the include)
void print(MyStruct* arg){
     std::cout << "Hello from print funct defenition! arg: " << arg->privateVar << "\n";
}

