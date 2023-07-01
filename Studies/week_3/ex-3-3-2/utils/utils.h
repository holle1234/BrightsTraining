#if !defined(UTILS)
#define UTILS

#include <string>


// functions declarations made before tests

double add(double a, double b);
double substract(double a, double b);
double multiply(double a, double b);
double devide(double a, double b);


std::string reverse_string(const std::string& input);
std::string toupper_string(const std::string& input);
std::string tolower_string(const std::string& input);
bool is_string_palindrome(const std::string& input);




#endif // UTILS
