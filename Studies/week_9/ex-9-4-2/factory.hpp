#if !defined(FACTORY)
#define FACTORY

#include "expected.hpp"
#include <optional>
#include <ostream>

class Factory
{
private:
    int id {0};
    Factory() = default;
    Factory(int id = 0) : id(id){};

public:

    static std::optional<Factory> create(int new_id){
        if (new_id > 0){
            return Factory {new_id};
        }
        return std::nullopt;
    }

    static tl::expected<Factory, std::string> create_exp(int new_id){
        if (new_id > 0){
            return Factory {new_id};
        }
        return tl::unexpected("Unexpected value in Factory message");
    }

    friend std::ostream& operator<<(std::ostream& os, const Factory& fac);

};


#endif // FACTORY
