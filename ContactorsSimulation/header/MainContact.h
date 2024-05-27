/*
 * File: MainContact.h
 * Author: Subhendu Mishra
 * Description: Definition of the MainContact class representing main contacts in a contactor.
 * License: GPL
 */

#ifndef MAINCONTACT_H
#define MAINCONTACT_H

#include "Port.h" // Include the modified Port class header file
#include "ErrorHandling.h" // Include for error handling
#include <stdexcept> // Include for std::runtime_error

/**
 * @brief Class representing a main contact in a contactor.
 */
class MainContact {
private:
    Port port;
    double maxCurrent;
    double current;

public:
    /**
     * @brief Constructor for MainContact.
     * @param name Name of the contact.
     * @param initialInValue0 Initial input value 0 for the port.
     * @param initialInValue1 Initial input value 1 for the port.
     * @param initialState Initial state for the contact.
     * @param maxCurr Maximum current rating.
     * @param initialCurr Initial current flowing through the main contact.
     */
    MainContact(const std::string& name, double initialInValue0, double initialInValue1, bool initialState, double maxCurr, double initialCurr = 0.0)
        : port(initialInValue0, initialInValue1, initialState), maxCurrent(maxCurr), current(initialCurr) {}

    /**
     * @brief Method to set the current flowing through the main contact.
     * @param curr Current to be set.
     */
    void setCurrent(double curr) {
        if (curr > maxCurrent) {
            throw MaxCurrentExceededException("Current exceeds maximum current for main contact.");
        }
        current = curr;
    }

    /**
     * @brief Method to get the current flowing through the main contact.
     * @return Current flowing through the main contact.
     */
    double getCurrent() const { return current; }

    /**
     * @brief Method to get the input port.
     * @return Input port.
     */
    Connection getInPort() const { return port.getInPort(); }

    /**
     * @brief Method to get the output port.
     * @return Output port.
     */
    Connection getOutPort() const { return port.getOutPort(); }
};

#endif // MAINCONTACT_H
