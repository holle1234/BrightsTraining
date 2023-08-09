#include "tagged/tagged_union.h"
#include "file/file.h"
#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    // 1-2
    Data obj;
    std::cout << obj << "\n";

    obj.set("1");
    std::cout << obj << "\n";

    obj.set("p");
    std::cout << obj << "\n";

    obj.set("2.0");
    std::cout << obj << "\n";

    // 3-4
    std::vector<Data> obj_cont;
    cfile::FileHandle handle {"test.txt"};
    std::cout << "File size is: " << handle.size() << "\n";
    
    while (handle){
        std::string line = handle.readline();
        std::cout << "Creating object from: \t" << line;
        obj_cont.push_back(Data(line));
    }

    std::cout << '\n';
    for (auto &&cont_obj : obj_cont){
        std::cout << cont_obj << '\n';
    }
    


    return 0;
}
