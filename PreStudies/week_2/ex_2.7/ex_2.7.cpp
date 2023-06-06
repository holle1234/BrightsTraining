#include <iostream>
#include <vector>



int main(){
    int fibonacci10[10] {0, 1};
    int nNumbersToCalculate {10};
    
    for (size_t i = 1; i < (nNumbersToCalculate - 1); i++){
        int nextFib {fibonacci10[i-1] + fibonacci10[i]};
        fibonacci10[i+1] = nextFib;
    }

    for (auto i = std::begin(fibonacci10); i != std::end(fibonacci10); i++){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}