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
    Port port; /**< Main contact includes a Port */
    double maxCurrent; /**< Maximum current rating of the main contact */
    double current; /**< Current flowing through the main contact */

public:
    /**
     * @brief Constructor for MainContact.
     * @param portInId ID of the input port.
     * @param portInName Name of the input port.
     * @param portOutId ID of the output port.
     * @param portOutName Name of the output port.
     * @param maxCurr Maximum current rating.
     * @param initialCurr Initial current flowing through the main contact.
     */
    MainContact(int portInId, const std::string& portInName, int portOutId, const std::string& portOutName, double maxCurr, double initialCurr = 0.0)
        : port(portInId, portInName, portOutId, portOutName), maxCurrent(maxCurr), current(initialCurr) {}

    /**
     * @brief Method to set the current flowing through the main contact.
     * @param curr Current to be set.
     */
    void setCurrent(double curr) {
        if (curr > maxCurrent) {
            throw MaxCurrentExceededException("Max Current is above capacity");
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
