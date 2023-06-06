#include <iostream>

int main(){
    int curSalary {1};
    int curDay {1};

    while (curSalary < 10'000'000){
        curSalary *= 2;
        ++curDay;
    }
    std::cout << "You earned 10 million on day " << curDay << std::endl;

    return 0;
}