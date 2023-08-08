#if !defined(UINT)
#define UINT

#include "../debug.h"
#include <ostream>
#include <iostream>
#include <limits>




// max value
constexpr long umax {std::numeric_limits<unsigned int>::max()};
// min value
constexpr long umin {std::numeric_limits<unsigned int>::min()};



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
        #if defined(DEBUG)
            debug::Uint_count--;
        #endif // DEBUG
    };

    // constructor for all integers (not including char)
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    Uint(T x){

        this->value = to_range(x);
        
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
        long val = static_cast<long>(value);
        long xl = static_cast<long>(x);
        
        // too small of a negative
        if (xl < (umin - value)){
            return Uint(umin);
        }
        // too big
        else if (xl > (umax - val)){
            return Uint(umax);
        }

        return Uint(val + xl);
    }

    // minus with integers
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    Uint operator-(T x){
        long val = static_cast<long>(value);
        long xl = static_cast<long>(x);
        
        // too small of a negative (-- op)
        if (xl < (value - umax)){
            return Uint(umax);
        }
        // too big
        else if (xl > val){
            return Uint(umin);
        }
        
        return Uint(val - xl);
    }

    // plus with another Uint
    Uint operator+(const Uint& another){
        long val = static_cast<long>(value) + another.value;
        return Uint(val);
    }

    // minus with another Uint
    Uint operator-(const Uint& another){
        long val = static_cast<long>(value) - another.value;
        return Uint(val);
    }

    // copy Uint
    Uint& operator=(const Uint& another){
        this->value = another.value;
        return *this;
    }

    // copy Uint
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    Uint& operator=(const T& x){
        this->value = to_range(x);
        return *this;
    }

    // equal Uint
    bool operator==(const Uint& another) const {
        return this->value == another.value;
    }

    // equal int
    template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, char>::value, int>::type = 0>
    bool operator==(T x) const {
        return this->value == x;
    }

    // printing etc.
    friend std::ostream& operator<<(std::ostream& os, const Uint& u);

private:
    unsigned int to_range(long x);

};

#endif // UINT
