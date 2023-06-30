#include "debug.h"
#include "utils.h"
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <assert.h>


double sum(double a, double b){
    return a + b;
}

double substract(double a, double b){
    return a - b;
}

double multiply(double a, double b){
    return a * b;
}

double devide(double a, double b){
    assert(b != 0);
    double res {a / b};
    return std::isinf(res) ? 0 : res;
}

double power(double a, double b){
    return std::pow(a, b);
}

double mean(double a, double b){
    return (a + b) / 2;
}


double handleCommand(Options option, double a, double b){

    switch (option){
        case Options::sum :{
            return sum(a, b);
        }
        case Options::sub :{
            return substract(a, b);
        }
        case Options::dev :{
            return devide(a, b);
        }
        case Options::mul :{
            return multiply(a, b);
        }
        case Options::avg :{
            return mean(a, b);
        }
        case Options::pow :{
            return power(a, b);
        }

        default: break;
    
    }
    
    return 0.0;
}

std::string handleCommand(Options option, int a, std::string& b){

    switch (option){
        case Options::ccc :{
            return ceacarsCipherIn(a, b);
        }
        case Options::ccd :{
            return ceacarsCipherOut(a, b);
        }

        default: break;
    
    }
    
    return "";
}

bool isRightSize(const char** begin , const char** end){
    assert (std::distance(begin, end) == 2);
    return std::distance(begin, end) == 2;
}


// unpack numeric arguments following the operation option
bool unpackArguments(const char** begin , const char** end, std::pair<double, double>& dest){

    // there must be two numbers no more no less
    if (!isRightSize(begin, end)){return false;}

    try{
        dest.first = std::stod(*begin);
        dest.second = std::stod(*(begin + 1));
    }
    catch(const std::invalid_argument& e){
        return false;
    }
    
    return true;
}

// unpack ceasar arguments following the operation option
bool unpackArguments(const char** begin , const char** end, std::pair<int, std::string>& dest){

    if (!isRightSize(begin, end)){return false;}
    try{
        dest.first = std::stoi(*(begin + 1));
        dest.second = *begin;
    }
    catch(const std::invalid_argument& e){
        return false;
    }
            
    return true;
}


std::pair<bool, std::string> processCommand(const char** begin , const char** end){

    // check existance for all commands
    for (int index = 0; index < COMMANDS.size(); index++){
        Options option {static_cast<Options>(index)};

        auto loc = std::find(begin, end, COMMANDS[index]);
        if (loc == end) {continue;}

        // if ceasar, string and number should follow
        if (option == Options::ccc || option == Options::ccd){
            std::pair<int, std::string> arguments;
            if (unpackArguments(loc+1, end, arguments)){
                // Call matching function and return the results
                std::string result = handleCommand(option,
                                                   arguments.first,
                                                   arguments.second);
                return {true, result};
            }
        }
        // if math operation, two numbers follow
        else {
            std::pair<double, double> arguments;
            if (unpackArguments(loc+1, end, arguments)){
                // Call matching function and return the results
                double result = handleCommand(option,
                                              arguments.first,
                                              arguments.second);

                return {true, std::to_string(result)};
            }
        }
    }

    return {false, ""};
}

void printHelp(){
    for (auto &&i : COMMANDHELP){
        std::cout << i << "\n";
    }
}

std::string ceacarsCipherIn(int ceasar, std::string input){
    std::for_each(input.begin(), input.end(), [&](char& v){v += ceasar;});
    return input;
}

std::string ceacarsCipherOut(int ceasar, std::string input){
    std::for_each(input.begin(), input.end(), [&](char& v){v -= ceasar;});
    return input;
}