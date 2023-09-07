#if !defined(MONADIC)
#define MONADIC

#include <string>
#include <variant>
#include <stdexcept>

namespace variant
{

enum class VariantType{
    human,
    alien,
    robot,
    invalid,
};


class Object
{
private:
    std::variant<std::monostate, double, int, std::string> data;
public:
    template<typename T>
    Object(T initial) : data(initial) {}
    Object() = default;

    template<typename T>
    void set(T value){
        data = value;
    }

    template<typename T>
    T get() const {
        if (!std::holds_alternative<T>(data)){
            throw std::invalid_argument("Type not present in variant!");
        }
        return std::get<T>(data);
    }

    VariantType check_type() const{
        return std::visit([&](const auto& arg){
            using T = std::decay_t<decltype(arg)>;
            if constexpr(std::is_same_v<T, std::monostate>){
                return VariantType::invalid;
            }
            else if constexpr(std::is_same_v<T, std::string>){
                return VariantType::human;
            }
            else if constexpr(std::is_same_v<T, double>){
                return VariantType::alien;
            }
            else if constexpr(std::is_same_v<T, int>){
                return VariantType::robot;
            }
            // just a placeholder if nothing goes. Some compilers may throw this 
            else static_assert(!std::is_same_v<T, T>, "Type not present in variant!");
        },
        data);
    }

};


} // namespace variant




#endif // MONADIC

