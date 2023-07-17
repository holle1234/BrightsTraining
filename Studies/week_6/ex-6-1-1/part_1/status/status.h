#include <random>
#include <array>

// Random between, hidden from main view
namespace rndBtw{int randomBetween(int min, int max);};


enum class Status {
    success,
    error_1,
    error_2,
    error_3,
    error_undefined,
};

constexpr const std::array<Status, 5> Statuses{Status::success,
                                               Status::error_1,
                                               Status::error_2,
                                               Status::error_3,
                                               Status::error_undefined};

// returns a status object
Status get_random_status(int for_test_purposes = 0);

// prints a message belonging to the spesific status
void print_status_message(Status status);
