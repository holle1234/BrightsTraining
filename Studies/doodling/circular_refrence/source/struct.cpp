#include <iostream>
#include "struct.h"
#include "functions.h"


// MyStruct structFunc defenition
// calls print from functions.h (note the include)
void MyStruct::structFunc(){
    std::cout << "Hello from MyStruct's print funct defenition!\n";
    print(this);

}

