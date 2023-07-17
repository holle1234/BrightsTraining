#include "status.h"
#include <iostream>


// Random values between min & max
namespace rndBtw{

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    
    // randon range int
    int randomBetween(int min, int max){
        std::uniform_int_distribution<int> distr(min, max);

        return distr(generator);
    }
};

Status get_random_status(int for_test_purposes){
    // note: for_test_purposes allows picking non valid state that can lead to undefined behaviour
    int istatus {for_test_purposes};
    if (!for_test_purposes){
        istatus = rndBtw::randomBetween(0, Statuses.size() - 2);
    }

    return Statuses[istatus];
}

void print_status_message(Status status){
    switch (status)
    {
    case Status::success:
        std::cout << "success!";
        break;
    case Status::error_1:
        std::cout << "error_1!";
        break;
    case Status::error_2:
        std::cout << "error_2!";
        break;
    case Status::error_3:
        std::cout << "error_3!";
        break;    
    default:
        throw std::invalid_argument("Status object not present in switch!\n");
        break;
    }
}