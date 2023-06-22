#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <random>
#include <time.h>
#include <algorithm>
#include <iomanip>


int randomBetween(int min, int max){
    
    static bool initDone {false};
    if (!initDone){
        std::srand(time(NULL));
        initDone = true;
    }
    return min + rand() % (( max + 1 ) - min);
}


template<std::size_t S>
void printStdArray(std::array<int, S>& arr){
    for (auto &&i : arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
template<typename T>
void printVector(std::vector<T>& vec){
    std::cout << "Vector values: ";
    for (auto &&i : vec){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

//Exercise 1
int* createArray(int min, int max){
    static int myArray[10];
    for (size_t i = 0; i < 10; i++){
        myArray[i] = randomBetween(min, max);
    }
    std::cout << "printing dummy basic array\n";
    for (auto &&i : myArray){
        std::cout << i << " ";
    }
    std::cout << "\n\n";
    return myArray;
}

//Exercise 2
template<std::size_t S>
bool isInArray(std::array<int, S>& arr, int x){
    auto it {std::find(arr.begin(), arr.end(), x)};
    if (it != arr.end()){
        return true;
    }
    return false;
}

//Exercise 3
template<std::size_t S>
int sumOfArray(std::array<int, S>& arr){
    return std::accumulate(arr.begin(), arr.end(), 0);
}

//Exercise 4
template<std::size_t S>
int productOfArray(std::array<int, S>& arr){
    return std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<int>());
}

// Exercise 5:
template<typename T>
int changeVectorSize(std::vector<T>& vec){
    std::cout << "Vector size now is: " << vec.size() << "\n";
    std::cout << "Give new size: ";
    int newSize;
    std::cin >> newSize;
    vec.resize(newSize, 0);
    std::cout << "New size: " << vec.size() << "\n";
    return newSize;
}

// Exercise 6:
void listMinMax(std::list<int>& myList){
    auto [min, max] {std::minmax_element(myList.begin(), myList.end())};
    std::cout << "stats of list {";
    for (auto &&i : myList){
        std::cout << i << ((i == myList.back()) ? "}\n" : " ");
    }
    std::cout << "min: " << *min << " max: " << *max << "\n";
}

// Exercise 7:
template<typename T, typename R>
void removeElement(std::vector<T>& v, R target){
    // erase remove idiom
    // erase needs an index-iterator to remove and shit elements
    // this causes a lot of overhead
    // remove finds the elements specified by criteria and shifts whole array at once
    // remove returns an iterator to the removed objects that can be passed to erase
    // remove does not modify arrays lenght
    // erase will then remove these values from the end of array

    v.erase(std::remove(v.begin(), v.end(), target), v.end());
}


int main(int argc, char const *argv[])
{
    // Exercise 1
    int* arr {createArray(0, 10)};

    // Exercise 2

    std::array<int, 5> stdArr {1,2,3,4,6};
    std::cout << "Using the following array for tests: ";
    printStdArray(stdArr);

    int test {5};
    bool find5 {isInArray(stdArr, test)};
    std::cout << test << (find5 ? " in" : " not in") << " array\n";

    // Exercise 3
    std::cout << "Sum of array: " << sumOfArray(stdArr) << "\n";

    // Exercise 4:
    std::cout << "Product of array: " << productOfArray(stdArr) << "\n\n";

    // Exercise 5:
    std::vector<int> vec {0, 1, 2};
    printVector(vec);
    changeVectorSize(vec);
    printVector(vec);
 
    // Exercise 6:
    std::cout << "\n";
    std::list<int> myList {1,2,3};
    listMinMax(myList);

    // Exercise 7:
    std::cout << "\nRemove zeros\n";
    printVector(vec);
    removeElement(vec, 0);
    printVector(vec);

}
