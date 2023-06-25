#include <string>
#include "utils.h"

bool checkNonEmptyString(std::string& member, std::string& value){
    if (!std::empty(value)){
        member = value;
        return true;
    }
    return false;
}
