#include "source/functions.h"

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>


/* 
Calculator app that uses stored lambda functions as operators.
Each function is mapped to a operational character "= / * etc."
Uses recursion to solve simple problems. 
Brackets are not supported.

Known issues:
- order of operations does not follow left to right when ops at the same level (div. & mul.)


 */


int main(int argc, char const *argv[])
{
    //exercise_1();

    //exercise_2
    std::vector<std::string> expr;
    for (auto it = argv+1; it != argv+argc; it++){
        expr.push_back(*it);
    }

    if(validate_expr(expr)){
        std::cout << "=" << recursion(expr) << '\n';
        for (auto &&i : variable_map){
            std::cout << i.first << " " << i.second << '\n';
        }
    }
    else std::cout << "Invalid expression!" << '\n';

    return 0;
}
