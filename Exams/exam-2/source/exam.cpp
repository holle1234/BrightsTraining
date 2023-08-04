#include "exam.h"



std::ostream &operator<<(std::ostream &os, const Deck &cont)
{
    for (auto it = cont.begin(); it != cont.end(); it++)
    {
        os << *it << " ";
    }
    
    
    return os;
}

std::ostream &operator<<(std::ostream &os, const PlayingCard& card)
{
    return os << card.value() << "-" << card.suit();
}
