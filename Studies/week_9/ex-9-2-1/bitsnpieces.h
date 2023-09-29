#if !defined(BITS)
#define BITS

#include <type_traits>
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <array>

// OPTIONS
constexpr static uint8_t IS_FUZZY            = 0b1;
constexpr static uint8_t IS_LARGE            = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES     = 0b100;
constexpr static uint8_t IS_CUTE             = 0b1000;
constexpr static uint8_t HAS_TEETH           = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY         = 0b1000000;
constexpr static uint8_t IS_SPIDER           = 0b10000000;

// COMBINATION OPTIONS
constexpr static uint8_t FUZZY_SPIDER        = 0b10000001;
constexpr static uint8_t LARGE_SPIDER        = 0b10000010;
constexpr static std::array<std::uint8_t, 2> combinations{
    FUZZY_SPIDER,
    LARGE_SPIDER
};

constexpr static std::array<std::string_view, 8> options_strrepr{
    "IS_FUZZY",
    "IS_LARGE",
    "HAS_GOOGLY_EYES",
    "IS_CUTE",
    "HAS_TEETH",
    "IS_ABOUT_TO_EAT_YOU",
    "IS_FRIENDLY",
    "IS_SPIDER",
};

constexpr static std::array<std::string_view, 2> combination_strrepr{
    "FUZZY_SPIDER",
    "LARGE_SPIDER"
};


// Ex 1.
template<typename T>
bool is_set_bit(T value, unsigned int index){
    return value & (1 << index);
}

// Ex 2.
template<typename T>
T byte_swap(T value){
    static_assert(std::is_integral_v<T> && std::is_unsigned_v<T>);
    constexpr size_t size = sizeof(T);

    // union holds the same memory block for both variables
    // when swapping char array, it swaps the order of 'u' too.
    union byteswap
    {
        T u;
        char bytes[size];

    } before, after;
    before.u = value;

    for (size_t i = 0; i < sizeof(T); i++){
        after.bytes[i] = before.bytes[size - 1 - i];
    }

    return after.u;
}

// Ex 3.
std::string show_flags(uint8_t value){
    std::bitset<8> x(value);
    std::stringstream ss("Options are:\n");

    for (size_t i = 0; i < options_strrepr.size(); i++){
        if (x[i] == true){
            ss << options_strrepr[i] << '\n';
        }
    }
    
    return ss.str();
}

// Ex 4.
std::string show_comb_flags(uint8_t value){
    std::bitset<8> x(value);
    std::stringstream ss("Combination of option:\n");

    for (size_t i = 0; i < combinations.size(); i++){
        if (combinations[i] & value == combinations[i]){
            ss << combination_strrepr[i] << '\n';
        }   
    }

    return ss.str();
}

// Ex 5.
std::bitset<10> find_commas(std::string& str){
    std::bitset<10> bm;
    for (size_t i = 0; i < str.size(); i++){
        bm.set(i, str[i] == ',');
    }
    return bm;
}


#endif // BITS
