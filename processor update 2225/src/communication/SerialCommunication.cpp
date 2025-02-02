#include "SerialCommunication.h"
#include <iostream>
#include <windows.h>

SerialCommunication::SerialCommunication() {
    // Constructor implementation
}

void SerialCommunication::createVirtualSerialPort(const std::string& portName) {
    std::cout << "Creating virtual serial port: " << portName << std::endl;

    HANDLE hSerial = CreateFile(portName.c_str(),
                                GENERIC_READ | GENERIC_WRITE,
                                0,
                                nullptr,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                nullptr);

    if (hSerial == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();
        std::cerr << "Error opening serial port: " << portName
                  << " (Error Code: " << error << ")" << std::endl;
        return;
    }

    if (!configureSerialPort(hSerial)) {
        CloseHandle(hSerial);
        return;
    }

    std::cout << "Virtual serial port " << portName << " created successfully" << std::endl;

    CloseHandle(hSerial);
}

bool SerialCommunication::configureSerialPort(HANDLE hSerial) {
    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        DWORD error = GetLastError();
        std::cerr << "Error getting serial port state (Error Code: " << error << ")" << std::endl;
        return false;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        DWORD error = GetLastError();
        std::cerr << "Error setting serial port state (Error Code: " << error << ")" << std::endl;
        return false;
    }

    return true;
}
