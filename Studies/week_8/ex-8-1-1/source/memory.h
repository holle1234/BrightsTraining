#if !defined(MEMORY)
#define MEMORY
#include <iostream>


void ex1_func();
void ex2_func();


template<typename cont_it>
bool ex3_func(cont_it begin, cont_it end){

    if (begin == end){return true;}

    auto current = begin;
    auto next = std::next(current);

    while (next != end){

        if ((&(*next) - &(*current)) != 1){return false;}
        ++current;
        ++next;
    }
    
    return true;
}

#endif // MEMORY
