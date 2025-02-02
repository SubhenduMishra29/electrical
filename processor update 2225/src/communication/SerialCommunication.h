#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

#include <string>
#include <windows.h>

class SerialCommunication {
public:
    // Constructor
    SerialCommunication();

    // Method to create a virtual serial port
    void createVirtualSerialPort(const std::string& portName);

private:
    // Helper method to configure the serial port
    bool configureSerialPort(HANDLE hSerial);
};

#endif // SERIAL_COMMUNICATION_H
