/* 
Create a header file that contains definition for enum class "status", and add a
success status, and couple of error statuses
Create a function that returns a status code at random
Create a program to call the function and handle the status using `switch`-statement
 */

#include "status/status.h"
#include <iostream>

/* 
This solution demonstrates how to pick random enum class state.
Program demonstrates behaviour of switch with enum classses.
For demonstration purposes, possibility to insert invalid state to the print function was added.

FLOW:
    - make a constant array of all the states
    - pick random number that is in the range of array
    - return enum-value from array at index

 */

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 5; i++){
        Status status = get_random_status();
        std::cout << "Random status " << i << ": ";
        print_status_message(status);
        std::cout << "\n";
    }

    // unprepared value
    int invalid_index {Statuses.size() - 1};
    Status status = get_random_status(invalid_index);
    std::cout << "Random status upprepared" << ": ";
    print_status_message(status);
    
    return 0;
}
