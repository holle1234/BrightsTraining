#if !defined(UINT)
#define UINT

#include "../debug.h"
#include <ostream>
#include <iostream>


class Uint
{

public:

    unsigned int value {0};

    // default constructor
    Uint() {
        #if defined(DEBUG)
            debug::Uint_count ++;
        #endif // DEBUG
    }

    // default deconstructor
    ~Uint(){
        std::cout << "Exiting.. doing some cleanup\n";
        
        #if defined(DEBUG)
            debug::Uint_count--;
        #endif // DEBUG
    };

    // constructor for all integers (not including char)
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    Uint(T x){
        if(x < 0){throw(std::invalid_argument("Cant assign smaller than zero to a class type of Uint. Got " + std::to_string(x)));}
        this->value = x;

        #if defined(DEBUG)
            debug::Uint_count++;
        #endif // DEBUG
    }

    // constructor for Uint input
    Uint(const Uint& another){
        this->value = another.value;

        #if defined(DEBUG)
            debug::Uint_count++;
        #endif // DEBUG
    }

    // plus with integers
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    Uint operator+(T x){
        int res = static_cast<int>(this->value) + x;
        return Uint(res);
    }

    // minus with integers
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    Uint operator-(T x){
        int res = static_cast<int>(this->value) - x;
        return Uint(res);
    }

    // plus with another Uint
    Uint operator+(const Uint& another){
        int x = static_cast<int>(this->value) + another.value;
        return Uint(x);
    }

    // minus with another Uint
    Uint operator-(const Uint& another){
        int x = static_cast<int>(this->value) - another.value;
        return Uint(x);
    }

    // copy Uint
    Uint& operator=(const Uint& another){
        std::cout << "copying \n";
        this->value = another.value;
        return *this;
    }

    // copy Uint
    Uint& operator=(const int& value){
        std::cout << "copying \n";
        this->value = value;
        return *this;
    }

    // printing etc.
    friend std::ostream& operator<<(std::ostream& os, const Uint& u);
};

#endif // UINT
