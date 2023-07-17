#if !defined(STATUS)
#define STATUS

#include <string>
#include <array>


enum class Status {
    ordered,
    received,
    processed,
    packed,
    delivered,
};


const std::array<std::string, 5> StrStatus{"ordered","received","processed","packed","delivered"};                                              



class Order
{
private:
    Status status {Status::ordered};
    size_t istatus {0};

public:
    // Advance order state
    void advance();
    // Get status
    Status get_status();
    // Printable status
    std::string get_status_str();
};

#endif // STATUS