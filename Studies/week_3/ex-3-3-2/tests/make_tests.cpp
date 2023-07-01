#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../utils/utils.h"


// Test that all math functions return right results
TEST_CASE("MATH FUNCTIONS TESTS"){
    MESSAGE("Testing add");
    CHECK(add(0, 0) == 0);
    CHECK(add(-1, 0) == -1);
    CHECK(add(-1, -1) == -2);

    MESSAGE("Testing substract");
    CHECK(substract(0, 0) == 0);
    CHECK(substract(-1, 0) == -1);
    CHECK(substract(-1, -1) == 0);

    MESSAGE("Testing multiply");
    CHECK(multiply(1, 0) == 0);
    CHECK(multiply(-1, 2) == -2);
    CHECK(multiply(1, 2) == 2);

    MESSAGE("Testing devide");
    CHECK(devide(1, 0) == 0); // zero devision should return 0
    CHECK(devide(10, -0) == 0); // zero devision should return 0
    CHECK(devide(-10, 2) == -5);
    CHECK(devide(10, 2) == 5);
    CHECK_THROWS(devide(10, std::numeric_limits<double>::infinity())); // check for inf
    CHECK_THROWS(devide(10, std::numeric_limits<double>::quiet_NaN())); // check for nan
};

// Test that all string functions return right results
TEST_CASE("STRING FUNCTIONS TESTS"){

    MESSAGE("Testing reverse str");
    CHECK(reverse_string("lol this") == "siht lol");
    CHECK(reverse_string("") == "");
    CHECK(reverse_string("12") == "21");
    CHECK(reverse_string("12&") == "&21");

    MESSAGE("Testing toupper str");
    CHECK(toupper_string("lol") == "LOL");
    CHECK(toupper_string("") == "");
    CHECK(toupper_string("l0l") == "L0L");
    CHECK(toupper_string("12&%") == "12&%");
    CHECK(toupper_string("öä") == "öä"); // unicode is not converted

    MESSAGE("Testing tolower str");
    CHECK(tolower_string("LOL") == "lol");
    CHECK(tolower_string("") == "");
    CHECK(tolower_string("L0L") == "l0l");
    CHECK(tolower_string("12&%") == "12&%");
    CHECK(tolower_string("ÖÄ") == "ÖÄ"); // unicode is not converted

    MESSAGE("Testing palindrome str");
    CHECK(is_string_palindrome("lol") == true);
    CHECK(is_string_palindrome("saippuakauppias") == true);
    CHECK(is_string_palindrome("") == true);
    CHECK(is_string_palindrome("123") == false);
    CHECK(is_string_palindrome("1221") == true);

};