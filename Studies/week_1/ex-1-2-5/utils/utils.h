#if !defined(UTILS)
#define UTILS
#include <iostream>
#include <exception>
#include <algorithm>


template<typename Iter>
bool printOptions(Iter begin, Iter end){

    // list was empty
    if (begin == end){
        return false;
    }

    int index {1};
    for (Iter i = begin; i != end; i++){
        std::cout << index << ". " << *i << "\n";
        index++;
    }

    return true;
}


template<typename Iter>
int menuPrompt(Iter begin, Iter end){

    if (!printOptions(begin, end)){
        throw std::invalid_argument("Empty list");
    }

    std::cout << "Whats your poison? (q = quit) ";
    std::string option;
    std::getline(std::cin, option);

    if (option == "q"){
        return -2;
    }
    
    // try to convert input to integer choice
    try{
        int intOption = std::stoi(option);
        if (intOption <= std::distance(begin, end) && intOption > 0){
            return intOption - 1;
        }
        return -1;
    }
    catch(const std::invalid_argument& e){
        return -1;
    }
}


bool checkNonEmptyString(std::string & member, std::string & value);

#endif // UTILS

