/* 

UNIT TESTING

Make tests with terminal
Dont forget to include all cpp files to the list
You will see the results after running test.exe


FLOW:

Create tests/results & move into tests
mkdir tests && mkdir tests/results && cd tests

Include files conserning the test & give path to test exe & direct test results to .txt
g++ ./make_tests.cpp ../transactions/finance_tracker.cpp  -o ./results/test.exe && ./results/test.exe >> ./results/results.txt


 */


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../transactions/finance_tracker.h"

TEST_CASE("TEST MATH"){

    CHECK(preprocess_deposit(-10) == 10);
    CHECK(preprocess_deposit(10) == 10);

    CHECK(preprocess_withdraw(10) == -10);
    CHECK(preprocess_withdraw(-10) == -10);

}