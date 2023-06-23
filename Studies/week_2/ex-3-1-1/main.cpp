#include <stdexcept>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <cctype>


// check if b is 0
int int_devision(int a, int b){
    if(b == 0){
        throw std::invalid_argument("Devision by Zero!");
    }
    return a / b;
}

// to accept any kind iterators
template<typename Iterator>
int max_value(Iterator begin, Iterator end){

    if (begin == end){
        throw std::invalid_argument("Container is empty!");
    }

    int max {*begin};
    Iterator it = begin;

    while (it != end)
    {
        if (*it > max){
            max = *it;
        }
        it++;
    }
    return max;
}

// check if index is in range throw error otherwise
const std::string& chooce_name(const std::vector<std::string>& names, int index){
    if ((index >= 0 ) && (index < names.size())){
        return names.at(index);
    }
    else{
        throw std::invalid_argument("Index not in range!");
    }
}

bool process_data(int value){
    if (value < 0){
        throw std::invalid_argument("Process data: int value < 0");
    }
    return true;
}

bool process_data(std::string value){
    for (auto it = value.begin(); it != value.end(); it++){
        if (!std::isalpha(*it)){
            throw std::invalid_argument("Process data: string contains non alpha chars");
        }
    }
    return true;
}


int main(int argc, char const *argv[])
{

    // Ex 1.
    try
    {
        std::cout << int_devision(10, 2) << "\n";
        std::cout << int_devision(10, 0) << "\n";
    }

    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }


    // Ex 2.
    try
    {
        // should return -1
        std::list<int> test_list {-1, -15, -14};
        std::cout << max_value(test_list.begin(), test_list.end()) << "\n";

        // should return 9
        std::vector<int> test_vector {1, 9, 7};
        std::cout << max_value(test_vector.begin(), test_vector.end()) << "\n";
        
        // should throw error
        test_list.clear();
        std::cout << max_value(test_list.begin(), test_list.end()) << "\n";
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
        
    // Ex 3.
    // not a loop printing program as requested but gets the idea across..
    try
    {
        // should return 'alfa'
        std::vector<std::string> names {"alfa", "bravo", "charlie"};
        std::cout << chooce_name(names, 0) << "\n";

        // should throw error
        std::cout << chooce_name(names, 60) << "\n";

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    // Ex 4.
    for (size_t i = 0; i < 4; i++)
    {
        try{   
            switch (i){
                // should be 1
                case 0:{std::cout << "Overloaded process_data " << process_data(0) << "\n";
                    break;
                }
                // should throw error
                case 1:{std::cout << "Overloaded process_data " << process_data(-10) << "\n";
                    break;
                }
                // should be 1
                case 2:{std::cout << "Overloaded process_data " << process_data("aLpHas") << "\n";
                    break;
                }
                // should throw error
                case 3:{std::cout << "Overloaded process_data " << process_data("aLpHa5") << "\n";
                    break;
                }
                default:
                    break;
            }
            
        }
        catch(const std::invalid_argument& e){
            std::cerr << e.what() << '\n';
        }

    }

    
    
    return 0;
}
