#include "source/file.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    cfile::FileHandle handle {"test.txt"};

    std::cout << "File size is: " << handle.size() << "\n";
    while (handle){
        std::cout << handle.readline();
    }

    return 0;
}
