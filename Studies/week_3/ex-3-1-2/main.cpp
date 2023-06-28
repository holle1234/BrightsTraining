#include "utils/utils.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include "csv/csv.h"
#include "utils/utils.h"


/* 
Virtual Weather Station

The program should handle any exceptions that may occur during runtime. 
Handle temperature, humidity, wind speed and atmospheric pressure.

Generate weather data via a function simulating changes in weather over time. 
Make sure the data changes in a way that's somewhat realistic. So the temperature should not jump from +20C to -20C
Implement exception handling to the case when data generated is out of logical range. 
(For example the temperature is less than -273.15C or humidity is over 100%.)

Log data in files. Handle any file-related exceptions like not being able to open the file. 
The console applications should be able to show logs and current weather.
For testing purposes you can add a function that allows you to manually add weather readings.

 */


const std::array<std::string, 2> CMD_OPTIONS {"-h", "-r"};
const std::string logpath {"weather.log"};


// find option from terminal prompt
const char** find_option(const char** begin, const char** end, std::string option){
    return std::find(begin, end, option);
}


StringRow read_logs(bool printall=false){
    csv::CSVReader logreader {logpath};
    logreader.open();

    StringRow row;
    std::cout << "Weather history:\n\n";
    while (logreader.readLine(row)){
        std::cout << row << "\n";
    }

    // last row is the previous weather
    logreader.close();
    return row;
}

void convert_log_to_doubles(StringRow& source, std::vector<double>& dest){
    for (size_t i = 0; i < source.size(); i++){
        double value {std::stod(source[i])};
        dest.push_back(value);
    }
}




int main(int argc, char const *argv[])
{
    const char** end {argv+argc};

    // init weatherdata logs
    if (!std::filesystem::exists(logpath)){
        std::vector<double> weather = generateWeatherData();
        csv::CSVWriter logwriter {logpath};
        logwriter.writeLine(weather.begin(), weather.end());
    }

    // process arguments
    if (argc > 1){

        // if some args supplied find and process them
        for (auto &&option : CMD_OPTIONS){
            const char** it = find_option(argv, end, option);

            if (it != end){

                // print history
                if (option == CMD_OPTIONS[0]){
                    read_logs(true);
                }

                // show current weather
                else if(option == CMD_OPTIONS[1]){
                    std::vector<double> reading_dest;
                    StringRow row = read_logs(false);
                    convert_log_to_doubles(row, reading_dest);
                    updateReadings(reading_dest);
                    std::cout << "Current Weather:\n" << row;
                    
                }
            }
        }
        
    }
    
    return 0;
}



