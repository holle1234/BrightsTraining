#if !defined(CONSTEXPRDECAY)
#define CONSTEXPRDECAY

#include <type_traits>

template<typename T, typename TT>
constexpr bool is_same_type(T first, TT second){
    return std::is_same_v<std::decay_t<T>, TT>;
}

#endif // CONSTEXPRDECAY
