#include <iostream>
#include <typeinfo>


template <typename T>
T testfunc(T a){
    return a + 1;
}


int main(){
    int a {0};
    double b {0};

    std::cout << typeid(a).name() << " arg " << testfunc(a) << "\n";
    std::cout << typeid(b).name() << " arg " << testfunc(b) << "\n";

    return 0;
}