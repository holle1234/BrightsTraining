#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("TEST PASCAL"){
    CHECK(sum_right(1,1) == 2);
    CHECK(sum_wrong(1,1) == 2);
}