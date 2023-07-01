#include <iostream>
#include <random>


// randon range double
double randomBetween(double min, double max){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}

// randon range int
double randomBetween(int min, int max){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(min, max);
    return distr(generator);
}



int main(int argc, char const *argv[])
{
    // random range int
    std::cout << "Int\n";
    for (int i = 0; i < 5; i++){
        std::cout << randomBetween(0, i) << "\n";
    }
    std::cout << "Double\n";
    for (int i = 0; i < 5; i++){
        double di = static_cast<double>(i);
        std::cout << randomBetween(0.0, di) << "\n";
    }

    return 0;
}
