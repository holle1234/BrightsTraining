#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../utils/utils.h"
#include <vector>


/* 
FLOW:
create dir unittests
cd to it
create dir results
build make_tests.cpp with g++ include paths to testable cpps and set -o for exe, run exe and redirect output to a file in results

 */

std::string stringEmpty         {};
std::string stringNumber        {"1"};
std::string stringAlpha         {"a"};
std::string stringMultiAlpha    {"aa"};
std::string stringValid         {"12"};
PascalVector pVectEmpty         {};
PascalVector pVecFilled         {1};

TEST_CASE("TEST PASCAL UTILS"){

    // check string to int conversion
    CHECK_THROWS(sToInt(stringEmpty));
    CHECK_THROWS(sToInt(stringAlpha));
    CHECK_THROWS(sToInt(stringMultiAlpha));
    CHECK(sToInt(stringValid) == 12);

    // check depth calculations
    CHECK(calculateTriangleDepthFromVectorSize(15)==5);
    CHECK(calculateTriangleDepthFromVectorSize(28)==7);
    CHECK_THROWS(calculateTriangleDepthFromVectorSize(27));

}

TEST_CASE("TEST PASCAL FUNCT"){

    // check for invalid depth
    CHECK_THROWS(pascal(pVectEmpty, 1, 0));
    CHECK_THROWS(pascal(pVectEmpty, 1, -1));
    CHECK_THROWS(pascal(pVecFilled, 1, 6));

}