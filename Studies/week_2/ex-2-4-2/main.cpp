#include "device/device.h"
#include "logger/logger.h"
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <array>
#include <iterator>
#include <algorithm>


const std::array<std::string, 8> CMD_OPTIONS {"reset",
                                              "set",
                                              "devices",
                                              "read",
                                              "write",
                                              "log",
                                              "help",
                                              "master"};

const std::array<std::string, 8> CMD_HELP {"'reset'   --                        reset devices",
                                           "'set'     [device][master/slave]    set role ",
                                           "'devices' --                        list all data",
                                           "'read'    [device]                  read one device ",
                                           "'write'   [device][register][value] write value to register ",
                                           "'log'     --                        print change log",
                                           "'help'    --                        show this msg",
                                           "'master'  --                        print master device"};

/* 

READING DATA IN TO SET UP DEVICES:

challenge:
Files might be huge and the order of records might not match between files.

solution:
Read registers.csv first. Add devices by id if they dont exists yet and then add registers to them.
Find each device from devices.csv and set role to devices added at the previous step.
 
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
        modbus::writeData(dVect);
    }
    else{
         std::cout << "Could not change device " << id << " properties. " 
                   << "It might not be a slave or you entered invalid arguments.\n";
    }
}

void changeRole(modbus::DeviceVector& dVect, std::string id, std::string role){
    bool status = modbus::changeDeviceRole(dVect, id, role);
    if (status){
        std::cout << "Device " << id << " role changed to " << role << "\n";
        modbus::writeData(dVect);
    }
    else {
        std::cout << "Device " << id << " role remained the same" << "\n";
    }
}

// reset all devices and records (.log not included)
void resetDevices(modbus::DeviceVector& devices){
    devices.clear();
    modbus::generateDevices(devices, modbus::DEVICE_COUNT);
    modbus::writeData(devices);
}

void printLog(){

    // open log reader
    logger::LogReader reader {modbus::LOG_PATH};
    reader.open();

    // print every log entry
    std::string temp;
    while (reader.readLine(temp)){
        std::cout << temp << "\n";
    }
    reader.close();
}

// Find option location
const std::string* findOption(const std::string* begin, const std::string* end, const std::string& query){
    return std::find(begin, end, query);
}

// handle commands here (eq. check if following args are qualifiers needed)
bool handleOptions(modbus::DeviceVector dVect, const char** begin, const char** end, const std::string& option){

    bool doesExist {begin != end};
    int dist = std::distance(begin, end) - 1;
    
    // reset
    if (option == CMD_OPTIONS[0]){
        resetDevices(dVect);
    }
    // set role
    else if (option == CMD_OPTIONS[1]){
        // check if there are two options to follow
        if (dist >= 2){
            changeRole(dVect, *(begin + 1), *(begin + 2));
        }
    }
    // print devices
    else if (option == CMD_OPTIONS[2]){
        printDevices(dVect);
    }

    // read device
    else if (option == CMD_OPTIONS[3]){
        // check if ther are 1 argument to follow
        if (dist >= 1){
            findDevice(dVect,  *(begin + 1));
        }
    }
    // write register
    else if (option == CMD_OPTIONS[4]){
        // check if there are 3 arguments to follow
        if (dist >= 3){
            updateRegister(dVect, *(begin + 1), *(begin + 2), *(begin + 3));
        }
    }
    // log
    else if (option == CMD_OPTIONS[5]){
        printLog();
    }
    // help
    else if ((option == CMD_OPTIONS[6]) || !doesExist){
        std::copy(CMD_HELP.begin(), CMD_HELP.end(),
                  std::ostream_iterator<std::string>(std::cout, "\n"));
    }
    // master
    else if (option == CMD_OPTIONS[7]){
        auto it = modbus::getMaster(dVect);
        if (it != dVect.end()){
            std::cout << *it << "\n";
        }
    }
    return  true;
}



int main(int argc, char const *argv[]){

    // prepare devices
    modbus::DeviceVector devices;

    // arg list end
    const char** end {(argv + argc)};
    
    if (argc > 1){

        modbus::readData(devices);

        // create data paths
        if (!std::filesystem::exists(modbus::LOG_PATH)){
            std::filesystem::create_directory("resources");
            resetDevices(devices);
        }

        // find matching loc (location of argument end() if not found)
        const std::string* loc = findOption(CMD_OPTIONS.begin(), CMD_OPTIONS.end(), *(argv + 1));
        handleOptions(devices, argv + 1, end, *loc);
    }

    // print help if no arguments supplied
    handleOptions(devices, argv + 1, end, "");

    return 0;

}