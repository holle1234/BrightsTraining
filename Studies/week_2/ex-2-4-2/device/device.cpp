#include "device.h"
#include "../utils/utils.h"
#include "../csv/csv.h"
#include "../logger/logger.h"
#include <string>
#include <algorithm>
#include <fstream>


namespace modbus{    
bool readDeviceData(DeviceVector &dVect){

    bool ignoreHeader{true};
    csv::CSVReader reader{DEVICES_PATH, ignoreHeader};

    if (!reader.open())
    {
        return false;
    }

    // read the data
    std::vector<std::string> row;
    while (reader.readLine(row))
    {
        // lets find this id and add role to corresponding device
        auto loc = std::find_if(dVect.begin(), dVect.end(),
                                [&](const Device &d)
                                { return d.deviceID == row[0]; });

        if (loc != dVect.end())
        {
            (*loc).role = row[1];
        }
    }

    reader.close();
    return true;
}


bool readRegisterData(DeviceVector &dVect)
{

    bool ignoreHeader{true};
    csv::CSVReader reader{REGISTERS_PATH, ignoreHeader};

    if (!reader.open())
    {
        return false;
    }

    // read the data
    std::vector<std::string> row;
    while (reader.readLine(row))
    {

        RegisterRecord newRecord;
        newRecord.first = row[1];
        newRecord.second = row[2];

        // data should be "deviceID", "address", "value"
        // lets find out if we have encountered it yet
        auto loc = getDevice(dVect, row[0]);

        // device not found, create new
        if (loc == dVect.end())
        {
            Device dev{row[0]};
            dev.addToRegister(newRecord);
            dVect.push_back(dev);
        }
        // device found, add register to it
        else
        {
            (*loc).addToRegister(newRecord);
        }
    }

    reader.close();
    return true;
}

DeviceVector::iterator getDevice(DeviceVector& dVect, std::string id){
    auto loc = std::find_if(dVect.begin(), dVect.end(),
                        [&](const Device &d)
                        { return d.deviceID == id;});
    return loc;
}


bool setDevice(DeviceVector& dVect, std::string id,
              std::string registerId, std::string value){

    if (isInteger(value)){
        // ensure int format !(00, 01)
        value = std::to_string(std::stoi(value));
        auto res = getDevice(dVect, id);

        if (res != dVect.end()){
            auto master = getMaster(dVect);

            std::string bVal {res->getRegister(registerId)};
            res->changeRegister(registerId, value);

            logger::LogWriter logWriter {LOG_PATH};
            logWriter.open("a");
            logWriter.writeLine("Master Device " +  master->deviceID + " changed register value of: Device " + id + 
                                " register " + registerId + " from '" + bVal + "' to '" + value + "'");
            logWriter.close();

            return true;
        }
    }
    return false;
}

DeviceVector::iterator getMaster(DeviceVector& dVect){
    auto loc = std::find_if(dVect.begin(), dVect.end(),
                        [&](const Device &d)
                        { return d.role == MASTER;});
    return loc;
    
}

bool changeDeviceRole(DeviceVector& dVect, std::string id, std::string role){

    // non valid role
    if ((role != MASTER) && (role != SLAVE)){
        return false;
    }
    // check if device id is valid
    auto device = getDevice(dVect, id);
    if (device == dVect.end()){
        return false;
    }
    // cant set master to a slave before passing the role
    if ((device->role == MASTER) && (role == SLAVE)){
        return false;
    }
    // change master
    else if ((device->role == SLAVE) && (role == MASTER)){
        auto master = getMaster(dVect);
        master->role = SLAVE;
        device->role = MASTER;

        logger::LogWriter logWriter {LOG_PATH};
        logWriter.open("a");
        logWriter.writeLine("Device " + id + " changed role from 'slave' to 'master'");
        logWriter.writeLine("Device " + master->deviceID + " changed role from 'master' to 'slave'");
        logWriter.close();

        return true;
    }

    // otherwise we are trying to set slave to slave or master to master
    return false;
}

// Read data from csv file
bool readData(DeviceVector &dVect)
{
    bool regStatus = readRegisterData(dVect);
    bool devStatus = readDeviceData(dVect);

    return regStatus && devStatus;
}

// Write data to csv file.
bool writeData(const DeviceVector &devices)
{

    // set streams and open both files
    csv::CSVWriter devWriter {DEVICES_PATH};
    csv::CSVWriter regWriter {REGISTERS_PATH};

    // abort if either cant be opened
    auto isopend = devWriter.open("w");
    auto isopene = regWriter.open("w");

    if (!(isopend && isopene)){
        devWriter.close();
        regWriter.close();
        return false;
    }

    // write device headers
    devWriter.writeLine(DEVICE_HEADERS->begin(),
                        DEVICE_HEADERS->end());
    

    // write register headers
    regWriter.writeLine(REGISTER_HEADERS->begin(),
                        REGISTER_HEADERS->end());
    
    // write device data
    std::vector<std::string> line;
    for (auto &&dev : devices){
        line = {dev.deviceID, dev.role};
        devWriter.writeLine(line.begin(), line.end());

        // write register data
        for (auto &&reg : dev.dataRegister){
            line = {dev.deviceID, reg.first, reg.second};
            regWriter.writeLine(line.begin(), line.end());
        }
    }
    
    devWriter.close();
    regWriter.close();

    return true;
}

Device generateSingleDevice(std::string &s)
{
    std::string newId = generateDeviceID();
    Device device{newId, s};
    return device;
}

void generateDevices(DeviceVector &devVect, int size = 10)
{
    logger::LogWriter logWriter {LOG_PATH};
    logWriter.open("a");
    logWriter.writeLine("Reseting the Devices..");

    std::string role {SLAVE};

    // create slaves
    Device device;
    for (size_t i = 0; i < (size - 1); i++)
    {
        device = generateSingleDevice(role);
        devVect.push_back(device);
        logWriter.writeLine("Device " + device.deviceID + " changed role from '-' to 'slave'");
    }

    // create master last
    role = MASTER;
    device = generateSingleDevice(role);
    devVect.push_back(device);
    logWriter.writeLine("Device " + device.deviceID + " changed role from '-' to 'master'");
    logWriter.writeLine("Reset finished!");
    logWriter.close();
}
}