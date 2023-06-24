#include "utils/utils.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>



int main(int argc, char const *argv[])
{

    // Generate random readings
    SensorData data {sensorReadingsGenerator(100)};
    std::cout << "Raw generated data\n" << data;

    // Tally most common reading
    TallyPairVector top1 = mostCommonSensors(data, 1);
    std::cout << "\nMost common sensor: " << top1;

    // Filter by the most common sensor
    std::string queryID {top1[0].first};
    data = filterReadingByID(data, queryID);
    std::cout << "\nData filtered by ID\n" << data;

    // Get the outlier readings
    data = filterReadingOutliers(data);
    std::cout << "\nOutliers\n" << data;

    return 0;
}
