#if !defined(CALCULATOR)
#define CALCULATOR

#include <unordered_map>
#include <functional>
#include <math.h>
#include <string>


enum class InputTypes{
    operation_symbol,
    number,
    invalid,
};

constexpr static std::string_view symbols_carray {"*/+-^%="};
constexpr static std::string_view numeric_carray {"1234567890.-+"};
constexpr static std::array<char, 7> symbols {'^','*','/','+','-','%','='};

static std::unordered_map<char, double> variable_map = {};
static std::unordered_map<char, std::function<double(double, double)>> function_map = {
    {symbols[0], [](double a, double b){return pow(a, b);}},
    {symbols[1], [](double a, double b){return a * b;}},
    {symbols[2], [](double a, double b){return ((std::fabs(b) < 1E-12) ? 0 : a / b);}}, // zero devision
    {symbols[3], [](double a, double b){return a + b;}},
    {symbols[4], [](double a, double b){return a - b;}},
    {symbols[5], [](double a, double b){
        if (b < 0){return a + (a * (b / 100));}
        else {return a * (b / 100);}
        
    }},
};





void exercise_1();

// expression checks
bool is_variable(const std::string &value);

bool is_numeric(const std::string &value);

bool is_operation(const std::string &value);

// check and preprocess calculator expr
bool validate_expr(std::vector<std::string> &input);
// solve expression recursively
double recursion(std::vector<std::string> &input);
// save expressions results to keys
void save_variable(char key, double value);

#endif // CALCULATOR
