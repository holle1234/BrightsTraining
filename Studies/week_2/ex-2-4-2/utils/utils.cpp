#include "utils.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

// returns size 8 string '0' filled from left
std::string toSerial(int i)
{   
    std::string strNum = std::to_string(i);
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(8) << strNum;
    return ss.str();
}

// dummy id generator from 1->
std::string generateDeviceID()
{
    static int currentId{0};
    currentId++;
    return toSerial(currentId);
}

bool isInteger(const std::string& s)
{
    for (auto it = s.begin(); it != s.end(); it++){
        if (!std::isdigit(*it)){return false;}
    }
    return true;
}
