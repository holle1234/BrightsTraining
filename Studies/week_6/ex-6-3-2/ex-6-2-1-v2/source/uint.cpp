#include "uint.h"
#include <ostream>


std::ostream &operator<<(std::ostream& os, const Uint& u)
{
    os << u.value;
    return os;
}

unsigned int Uint::to_range(long x)
{
    // below zero. cast to T type to avoid auto conversion
    if(x < umin){
        return umin;
    }
    // greater than umax
    else if (x > umax){
        return umax;
    }
    // ok
    return static_cast<unsigned int>(x);

}
