#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../source/uint.h"
#include <cstdint>


// test uint class init
TEST_CASE("INIT TEST"){
    // inits
    Uint a =  0;
    Uint b = {1LL};
    Uint c = {a};
    Uint d   {-5};
    Uint e   {a};
    Uint f =  a;
    Uint g {std::numeric_limits<long>::min()};
    Uint h = {std::numeric_limits<long>::max()};
    Uint copy1, copy2;
    copy1 = a;                                                     
    copy2 = static_cast<std::int16_t>(-1);                

    CHECK(a.value == 0);
    CHECK(b.value == 1);
    CHECK(c.value == 0);
    CHECK(d.value == 0);
    CHECK(e.value == 0);
    CHECK(f.value == 0);
    CHECK(g.value == 0);
    CHECK(h.value == umax);

    CHECK(copy1.value == 0);
    CHECK(copy2.value == 0);
}

// test uint class init
TEST_CASE("MATH TEST"){
    // inits with valid value
    Uint uintmin  =  umin;
    Uint uint1    =  1;
    Uint uintmax  =  umax;
    Uint uintx    =  umax - 5;

    int one            = 1;
    int n_one          = -1;
    int two            = 2;
    long lmax          = std::numeric_limits<long>::max();
    long lmin          = std::numeric_limits<long>::min();
    unsigned int uimax = std::numeric_limits<unsigned int>::max();

    SUBCASE("MINUS"){
        CHECK(uintmin - one   == 0);
        CHECK(uintmin - n_one == 1);
        CHECK(uintmin - lmax  == 0);
        CHECK(uintmin - lmin  == uimax);
        CHECK(uintmin - uimax == 0);

        CHECK(uintmax - one   == uimax - 1);
        CHECK(uintmax - n_one == uimax);
        CHECK(uintmax - lmax  == 0);
        CHECK(uintmax - lmin  == uimax);
        CHECK(uintmax - uimax == 0);

        CHECK(uintmax - uint1 == uimax - 1);
        CHECK(uintmin - uint1 == 0);
        CHECK(uintx   - (-4)  == uimax - 1);
        
    }
    SUBCASE("PLUS"){
        CHECK(uintmin + one   == 1);
        CHECK(uintmin + n_one == 0);
        CHECK(uintmin + lmax  == uimax);
        CHECK(uintmin + lmin  == 0);
        CHECK(uintmin + uimax == uimax);

        CHECK(uintmax + one   == uimax);
        CHECK(uintmax + n_one == uimax - 1);
        CHECK(uintmax + lmax  == uimax);
        CHECK(uintmax + lmin  == 0);
        CHECK(uintmax + uimax == uimax);

        CHECK(uintmax + uint1 == uimax);
        CHECK(uintmin + uint1 == 1);
        CHECK(uintx   + (-4)  == uimax - 9);
    }

    SUBCASE("MINUS LITERAL"){
        CHECK(uintmin - 1     == 0);
        CHECK(uint1   - (-1)  == 2);
        CHECK(uintmax - (-1)  == umax);
        CHECK(uint1   - true  == 0);
    }
    SUBCASE("PLUS LITERAL"){
        CHECK(uintmin + 1     == 1);
        CHECK(uint1   + (-1)  == 0);
        CHECK(uintmax + (-1)  == umax - 1);
        CHECK(uint1   + true  == 2);

    }
}

