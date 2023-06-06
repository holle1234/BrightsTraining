#include <iostream>
#include <list>
#include <cmath>
#include <numeric>
#include <algorithm>


int sumList(const std::list<int>& l){
    int result {std::accumulate(l.begin(), l.end(), 0)};
    return result;
}

double averageList(const std::list<int>& l){
    double result {sumList(l) / double(l.size())};
    return result;
}

int minList(const std::list<int>& l){
    int result {*std::min_element(l.begin(), l.end())};
    return result;
}

int maxList(const std::list<int>& l){
    int result {*std::max_element(l.begin(), l.end())};
    return result;
}

int mostCommonList(const std::list<int>& l){
    int maxElement {0};
    int maxCount {0};

    for (auto &&i : l){
        int count {0};
        for (auto &&x : l){
            if (i == x){
                count++;
            }
        }
        if (count > maxCount){
            maxElement = i;
            maxCount = count;
        }
    }
    
    return maxElement;
}

int minMaxDiffList(const std::list<int>& l){
    int result {std::abs(maxList(l) - minList(l))};
    return result;
}


int main(){

    std::list<int> intList {};
    int nValues {0};

    std::cout << "Enter the number of values to inspect (int): ";
    std::cin >> nValues;

    for (size_t i = 0; i < nValues; i++){
        std::cout << "Number " << i + 1 << ": ";
        int temp {};
        std::cin >> temp;
        intList.push_back(temp);
    }

    for (int i : intList){
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << "Sum: " << sumList(intList) << std::endl;
    std::cout << "Average: " << averageList(intList) << std::endl;
    std::cout << "Min Element: " << minList(intList) << std::endl;
    std::cout << "Max Element: " << maxList(intList) << std::endl;
    std::cout << "Most common Element: " << mostCommonList(intList) << std::endl;
    std::cout << "Difference between min and max value: " << minMaxDiffList(intList) << std::endl;
    

    return 0;
}