#if !defined(COPY_MOVE)
#define COPY_MOVE

#include <iostream>
#include <type_traits>
#include <ostream>

// Exercise 1
template<typename T>
constexpr bool is_lvalue(T&& arg){
    return std::is_lvalue_reference_v<T>;
}

// Exercise 2
// Count stuff on class level
namespace counter_class
{

enum class type{
    copy,
    move,
    def_constr,
    deconstr,
    instance,
};
    
template<bool console, typename T>
class Counter
{
private:
    inline static int call_count_default_constructor = 0;
    inline static int call_count_copy_constructor = 0;
    inline static int call_count_move_constructor = 0;
    inline static int call_count_destructor = 0;
    inline static int instance_count = 0;

    static int _change_count(type t=type::copy, int op=0){
        switch (t)
        {
        case type::copy :{
            call_count_copy_constructor += op;
            return call_count_copy_constructor;}
        case type::move :{
            call_count_move_constructor += op;
            return call_count_move_constructor;}
        case type::def_constr :{
            call_count_default_constructor += op;
            return call_count_default_constructor;}
        case type::deconstr :{
            call_count_destructor += op;
            return call_count_destructor;}
        case type::instance :{
            instance_count += op;
            return instance_count;}
        }

        return -1;
    }

public:

    static void increment_count(type t){_change_count(t, +1);}
    static void decrement_count(type t){_change_count(t, -1);}
    static int tally(type t) {return _change_count(t);}

    Counter(){
        increment_count(type::instance);
        if (console){std::cout << "Default constr. class type of " << typeid(T).name() << '\n';}
    }
    ~Counter(){
        decrement_count(type::instance);
        if (console){std::cout << "Destroyed class type of " << typeid(T).name() << '\n';}
    }

    static void show_debug_statistics(){

        if(!console){return;}
        std::cout << "Object type " << typeid(T).name() << '\n'
        << "-call_count_default_constructor : " << call_count_default_constructor << '\n'
        << "-call_count_copy_constructor    : " << call_count_copy_constructor << '\n'
        << "-call_count_move_constructor    : " << call_count_move_constructor << '\n'
        << "-call_count_destructor          : " << call_count_destructor << '\n'
        << "-instance_count                 : " << instance_count << '\n';
    }
};

// Exercise 3.
template<typename T>
class InstanceCounter
{
private:
    inline static int instance_count = 0;
public:
    static int tally(type t) {return instance_count;}

    InstanceCounter(){
        instance_count++;
    }
    ~InstanceCounter(){
        instance_count--;
    }

    static void show_debug_statistics(){
        std::cout << "Object type " << typeid(T).name()
        << "has " << instance_count << " alive instances \n";
    };

};


} // namespace counter_class

#endif // COPY_MOVE
