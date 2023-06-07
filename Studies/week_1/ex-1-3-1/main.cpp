#include <iostream>
#include <array>


// Exercise 1:          
void exercise_1(){                  
    int value {0};                  // value can be accessed from this function only
    std::cout << value;
}

// Exercise 2:
void exercise_2(){
    for (size_t i = 0; i < 5; i++){
        int value {0};
    }
    // std::cout << value;          //value is declared in for loops scope and can only be accessed from there
}

// Exercise 3:
void calculate(){
    int value_in_calc {0};          // value lives in function scope (not a global)
    std::cout << value_in_calc;
}


// Exercise 4:
void exercise_4(){
    {
        int value {99};
        std::cout << value;         // ok, value accessed inside block-scope
    }
    //std::cout << value;           // wrong, value accessed outside block-scope
}

// Exercise 5:
void exercise_5(){
    int value {0};
    std::cout << value << "\n";
    if (value == 0){                
        value = 1;                  // will modify value in if scope conditionally
    }
    std::cout << value << "\n";
}

// Exercise 6:
void modifier(int& a){a = 1;}

void exercise_6(){
    int value {99};                 // if parameters are passed by value they are copies of the original
    std::cout << value << "\n";             // will print 99
    modifier(value);                // will print 1 because it was passed by reference
    std::cout << value << "\n";           
}

// Exercise 7
struct MyStruct
{
    private:
        int _var {0};

    public:
        int getter(){
            return _var;
        }

        int setter(int a){
            _var = a;
            return _var;
        }
};

// Exercise 8
void arrayPrinter(int *arr, int size){
    for (size_t i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void arrayCreator(){
    int size {5};
    int *arr = new int[size];
    for (size_t i = 0; i < size; i++){
        arr[i] = i;
    }

    arrayPrinter(arr, size);                   // prints 0 1 2 3 4
    delete[] arr;                              // deallocates memory of the array
}

// Exercise 9
int staticVarFunc(){
    static int counter {0};
    counter++;
    return counter;
}

// Excercise 10
namespace mySpace{
    int myVar {0}; 
}

void mySpacePrinter(){                          // objects can be accessed from namespace using ::
    int myVar {0};                              // abstracts naming from global namespace
    std::cout << mySpace::myVar                 // only adds mySpace as a global via myVar is accessed
              << " " << myVar << "\n";
    ++mySpace::myVar;                           // myVar has been modified
    std::cout << mySpace::myVar
              << " " << myVar << "\n";
}


int main(){
    //std::cout << value_in_calc;               // wrong, value lives only in calculate function 
    MyStruct st;
    std::cout << st.getter() << "\n";           // gets private value that cannot be accessed otherwise
    std::cout << st.setter(10) << "\n";         // gets private value that cannot be accessed otherwise
    //st._var = 0;                              // will fail! value is private can be accessed only from inside the class
    arrayCreator();                             // Untill you destory the object it remains in memory (programs lifetime)
                                                // and can be accessed by pointer to it
    
    for (size_t i = 0; i < 3; i++){             // static variables are initialized only once
        std::cout << staticVarFunc() << " ";    // after the first call initialization is skipped
    } std::cout << "\n";

    mySpacePrinter();    
    
    return 0;
}