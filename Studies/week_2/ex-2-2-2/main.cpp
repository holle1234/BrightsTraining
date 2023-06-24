#include "utils/utils.h"
#include <iostream>
#include <algorithm>

/* 

Calculator program that can do basic operations and ceasar cipher:
--sum  [double][double] addition
--dev  [double][double] division
--pow  [double][double] power
--mul  [double][double] multiplication
--avg  [double][double] mean
--sub  [double][double] subtraction
--ccc  [string][ int  ] ceasar cipher
--ccd  [string][ int  ] ceasar decipher

Showcases also how to use asserts in multifile project.
You would need to define NDEBUG in every .cpp file where you have asserts.
If you choose to include a header where it is defined instead,
you would only need to comment it out in that one file when you need asserts.

 */


int main(int argc, char const *argv[])
{

    auto begin = argv;
    auto end = argv + argc;

    if(argc > 1){
        std::pair<bool, std::string> result {processCommand(begin, end)};
        if(result.first){
            
            std::cout << result.second << "\n";
        }else {
            std::cout << "invalid arguments supplied!\n";
        }
    }else {printHelp();}
    return 0;
}
