#include "utils/utils.h"
#include <iostream>



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

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < 10; i++)
    {
        std::cout << randomBetween(i-1, i) << "\n";
    }
    
    return 0;
}



