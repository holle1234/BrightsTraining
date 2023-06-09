#include <iostream>
#include "header.h"


// HOX remember to modify tasks.json to compile multiple files!
// single file "${file}"
// multiple files "${fileDirname}/*.cpp", 

// Showcase program for accessing objects from different files.
// This sample shows how to access objects in namespace defined on another file 

int main(){
    std::cout << "access to myFunc in test namespace using test::myFunc(20): \nreturns: "
              << test::myFunc(20) << "\n";
    return 0;
}