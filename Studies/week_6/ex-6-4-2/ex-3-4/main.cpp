#include "source/file.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    cfile::FileHandle handle {"test.txt"};

    std::cout << "File size is: " << handle.size() << "\n";
    while (handle){
        std::cout << handle.readline();
    }

    // print every line of text file
    std::vector<std::string> lines = cfile::readlines(handle);
    for (auto &&line : lines){
        std::cout << line << "\n";
    }
    

    return 0;
}
