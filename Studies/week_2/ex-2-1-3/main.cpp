#include <algorithm>
#include <vector>
#include <iostream>
#include <array>
#include <iterator>


using MyPair = std::pair<std::string, int>;
using VectorOfPairs = std::vector<MyPair>;



int randomBetween(int min, int max){
    
    static bool initDone {false};
    if (!initDone){
        std::srand(time(NULL));
        initDone = true;
    }
    return min + rand() % (( max + 1 ) - min);
}


std::vector<int> getRandomVector(int minValue, int maxValue, int minSize=1, int maxSize=10){
    std::vector<int> vec {};
    int randLenght {randomBetween(minSize, maxSize)};
    for (size_t i = 0; i < randLenght; i++){
        vec.push_back(randomBetween(minValue, maxValue));
    }
    return vec;
}


// overload cout << VectorOfPairs for ease printing
std::ostream &operator<<(std::ostream& os, const VectorOfPairs& pairVec) {
    std::string out {"VectorOfPairs: "};
    for (auto &&pair : pairVec){
        out += "(" + pair.first + + ", " + std::to_string(pair.second) + ") ";
    }
    return os << out;
}

// Exercise 1 sorts an array of integers in ascending order
template<size_t S>
void sortArrayAsc(std::array<int, S>& arr){
    std::cout << "array befofe sort: ";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

    std::sort(arr.begin(), arr.end());

    std::cout << "\narray after sort: ";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}


// Exercise 2 integers in descending order.
template<size_t S>
void sortArrayDesc(std::array<int, S>& arr){
    std::cout << "array befofe sort: ";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

    std::sort(arr.begin(), arr.end(), std::greater<int>());
    
    std::cout << "\narray after sort: ";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}


// Exercise 3/4 sort asc
template<typename T>
void sortVectorAsc(std::vector<T>& vec){
    std::cout << "vector befofe sort: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));

    std::sort(vec.begin(), vec.end());
    
    std::cout << "\nvector after sort: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << "\n";
}

// Exercise 4 sort by length
void sortVectorByLength(std::vector<std::string>& vec){
    std::cout << "vector befofe sort: ";
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<std::string>(std::cout, " "));

    std::sort(vec.begin(), vec.end(), 
             [](const std::string& a, const std::string& b)
             {return a.length() < b.length();});
    
    std::cout << "\nvector after sort: ";
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << "\n";
}


// Exercise 5/8 sort pairs by second value
void sortPair(VectorOfPairs& pairVec, int index = 0){

    std::cout << "vector befofe sort: " << pairVec;
    
    std::sort(pairVec.begin(), pairVec.end(), 
             [&index](const auto& a, const auto& b)
             {
                if(index == 0){return a.first < b.first;}
                else {return a.second < b.second;}
             });
    
    std::cout << "\nvector after sort: " << pairVec;

    std::cout << "\n";
}


// Exercise 7 partial sort
template<typename T>
void partialSort(std::vector<T>& vec, int nMax){
    std::cout << "\nvector before sort: ";
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<T>(std::cout, " "));

    std::partial_sort(vec.rbegin(),vec.rbegin() + nMax, vec.rend(), std::greater{});

    std::cout << "\nTop " << nMax << " elements: ";
    std::copy(vec.rbegin(), vec.rbegin() + nMax,
              std::ostream_iterator<T>(std::cout, " "));
}



int main(int argc, char const *argv[])
{
    // test data
    std::array<int, 5> arr {1,5,3,2};
    std::vector<double> vec1 {1.999,5.1,3.42,2.01};
    std::vector<float> vec2 {0.1,0.1001};
    std::vector<std::string> vec3 {"aa", "acb", "ab", "b", "0"};
    VectorOfPairs pairVec {MyPair{"simo", 15},
                           MyPair{"aleksi", 10},
                           MyPair{"jorma", 80}};

    // Exercise 1 
    std::cout << "Exercise 1\n";
    sortArrayAsc(arr);

    std::cout << "\n";

    // Exercise 2
    std::cout << "Exercise 2\n";
    sortArrayDesc(arr);

    std::cout << "\n";

    // Exercise 3
    std::cout << "Exercise 3\n";
    sortVectorAsc(vec1);
    std::cout << "\n";
    sortVectorAsc(vec2);

    std::cout << "\n";

    // Exercise 4
    std::cout << "Exercise lex4\n";
    sortVectorAsc(vec3);
    std::cout << "Exercise 4 len\n";
    sortVectorByLength(vec3);

    std::cout << "\n";

    // Exercise 5
    sortPair(pairVec, 0);

    std::cout << "\n";

    // Exercise 7
    std::vector<int> randVec {getRandomVector(0, 100, 20, 30)};
    partialSort(randVec, 5);

    std::cout << "\n";

    // Exercise 8 (The order of equal elements is not guaranteed to be preserved)
    VectorOfPairs repPVec {MyPair{"a", 5},
                           MyPair{"a", 4},
                           MyPair{"a", 3},
                           MyPair{"a", 2},
                           MyPair{"a", 1}};
    sortPair(repPVec, 0);
    std::cout << "\n";

    return 0;
}
