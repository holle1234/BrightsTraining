#include "utils.h"
#include "../csv/csv.h"
#include <random>
#include <algorithm>
#include <vector>




// find option from terminal prompt
const char** find_option(const char** begin, const char** end, std::string option){
    return std::find(begin, end, option);
}


std::vector<double> to_double_vector(csv::StringRow& source){
    std::vector<double> dest;
    for (size_t i = 0; i < source.size(); i++){
        double value {std::stod(source[i])};
        dest.push_back(value);
    }
    return dest;
}


// read logs
void print_logs(){

    int cell_max_size {PRETTY_PRINT_CELL_SIZE};
    csv::StringRow row;
    csv::CSVReader logreader {LOGPATH};
    logreader.open();

    // print data
    while (logreader.readLine(row)){
        csv::pretty_print(row, cell_max_size);
        std::cout << "\n";
    }
    // last row is the most recent weather
    logreader.close();
}


// read logs
void read_log_last_entry(){

    csv::StringRow row;
    csv::CSVReader logreader {LOGPATH};
    logreader.open();

    // print headers
    std::cout << "Current Weather:\n";
    logreader.readLine(row);
    csv::pretty_print(row, PRETTY_PRINT_CELL_SIZE);

    // print last row
    logreader.read_last_line(row);
    updateReadings(row);
    std::cout << "\n";
    csv::pretty_print(row, PRETTY_PRINT_CELL_SIZE);
    std::cout << "\n";
    logreader.close();
}


// add initial row to weatherdata
void init_logs(){

    if (!std::filesystem::exists(LOGPATH)){
        std::vector<double> weather = generateWeatherData();
        csv::CSVWriter logwriter {LOGPATH};

        if (logwriter.open()){
            logwriter.writeLine(DATA_HEADERS.begin(), DATA_HEADERS.end());
            logwriter.writeLine(weather.begin(), weather.end());
            logwriter.close();
        }
    }
}


// add new row to weatherdata log
void update_log(std::vector<double>& weather){

    csv::CSVWriter logwriter {LOGPATH};

    if (logwriter.open("a")){
        logwriter.writeLine(weather.begin(), weather.end());
        logwriter.close();
    }
}


// randon range gen
double randomBetween(double min, double max){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distr(min, max);
    return distr(generator);
}


// init with random value between 25-75% range
double initSensor(int sensor){
    double minLimit {SENSOR_MIN_MAX[sensor][0]};
    double maxLimit {SENSOR_MIN_MAX[sensor][1]};
    double perc25 {std::abs(minLimit - maxLimit) / 4};
    return randomBetween(minLimit + perc25, maxLimit - perc25);
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
    return reading;
}

void updateReadings(csv::StringRow row){

    std::vector<double> readings = to_double_vector(row);

    for (size_t i = 0; i < DATA_HEADERS.size(); i++){
         // initialize values to default if they fall outside range
        double newValue = generateUpdate(readings[i]);
        if (isValidReading(i, newValue)){
            readings[i] = newValue;
        }
        else{
            readings[i] = initSensor(i);
        }
    }
    
    update_log(readings);
}

