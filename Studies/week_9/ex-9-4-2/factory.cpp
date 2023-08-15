#include "factory.hpp"

std::ostream &operator<<(std::ostream &os, const Factory &fac)
{
    return os << "I has the value!" << '\n';
}