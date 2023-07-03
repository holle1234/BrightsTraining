#include "utils.h"
#include <cmath>
#include <stdexcept>
#include <string>
#include <algorithm>


double add(double a, double b){
    return a + b;
}

double substract(double a, double b){
    return a - b;
}

double multiply(double a, double b){
    return a * b;
}

// we want inf and nan to raise exeption and zero devision to result as zero
double devide(double a, double b){
    if (std::isinf(a) || std::isinf(b) || std::isnan(a) || std::isnan(b)){
        throw(std::invalid_argument("Cant supply nan or inf to devide!"));
    }
    return (b == 0) ? 0 : a / b;
}

std::string reverse_string(const std::string& input){
    std::string strcopy {input};
    std::reverse_copy(input.begin(), input.end(), std::begin(strcopy));
    return strcopy;
    
}

std::string toupper_string(const std::string& input){
    std::string strcopy {input};
    std::transform(input.cbegin(), input.cend(),
                   strcopy.begin(), [](unsigned char c) { return std::toupper(c); });
    return strcopy;
}

std::string tolower_string(const std::string& input){
    std::string strcopy {input};
    std::transform(input.cbegin(), input.cend(),
                   strcopy.begin(), [](unsigned char c) {return std::tolower(c);});
    return strcopy;
}

bool is_string_palindrome(const std::string& input){
    std::string rev = reverse_string(input);
    return rev == input;
}