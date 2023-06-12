#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <random>
#include <time.h>
#include <algorithm>
#include <iterator>


int randomBetween(int min, int max){
    
    static bool initDone {false};
    if (!initDone){
        std::srand(time(NULL));
        initDone = true;
    }
    return min + rand() % (( max + 1 ) - min);
}


template<typename T>
void printVector(std::vector<T>& vec){
    std::cout << "Vector values: ";
    for (auto &&i : vec){
        std::cout << i << " ";
    }
    std::cout << "\n";
}


std::vector<int> getRandomVector(int minValue, int maxValue, int minSize=1, int maxSize=10){
    std::vector<int> vec {};
    int randLenght {randomBetween(minSize, maxSize)};
    for (size_t i = 0; i < randLenght; i++){
        vec.push_back(randomBetween(minValue, maxValue));
    }
    return vec;
}


// Exercise 1:
void vectorPartition(){
    std::vector<int> vec {};
    for (size_t i = 0; i < 10; i++){
        vec.push_back(i);
    }

    // bi-directional iterator
    auto it = std::partition(vec.begin(), vec.end(), [](int i){return (i % 2) == 0;});
    // copy values from begin to it into cout
    std::copy(std::begin(vec), it, std::ostream_iterator<int>(std::cout, " "));
    // copy values from it to end into cout
    std::copy(it, vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
}

// Exercise 2:
void vectorIntersection(){
    std::vector<int> vec1 {getRandomVector(0, 10, 5, 10)};
    std::vector<int> vec2 {getRandomVector(0, 10, 5, 10)};

    // print vec1
    std::cout << "vector 1: ";
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // print vec2
    std::cout << "vector 2: ";
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // output vector
    std::vector<int> result;
    auto it = std::set_intersection(vec1.begin(), vec1.end(),
                                    vec2.begin(), vec2.end(), 
                                    std::back_inserter(result));
    std::cout << "intersection: ";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

// Exercise 3:
void vectorRotation(int n = 0){
    std::vector<int> vec {getRandomVector(0, 10, 5, 10)};
    std::cout << "Vector before rotate: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
   
    std::rotate(vec.rbegin(), vec.rbegin() + n, vec.rend());
    std::cout << "\nVector after rotate: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

// Exercise 4:
void adjacentSearch(std::list<int>& list){
    std::cout << "Finding adjacent elements from: ";
    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    auto it = std::adjacent_find(list.begin(), list.end());
    if (it == list.end()){std::cout << "No adj. elements!\n";}
    else {std::cout << "First adj. element at index " << std::distance(list.begin(), it)
        << " with value of " << *it;}

    std::cout << "\n";
}

// Exercise 5:



// Exercise 6:
template<size_t T>
void arrayMinMax(std::array<int, T>& arr){
    auto [min, max] {std::minmax_element(arr.begin(), arr.end())};
    std::cout << "stats of array {";
    for (auto &&i : arr){
        std::cout << i << ((i == arr.back()) ? "}\n" : " ");
    }
    std::cout << "min: " << *min << " max: " << *max << "\n";
}



int main(int argc, char const *argv[])
{
    // Exercise 1:
    vectorPartition();
    std::cout << "\n";

    // Exercise 2:
    vectorIntersection();
    std::cout << "\n";

    // Exercise 3:
    vectorRotation(3);
    std::cout << "\n";

    // Exercise 4:
    std::list<int> list1 {0,1,2,3,4,5,6,7,8,9};
    std::list<int> list2 {0,1,2,3,4,5,6,7,9,9};
    adjacentSearch(list1);
    adjacentSearch(list2);
    std::cout << "\n";

    // Exercise 5:
    std::cout << "ex 5: ";
    std::vector<int> vec = getRandomVector(1, 100, 1, 10);
    printVector(vec);
    std::cout << "\n";

    // Exercise 6:
    std::array<int, 3> arr {9,1,2};
    arrayMinMax(arr);
    std::cout << "\n";

    return 0;

}
