#if !defined(CONSTEXPRDECAY)
#define CONSTEXPRDECAY

#include <type_traits>


// ex-1
template<typename T, typename TT>
constexpr bool is_same_type = std::is_same_v<T, TT>;

// ex-2
template<typename T>
constexpr bool can_decay = !std::is_same_v<std::decay_t<T>, T>;


#endif // CONSTEXPRDECAY
