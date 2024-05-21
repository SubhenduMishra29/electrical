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
#include "State.h" // Include the State class header file

/**
 * @brief Class representing main contacts in a contactor.
 */
class MainContact {
private:
    Port port; /**< Main contact now includes a Port */
    double maxCurrent; /**< Maximum current rating of the main contact */
    double current; /**< Current flowing through the main contact */
    State state; /**< State of the contactor (coil and contacts) */

public:
    /**
     * @brief Constructor with port name, type, maximum current, and initial current.
     * @param portName Name of the port.
     * @param portType Type of the port.
     * @param maxCurr Maximum current rating of the main contact.
     * @param initialCurr Initial current flowing through the main contact (default is 0.0).
     */
    MainContact(const std::string& portName, const std::string& portType, double maxCurr, double initialCurr = 0.0)
        : port(portName, portType), maxCurrent(maxCurr), current(initialCurr) {}

    /**
     * @brief Method to set the current flowing through the main contact.
     * @param curr Current to be set.
     */
    void setCurrent(double curr) {
        if (curr > maxCurrent) {
            throw std::runtime_error("Max Current is above capacity");
        }
        current = curr;
    }

    /**
     * @brief Method to get the current flowing through the main contact.
     * @return Current flowing through the main contact.
     */
    double getCurrent() const { return current; }

    // Other member variables and methods...
};

#endif // MAINCONTACT_H
