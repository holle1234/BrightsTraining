#include "utils.h"
#include <string>
#include <list>
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <iterator>


// overload cout for one reading
std::ostream&operator<<(std::ostream& os, SensorReading rd){
    return os << rd.timestamp << " Sensor " << rd.ID << " reading " << rd.value;
}

// overload cout for vector of reading
std::ostream&operator<<(std::ostream& os, SensorData rdv){
    for (auto &&rd : rdv){
        os << rd << "\n";
    }
    return os;
}

// overload cout for Tallypair
std::ostream&operator<<(std::ostream& os, TallyPair tp){
    return os << "Tallypair " << tp.first << " " << tp.second;
}


// overload cout for vector of Tallypair
std::ostream&operator<<(std::ostream& os, TallyPairVector tpv){
    for (auto &&tp : tpv){
        os << tp << "\n";
    }
    return os;
}



// randon range gen
int randomBetween(int min, int max){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(min, max);
    return distr(generator);
}


// generate random readings for a single ID
SensorData sensorReadingsGenerator(int size){

    SensorData data {};
    for (size_t i = 0; i < size; i++){
        // limit value to range 0-1
        float value {float(randomBetween(0, 100)) / 100.0f};
        // limit timestamp to range 0-TIME_LIMIT
        int tStamp {randomBetween(0, TIME_LIMIT)};
        // limit ID to range 0-ID_LIMIT
        int iID {randomBetween(0, ID_LIMIT)};

        // zero fill id
        std::ostringstream sID;
        sID << std::setw(4) << std::setfill('0') << iID;

        SensorReading reading {tStamp, sID.str(), value};
        data.push_back(reading);
    }

    return data;
}

SensorData filterReadingByID(SensorData& inputData, std::string& id){
    // define comparison for filtering
    auto lambda = [&id](const SensorReading& a){return a.ID != id;};

    // output copy
    SensorData out {inputData};

    // erase remove pattern
    out.erase(std::remove_if(begin(out),
                             end(out),
                             lambda), end(out));
    return out;
}

// sorts readings by ascending order
void sortReadingByTimeStamp(SensorData& inputData){
    // define comparison for filtering
    auto lambda = [](const auto& a, const auto& b)
                  {return a.timestamp < b.timestamp;};

    // use list's sort not std::sort..
    inputData.sort(lambda);
}


/* 
Tallies reading by ID occurance from a list of sensor readings.
First it reorders the list to ascending order by ID.
Then in a loop, it count how many objects has same ID in a row.
This count is added to the output list.
 */
TallyPairVector tallyReadingById(SensorData& inputData){

    // unique requires a sorted list
    inputData.sort([](const auto& a, const auto& b){return a.ID < b.ID;});

    // filter to unique copy
    SensorData unique;
    auto it = std::unique_copy(inputData.begin(), inputData.end(),
                               std::back_insert_iterator(unique),
                               [](const auto& a, const auto& b){return a.ID == b.ID;});

    // count occurances
    TallyPairVector pairVec;
    ReadingIt ptr {inputData.begin()};

    int count {0};
    for (auto &&uRead : unique){
        // advance by a previous count
        std::advance(ptr, count);
        // find first not matching spot
        auto uEnd = std::find_if_not(ptr, inputData.end(),
                    [&uRead](const SensorReading& s){return s.ID == uRead.ID;});
        // calculate distance from current it value to non matching spot (=count)
        count = std::distance(ptr, uEnd);
        pairVec.push_back({uRead.ID, count});
    }

    return pairVec;
}


/* 
Gets n most common sensors from a list of readings.
First it calls tallyReadingsById() to get a tally of sensors.
Then it sorts them partially in descending order.
Finally all the non sorted (outside n) are removed.

 */
TallyPairVector mostCommonSensors(SensorData& data, int nTop){
    TallyPairVector tally {tallyReadingById(data)};
    // sort to get top most
    std::partial_sort(tally.rbegin(), tally.rbegin() + nTop, tally.rend(),
              [](const TallyPair& a, const TallyPair& b)
              {return a.second > b.second;});

    tally.erase(tally.begin(), tally.end() - nTop);
    return tally;

}
/* 
Filters readings from set of data by deviation from the mean.

 */
SensorData filterReadingOutliers(SensorData& inputData){
    // calculate avg using lambda
    size_t size {inputData.size()};
    float avg {std::accumulate(inputData.begin(), inputData.end(),0.0f,
                            [&](float sum, const auto& a){return sum + (a.value / size);})};

    // filter anything smaller than MAX_SENSOR_DEV with absdiff
    auto lambda = [&avg](const SensorReading& a)
                  {return std::abs(a.value - avg) < MAX_SENSOR_DEV;};

    // return copy of the filtered data
    SensorData out {inputData};
    out.erase(std::remove_if(begin(out),
                             end(out),
                             lambda), end(out));
    return out;
}

