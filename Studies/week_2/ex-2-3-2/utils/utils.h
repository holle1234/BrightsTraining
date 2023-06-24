#if !defined(HEADER)
#define HEADER

#include <string>
#include <iterator>
#include <list>
#include <vector>

// constants 
constexpr int ID_LIMIT {20};
constexpr int TIME_LIMIT {1000};
constexpr double MAX_SENSOR_DEV {0.1};


// container for a single reading
struct SensorReading{
    int timestamp;
    std::string ID;
    float value;
};

// define alias for eye pleasure
using SensorData = std::list<SensorReading>;
using TallyPair = std::pair<std::string, int>;
using TallyPairVector = std::vector<TallyPair>;
using ReadingIt = std::list<SensorReading>::iterator;

// functions
int randomBetween(int min, int max);

SensorData sensorReadingsGenerator(int size);

SensorData filterReadingByID(SensorData &inputData, std::string &id);

SensorData filterReadingOutliers(SensorData &inputData);

void sortReadingByTimeStamp(SensorData &inputData);

TallyPairVector tallyReadingById(SensorData &inputData);

TallyPairVector mostCommonSensors(SensorData &data, int nTop);

std::ostream &operator<<(std::ostream &os, SensorReading rd);

std::ostream &operator<<(std::ostream &os, SensorData rdv);

std::ostream &operator<<(std::ostream &os, TallyPair tp);

std::ostream &operator<<(std::ostream &os, TallyPairVector tpv);


#endif // HEADER


