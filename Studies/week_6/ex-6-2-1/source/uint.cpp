#include "uint.h"
#include <ostream>


std::ostream &operator<<(std::ostream& os, const Uint& u)
{
    os << u.value;
    return os;
}