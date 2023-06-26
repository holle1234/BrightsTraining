#if !defined(UTILS)
#define UTILS

#include <string>
#include <array>


const std::array<std::string, 4> DATA_HEADERS {"temperature",
                                                "humidity",
                                                "windspeed",
                                                "atm"};


const double SENSOR_MIN_MAX[4][2] {{-100, 100},
                                    {0, 100},
                                    {0, 100},
                                    {0.8, 1.1}};




double randomBetween(double min, double max);

double initSensor(int sensor);

std::vector<double> generateWeatherData();

bool isValidReading(int sensor, double reading);

double generateUpdate(double reading);

void updateReading(std::vector<double> &readings);

#endif
// UTILS
