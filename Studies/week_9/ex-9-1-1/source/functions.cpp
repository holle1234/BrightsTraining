#include "functions.h"

#include <iostream>
#include <vector>
#include <functional>
#include <string>


void exercise_1(){

    // Exercise 1.
    std::vector<std::function<int()>> funcs = {
        [&](){return 1;},
        [&](){return 2;},
        [&](){return 3;},
    };

    std::string row;
    while (true){
        std::cout << "Give function number to call (q=quit): ";
        std::getline(std::cin, row);

        if(!std::cin.good()){
            std::cout << "Error encoutered while reading input. Shutting down program.";
            break;
        }

        if(row == "q"){break;}
        bool isint = std::all_of(row.begin(),
                        row.end(),
                        [](const auto v){return std::isdigit(v);});

        if(isint){
            int index = std::stoi(row);
            if (index < funcs.size()){
                std::cout << "Function '" << funcs[index]() << "' was called." << '\n';
                continue;
            }
        }
        std::cout << "Invalid argument!" << '\n';
    }
    
}



bool is_variable(const std::string& value){
    return value.size() == 1 && std::isalpha(value[0]);
}

bool is_numeric(const std::string& value){
    return value.find_last_not_of(numeric_carray) == value.npos;
}

bool is_operation(const std::string& value){
    return value.find_last_not_of(symbols_carray) == value.npos;
}


// exercise_2
bool validate_expr(std::vector<std::string>& input){

    InputTypes prev_type = InputTypes::invalid;
    InputTypes next_type = InputTypes::invalid;

    // minimum expr length
    if(input.size() < 3){
        return false;
    }

    for (auto it = input.begin(); it != input.end(); it++){
        const std::string& value = *it;

        // operation symbol type
        if (is_operation(value)){

            // operation cant be back or front
            if (it == input.begin() || &value == &*input.rbegin()){
                return false;
            }
            // assign must be at the second position
            if (value == std::string(1, symbols[6]) && (it != input.begin() + 1)){
                return false;
            }

            next_type = InputTypes::operation_symbol;
        }

        // numeric type
        else if(is_numeric(value)){
            next_type = InputTypes::number;
        }

        // variable type
        else if (is_variable(value)){

            // If variable is followed by '=' dont convert it.
            // The result of the expression is assigned to this variable
            if (!(it == input.begin() && *(it+1) == std::string(1, symbols[6]))){
                // fetch saved variable and replace symbol with a numeric
                if (variable_map.find(value[0]) != variable_map.end()){
                    *it = std::to_string(variable_map[value[0]]);
                }
                else return false;
            }
            
            next_type = InputTypes::number;
        }

        // non matcing type
        else return false;

        // two values with same type in a row is not allowed
        if (prev_type == next_type){
            return false;
        }

        prev_type = next_type;
    }

    return true;
}

double recursion(std::vector<std::string>& input){

    if (input.size() > 1){
        for (auto &&op : symbols){
            auto loc = std::find_if(input.begin(),
                                    input.end(),
                                    [&](std::string& a){return a == std::string(1, op);});
            if (loc != input.end()){
                double result {0.0};

                // assignment to variable
                if(*loc == std::string(1, symbols[6])){
                    save_variable((*(loc-1))[0], stod(*(loc+1)));
                    result = stod(*(loc+1));
                }
                else result = function_map[op](stod(*(loc-1)), stod(*(loc+1)));
                
                *loc = std::to_string(result);
                input.erase(loc+1);
                input.erase(loc-1);
                recursion(input);
            }
        }
    }

    // base case
    return std::stod(input[0]);;
}

void save_variable(char key, double value){
    variable_map[key] = value;
}