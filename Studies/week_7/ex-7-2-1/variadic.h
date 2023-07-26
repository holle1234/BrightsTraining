#if !defined(VARIADIC)
#define VARIADIC
#include <type_traits>
#include <iostream>
#include <vector>


// Exercise 1a.
template<typename T>
int print1a(T value){
    std::cout << value << "\n";
    return 1;
}

template<typename T, typename... Ts>
int print1a(T value, Ts... args){
    std::cout << value << " ";
    return 1 + print(args...);
}

// Exercise 1b.
template<typename T, typename... Ts>
int print1b(T value, Ts... args){
    std::cout << value << " ";
    if constexpr(sizeof...(Ts) > 0){
        return 1 + print1b(args...);
    }
    return 1;
}

//Exercise 2.
template<typename T, typename... Ts>
int sum(T value, Ts... args){
    if constexpr(sizeof...(Ts) > 0){
        if constexpr(std::is_integral_v<T>)
            return value + sum(args...);
        return sum(args...);
    }
    if constexpr(std::is_integral_v<T>)
        return value;
    return 0;
}


//Exercise 3.
template<typename T, typename... Ts>
bool all_the_same(T value, Ts... args){
    return std::conjunction_v<std::is_same<T, Ts>...>;
}

//Exercise 4. (2.)
template<typename T, typename... Ts>
T _product(T value, Ts... args){
    if constexpr(sizeof...(Ts) > 0){
        return value * _product(args...);
    }
    return value;
}

//Exercise 4. (1.)
template<typename T, typename... Ts,
    typename std::enable_if_t<std::conjunction_v<std::is_same<T, Ts>...> && std::is_arithmetic_v<T>, int> = 0>
T product(T value, Ts... args){
    if constexpr(sizeof...(Ts) > 0){
        return (sizeof...(Ts) + 1) * value * _product(args...);
    }
    return value;
}

//Exercise 5.

template<typename T, typename C, typename... Ts>
void concat(std::vector<T>& dest, C&& cont, Ts... args){

    for (auto &&i : cont){
        dest.push_back(i);
    }
    if constexpr(sizeof...(Ts) > 0){
        return concat(dest, args...);
    }
    return;
}




#endif // VARIADIC
