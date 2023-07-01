#include "utils/utils.h"
#include <iostream>
#include <string>

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



IMPLEMENTATION:
- updates are -5+5% change from previous readings.
- readings are stored into csv file. 
- readings are stored as a vector double while updating
- readings are converted from double to string while saving or loading
- console options are -h & -r (history, read).
- history is updated only via -r command


SAMPLE PRINT:

juho@myubuntuenv:~/Desktop/BrightsRepo$ ./.build/weather -h
Weather history:

|    temp C     ||  humidity %   || windspeed m/s ||      atm      |
|   -9.04745    ||    73.9873    ||    36.3796    ||   0.966458    |
|   -8.61061    ||    72.7848    ||    34.8984    ||   0.950965    |
|   -8.74772    ||    75.9275    ||    33.6984    ||   0.911876    |


 */




int main(int argc, char const *argv[]){

    // make sure logs exists
    init_logs();

    // print help if no args supplied
    if (argc == 1){
        std::cout << "-h    show history\n-r    show current weather\n";
    }

    // if some args supplied find and process them
    const char** end {argv+argc};
    for (auto &&option : CMD_OPTIONS){
        const char** it = find_option(argv, end, option);
        if (it == end){
            continue;
        }

        // print history
        if (option == CMD_OPTIONS[0]){
            std::cout << "Weather history:\n\n";
            print_logs();
        }

        // show current weather
        if (option == CMD_OPTIONS[1]){
            read_log_last_entry();
        }
        
    }
    
    return 0;
}



