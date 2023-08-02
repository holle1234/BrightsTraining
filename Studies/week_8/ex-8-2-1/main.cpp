#include "source/copy_move.h"
#include <iostream>
#include <type_traits>
#include <ostream>



// Testing Counter with increment calls
class Test1 : public counter_class::Counter<true, Test1>{

public:
    Test1(){increment_count(counter_class::type::def_constr);}
    ~Test1(){increment_count(counter_class::type::deconstr);}

    // copy constructor
    Test1(const Test1& rhs){
        increment_count(counter_class::type::copy);
    }
    // move constructor
    Test1(Test1&& rhs) noexcept {
        increment_count(counter_class::type::move);
    }
};

// Testing Counter with another class (count should be different with Test1)
class Test2 : public counter_class::Counter<true, Test2>{

public:
    Test2(){increment_count(counter_class::type::def_constr);}
    ~Test2(){increment_count(counter_class::type::deconstr);}

    // copy constructor
    Test2(const Test2& rhs){
        increment_count(counter_class::type::copy);
    }
    // move constructor
    Test2(Test2&& rhs) noexcept {
        increment_count(counter_class::type::move);
    }

    // copy-assignment
    Test2& operator=(const Test2& rhs){
        // this = move_assign(copy(rhs))
        return *this = Test2(rhs);
    }
    // move-assignment
    Test2& operator=(Test2&& rhs) noexcept {
        return *this;
    }
};


class InstanceCountTest : public counter_class::InstanceCounter<InstanceCountTest>{

public:

    InstanceCountTest(){}
    ~InstanceCountTest(){}

    // copy constructor
    InstanceCountTest(const InstanceCountTest& rhs) = delete;

    // move constructor
    InstanceCountTest(InstanceCountTest&& rhs) noexcept {
    }
    // move-assignment
    InstanceCountTest& operator=(InstanceCountTest&& rhs) noexcept {
        return *this;
    }
};



int main(int argc, char const *argv[])
{
    // Exercise 1
    int a;
    std::cout << std::boolalpha << is_lvalue(a) << '\n';
    std::cout << std::boolalpha << is_lvalue(a + 1) << '\n';

    // Exercise 2
    Test1 test1;
    {
        Test1 testl1;
        Test1 testl2;
        // copy constructor
        Test1 testl3 {testl2};
    }

    // copy-move
    Test2 test2;
    Test2 test22;
    test22 = test2;

    // move assign
    test22 = Test2();

    // move constr
    Test2 test222 = std::move(Test2());

    test1.show_debug_statistics();
    std::cout << '\n';
    test2.show_debug_statistics();

    // Exercise 3
    InstanceCountTest icount;
    icount.show_debug_statistics();

    // will not work because copy constructor is deleted
    // InstanceCountTest icount_copy = icount; 

    // works because overloaded move-assignment operator
    InstanceCountTest icount2;
    icount = std::move(icount2);
    icount.show_debug_statistics();
    
}