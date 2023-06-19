#if !defined(DEVICE)
#define DEVICE

#include "../utils/utils.h"
#include "../csv/csv.h"
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>


namespace modbus{

// constants
constexpr int                       REGISTER_SIZE           {5};
constexpr int                       REGISTER_DEFAULT_VAL    {0};
const std::array<std::string, 2>    DEVICE_ROLES[2]         {"master", "slave"};
const std::array<std::string, 2>    DEVICE_HEADERS[2]       {"deviceID", "role"};
const std::array<std::string, 3>    REGISTER_HEADERS[3]     {"deviceID", "address", "value"};
const std::string                   DEVICES_PATH            {"resources/devices.csv"};
const std::string                   REGISTERS_PATH          {"resources/registers.csv"};
const std::string                   LOG_PATH                {"resources/modbus.log"};


// constant roles
 const std::string                  MASTER                  {(*DEVICE_ROLES)[0]};
 const std::string                  SLAVE                   {(*DEVICE_ROLES)[1]};


// for eye cancy
using RegisterRecord = std::pair<std::string, std::string>;
using DataRegister = std::array<RegisterRecord, REGISTER_SIZE>;

// Struct to hold the device and register data.
// Simulates a real world device.
struct Device{
    
    DataRegister dataRegister;
    std::string deviceID;
    std::string role{"slave"};
    int registerSize{0};

    private:
        // fills whole register with specific value
        void fillRegister(int initValue = REGISTER_DEFAULT_VAL)
        {
            for (size_t i = 0; i < REGISTER_SIZE; i++)
            {
                this->dataRegister[i] = {toSerial(i), std::to_string(initValue)};
            }
        }

    public:
        // default constructor
        Device() { fillRegister(); }

        // string constructor id & role
        Device(std::string ID, std::string role = "")
        {
            this->deviceID = ID;
            this->role = role;
            fillRegister();
        }

        // Change the register value at 'key' with 'value'
        bool changeRegister(std::string key, std::string value)
        {
            // find a matching register
            auto it = std::find_if(dataRegister.begin(),
                                dataRegister.end(),
                                [&](const RegisterRecord &r)
                                { return r.first == key; });

            // update value via pointer
            if (it != dataRegister.end())
            {
                (*it).second = value;
                return true;
            }

            return false;
        }

        // Return the register value at 'key' with 'value'
        const std::string& getRegister(std::string key)
        {
            // find a matching register
            auto it = std::find_if(dataRegister.begin(),
                                dataRegister.end(),
                                [&](const RegisterRecord &r)
                                { return r.first == key; });
            return (*it).second;
        }

        // Add a new record to register
        bool addToRegister(RegisterRecord r)
        {
            int curIndex = this->registerSize;
            if (curIndex < REGISTER_SIZE)
            {
                this->dataRegister[curIndex] = r;
                this->registerSize += 1;
                return true;
            }
            return false;
        }
};

// for eye cancy
using DeviceVector = std::vector<Device>;


// read/write functions
bool writeData(const DeviceVector&);
bool readData(DeviceVector &dVect);
void generateDevices(DeviceVector&, int);

bool readDeviceData(DeviceVector&);
bool readRegisterData(DeviceVector&);
DeviceVector::iterator getDevice(DeviceVector &dVect, std::string id);
bool setDevice(DeviceVector &dVect, std::string id, std::string registerId, std::string value);
DeviceVector::iterator getMaster(modbus::DeviceVector &dVect);
bool changeDeviceRole(DeviceVector &dVect, std::string id, std::string role);
Device generateSingleDevice(std::string &);
}

#endif // DEVICE