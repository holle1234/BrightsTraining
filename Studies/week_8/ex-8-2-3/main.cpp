#include "source/custom_type.h"
#include <iostream>
#include <tuple>
#include <string>




int main(int argc, char const *argv[])
{
    // string
    MyContainer<std::string> cont {5, 5, "i"};
    MyContainer<std::string> cont2 {5, 5, "-"};
    MyContainer<std::string> cont3 {5, 6, "0"};

    // copy
    //cont = cont2;
//    cont3 = {cont2};
//   std::cout << cont3;

    // move
    cont = std::move(cont2);

    // move-constr (cont was copied from cont2 previously)
    cont.update(0,0, "i");
    MyContainer<std::string> cont_moveconstr = std::move(cont);

    std::cout << cont_moveconstr;

    return 0;
}


