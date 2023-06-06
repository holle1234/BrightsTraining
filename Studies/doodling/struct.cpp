#include <iostream>


struct MyStruct{
    int a {0};
    double b {0.0};

    double getB(){
        return b;
    }

};


int main(){

    MyStruct st {1,2};                  // list init
    std::cout << "a = " << st.a << "\n";

    st.b = 100.0;                       // value set with .
    std::cout << "b = " << st.b << "\n";

    std::cout << st.getB() << "\n";     // callin struct func

    return 0;
}