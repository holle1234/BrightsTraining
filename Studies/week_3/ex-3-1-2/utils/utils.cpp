#include "utils.h"
#include <random>
#include <algorithm>
#include <vector>


// randon range gen
double randomBetween(double min, double max){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}


double initSensor(int sensor){
    double minLimit {SENSOR_MIN_MAX[sensor][0]};
    double maxLimit {SENSOR_MIN_MAX[sensor][1]};
    return (minLimit + maxLimit) / 2;

}

// initialize weather data
std::vector<double> generateWeatherData(){
    std::vector<double> data;

    // generate data for each type of readings
    for (size_t i = 0; i < DATA_HEADERS.size(); i++){
        data.push_back(initSensor(i));
    }
    return data;
    
}

bool isValidReading(int sensor, double reading){
    double minLimit {SENSOR_MIN_MAX[sensor][0]};
    double maxLimit {SENSOR_MIN_MAX[sensor][1]};

    return (reading >= minLimit) && (reading <= maxLimit);
}

double generateUpdate(double reading){
    reading *=  randomBetween(0.95, 1.05);
}

// initialize values to default if they fall outside range
void  updateReading(std::vector<double>& readings){

    for (size_t i = 0; i < DATA_HEADERS.size(); i++){
        double newValue = generateUpdate(readings[i]);
        if (isValidReading(i, newValue)){
            readings[i] = newValue;
        }
        else{
            readings[i] = initSensor(i);
        }
    }
    
}

