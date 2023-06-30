#if !defined(UTILS)
#define UTILS

#include "../csv/csv.h"
#include <string>
#include <array>
#include <vector>


const std::array<std::string, 4> DATA_HEADERS {"temp C",
                                               "humidity %",
                                               "windspeed m/s",
                                               "atm"};


const double SENSOR_MIN_MAX[4][2] {{-100, 100},
                                    {0, 100},
                                    {0, 100},
                                    {0.8, 1.1}};


const std::array<std::string, 2> CMD_OPTIONS {"-h", "-r"};
const std::string LOGPATH {"weather.log"};
const int PRETTY_PRINT_CELL_SIZE {15};

// log and other functions

const char **find_option(const char **begin, const char **end, std::string option);

std::vector<double> to_double_vector(csv::StringRow &source);

void print_logs();

void read_log_last_entry();

void init_logs();

void update_log(std::vector<double> &weather);


// weather data functions

double randomBetween(double min, double max);

double initSensor(int sensor);

std::vector<double> generateWeatherData();

bool isValidReading(int sensor, double reading);

double generateUpdate(double reading);

void updateReadings(csv::StringRow);

#endif
// UTILS
