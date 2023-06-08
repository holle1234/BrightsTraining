//#define NDEBUG
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>


// Exercise 1
std::string capitalize_string(std::string input){
    char preChar {' '};
    for (size_t i = 0; i < input.length(); i++){

        if (preChar == ' '){
            input[i] = std::toupper(input[i]);}
        else{
            input[i] = std::tolower(input[i]);}

        preChar = input[i];
    }
    return input;
}

// Exercise 2
int factorial(int x){
    assert(x >= 0 && "use non negative numbers only!");

    int result {x};
    for (int i = x - 1; i > 0; i--){
        result *= i;
    }

    return result;
}

// Exercise 3
int sum(int a, int b){
    int results {a + b};
    assert(results > 0 && "sum is not positive");
    return results;

}

// Exercise 4
template <typename T>
T divide(T a, T b){
    assert(b != 0 && "Division by zero!");
    return a / b;
}


// Exercise 5
double square_root(double a){
    assert(a > 0 && "square root of negative number!");
    return std::sqrt(a);
}

// Exercise 6
bool play_game(int guess){
    bool result {(guess >= 1) && (guess <= 100)};
    assert((guess >= 1) && (guess <= 100) && "out of range!");
    return result;
}


int main() {

    int exerciseNumber {1};

    switch (exerciseNumber){
    case 1:{ // Exercise 1
        assert("The String Challenge" ==
        capitalize_string("the string challenge"));
        std::cout << "Test 1 passed" << std::endl;
        assert("This Is An Example, Should Work!" ==
        capitalize_string("THIS IS an ExamplE, should wORk!"));
        std::cout << "Test 2 passed" << std::endl;
        break;}

     case 2:{// Exercise 2
        int array[] {0, 1, 7, 3, -1};
        int results[] {0, 1, 5040, 6, -1};
        for (size_t i = 0; i < 5; i++){
            assert(factorial(array[i]) == results[i] && "factorial test failed");
        }
        break;}

    case 3:{// Exercise 3
        // with ndebug function runs normally even with negative returns
        for (int i = -1; i < 2; i++){
            std::cout << "sum test: " << i << "->" << sum(i, 0) << "\n";
        } 
        break;}

    case 4:{// Exercise 4
        // with ndebug and type double returning value is inf (no exception raised)
        // dividing with ints compiler will raise exception
        int value {2};
        for (int i = -1; i < 2; i++){
            std::cout << "division test: " << divide<double>(value, i) << "\n";
            //std::cout << "division test: " << divide<int>(value, i) << "\n";
        }
        break;}
    
    case 5:{// Exercise 5
        // with ndebug negative input will result to -nan
        for (int i = -1; i < 2; i++){
            std::cout << "Square root test: " << square_root(i) << "\n";
        }
        break;}

    case 6:{// Exercise 6
        int guesses[] {1, 5, 100, 0, 101};
        for (int i = 0; i < 5; i++){
            int value = guesses[i];
            std::cout << "ranger test " << value << ": " 
                      << play_game(value) << "\n";
        }
        break;}
    
    default: break;
    }
}

