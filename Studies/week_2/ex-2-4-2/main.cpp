#include "device/device.h"
#include "logger/logger.h"
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <array>


const std::array<std::string, 7> CMD_OPTIONS {"reset",
                                              "set",
                                              "devices",
                                              "read",
                                              "write",
                                              "log",
                                              "help"};

const std::array<std::string, 7> CMD_HELP {"'reset'   --                         reset all records",
                                           "'set'     [master/slave] [deviceID]  set role ",
                                           "'devices' --                         list all data",
                                           "'read'    [deviceId]                 read one device ",
                                           "'write'   [deviceID] [intvalue]      write value to register ",
                                           "'log'     --                         print change log",
                                           "'help'    --                         show this msg"};

/* 

READING DATA IN TO SET UP DEVICES:

challenge:
Files might be huge and the order of records might not match between files.

solution:
Read registers.csv first. Add devices by id if they dont exists yet and then add registers to them.
Find each device from devices.csv and set role to devices added at the previous step.
 

Command line args
modbus reset
modbus set [master/slave] deviceID
modbus devices
modbus read deviceID
modbus write -deviceID [] -value []
modbus log

TODO
- command line tools



*/


std::ostream& operator<<(std::ostream& os, const modbus::Device& dt)
{
    os << "Device " << dt.deviceID << " Role " << dt.role << " Registers "; 
    for (auto &&i : dt.dataRegister){
        os << "[" << i.first << " " << i.second << "] ";
    }
    return os;
}

void printDevices(modbus::DeviceVector& devices){
    for (auto &&i : devices)
    {
        std::cout << i << "\n";
    }
    
}

void findDevice(modbus::DeviceVector& dVect, std::string id){
    auto res = modbus::getDevice(dVect, id);
    if (res != dVect.end()){
        std::cout << *res << "\n";
        return;
    }
    std::cout << "Device with id '" << id << "' not found" << "\n";
}

void updateRegister(modbus::DeviceVector& dVect, std::string id,
              std::string registerId, std::string value){

    if(modbus::setDevice(dVect, id, registerId, value)){
        std::cout << "Device " << id << " value set to '"
                  << std::stoi(value) << "' at address " << registerId << "\n";
    }
    else{
         std::cout << "Could not change device " << id << " properties. " 
                   << "It might not be a slave or you entered invalid arguments.\n";
    }
}

void changeRole(modbus::DeviceVector& dVect, std::string id, std::string role){
    bool status = modbus::changeDeviceRole(dVect, id, role);
    if (status){
        std::cout << "Device " << id << "role changed to " << role << "\n";
    }
    else {
        std::cout << "Device " << id << "role remained the same" << "\n";
    }
}



// Find option location
const char** findOption(const char** begin, const char** end, const std::string& query){
    return std::find(begin, end, query);
}

// handle commands here (eq. check if following args are qualifiers needed)
void handleOptions(const std::string& option, const char** loc, const char** end){
    std::cout << option << "\n";

}



int main(int argc, char const *argv[])
{
    const char** end {(argv + argc)};
    for (auto &&i : CMD_OPTIONS)
    {
        const char** loc = findOption(argv, end, i);
        bool doesExist {loc != end};

        if (doesExist){
            handleOptions(i, loc, end);
        }
    }

/*     std::filesystem::create_directory("resources");
    modbus::DeviceVector devices;
    modbus::generateDevices(devices, 10);
    modbus::writeData(devices);
    modbus::readData(devices);
    printDevices(devices);
    findDevice(devices, "w");
    findDevice(devices, "00000001");
    updateRegister(devices, "00000010", "00000000", "01");
    updateRegister(devices, "00000010", "00000001", "r");
    changeRole(devices, "00000010", "slave");
    changeRole(devices, "00000001", "master");
    modbus::writeData(devices);
    printDevices(devices);
 */
    return 0;

}