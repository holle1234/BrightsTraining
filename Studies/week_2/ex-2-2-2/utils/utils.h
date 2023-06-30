#if !defined(CALCULATOR_UTILS)
#define CALCULATOR_UTILS

#include <string>
#include <array>
#include <vector>


const std::array<std::string, 8> COMMANDS {"--sum",
                                           "--dev",
                                           "--pow",
                                           "--mul",
                                           "--avg",
                                           "--sub",
                                           "--ccc",
                                           "--ccd"};


const std::array<std::string, 8> COMMANDHELP {"--sum  [double][double] addition",
                                              "--dev  [double][double] division",
                                              "--pow  [double][double] power",
                                              "--mul  [double][double] multiplication",
                                              "--avg  [double][double] mean",
                                              "--sub  [double][double] subtraction",
                                              "--ccc  [string][ int  ] ceasar cipher",
                                              "--ccd  [string][ int  ] ceasar decipher"};
                                
enum class Options{
    sum,
    dev,
    pow,
    mul,
    avg,
    sub,
    ccc,
    ccd
};


double multiply(double a, double b);

double devide(double a, double b);

double power(double a, double b);

double mean(double a, double b);

double sum(double a, double b);

double substract(double a, double b);

double handleCommand(Options option, double a, double b);

std::string handleCommand(Options option, int a, std::string& b);

std::string ceacarsCipherIn(int ceasar, std::string input);

std::string ceacarsCipherOut(int ceasar, std::string input);

bool unpackArguments(const char **begin, const char **end, std::pair<double, double>& dest);

bool unpackArguments(const char** begin , const char** end, std::pair<int, std::string>& dest);

std::pair<bool, std::string> processCommand(const char **begin, const char **end);

void printHelp();



#endif // CALCULATOR_UTILS

