#if !defined(FUNCTEMPLATE)
#define FUNCTEMPLATE

#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <tuple>


template<typename F, typename... Args>
class MyClass
{

private:

    template<typename T, typename... Ts>
    void unpack_argument_types(size_t index=0){
        arguments[index] = typeid(T).name();
        if constexpr(sizeof...(Ts) > 0){
            unpack_argument_types<Ts...>(index+1);
        }
    }

public:

    constexpr static int size = sizeof...(Args);
    std::array<std::string_view, size> arguments;
    using ftype = F;

    MyClass(F(*f)(Args... args)) {
        // save argument types as strings
        unpack_argument_types<Args...>();
    }

    int get_size(){
        return size;
    }
    const char* get_type(){
        return typeid(ftype).name();
    }

};


#endif // FUNCTEMPLATE
