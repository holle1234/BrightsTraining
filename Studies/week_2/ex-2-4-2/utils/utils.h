#if !defined(UTILS)
#define UTILS

#include <string>
#include <sstream>
#include <iomanip>


// returns size 8 string '0' filled from left
std::string toSerial(int);

// dummy id generator from 1->
std::string generateDeviceID();

// checks if number is a numeric type
bool isInteger(const std::string &s);



#endif // UTILS



