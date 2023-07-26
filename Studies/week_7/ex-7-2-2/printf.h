#if !defined(PRINTF)
#define PRINTF

#include <string>
#include <type_traits>
#include <array>


constexpr static std::array<std::string_view, 5> print_formats {"%c", "%d", "%f", "%s", "%u"};


template<typename T>
bool helper(const std::string_view& ref, T arg){
    if (ref == print_formats[0]){
        return std::is_same_v<T, char>;
    }
    else if (ref == print_formats[1]){
        return std::is_integral_v<T> && !std::is_same_v<T, char> && !std::is_same_v<T, bool>;
    }
    else if (ref == print_formats[2]){
        return std::is_floating_point<T>::value;
    }
    else if (ref == print_formats[3]){
        return std::is_same_v<T, std::string>;
    }
    else if (ref == print_formats[4]){
        return std::is_unsigned_v<T> && std::is_integral_v<T> && !std::is_same_v<T, bool>;
    }

    return false;
}


template<typename T, typename... Ts>
bool check_format(const std::string_view& ref, T arg, Ts... args){

    if constexpr(sizeof...(args) > 0){
        return helper(ref, arg) && check_format(ref, args...);
    }

    return helper(ref, arg);
}


template <std::size_t N>
struct Example
{
    constexpr static size_t size{N};

    template <typename... Ts>
    Example(Ts...) {};

    size_t parameter_count(){
        return size;
    }

    template<typename... Ts>
    void require_count(Ts... params){
        static_assert(sizeof...(Ts) == size);
    }
};

template <typename... Ts>
Example(Ts...) -> Example<sizeof...(Ts)>;


#endif // PRINTF
 