/*
 * File: AuxiliaryContact.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef AUXILIARYCONTACT_H
#define AUXILIARYCONTACT_H

#include "Port.h" // Include the modified Port class header file

class AuxiliaryContact {
private:
    Port port; // Auxiliary contact now includes a Port

public:
    // Constructor with port name and type
    AuxiliaryContact(const std::string& portName, const std::string& portType) : port(portName, portType) {}

    // Other member variables and methods...
};

#endif // AUXILIARYCONTACT_H
