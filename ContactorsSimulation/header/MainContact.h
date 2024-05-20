/*
 * File: MainContact.h
 * Author: Subhendu Mishra
 * Description: Definition of the MainContact class representing main contacts in a contactor.
 * License: GPL
 */
#ifndef MAINCONTACT_H
#define MAINCONTACT_H

#include "Port.h" // Include the modified Port class header file
#include <stdexcept> // Include for std::runtime_error

class MainContact {
private:
    Port port; // Main contact now includes a Port
    double maxCurrent; // Maximum current rating of the main contact
    double current; // Current flowing through the main contact

public:
    // Constructor with port name, type, maximum current, and initial current
    MainContact(const std::string& portName, const std::string& portType, double maxCurr, double initialCurr = 0.0)
        : port(portName, portType), maxCurrent(maxCurr), current(initialCurr) {}

    // Method to set the current flowing through the main contact
    void setCurrent(double curr) {
        if (curr > maxCurrent) {
            throw std::runtime_error("Max Current is above capacity");
        }
        current = curr;
    }

    // Method to get the current flowing through the main contact
    double getCurrent() const { return current; }

    // Other member variables and methods...
};

#endif // MAINCONTACT_H
