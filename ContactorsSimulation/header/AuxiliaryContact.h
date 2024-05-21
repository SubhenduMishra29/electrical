/*
 * File: AuxiliaryContact.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef AUXILIARYCONTACT_H
#define AUXILIARYCONTACT_H

#include "Port.h" // Include the modified Port class header file
#include "ErrorHandling.h"
#include <string>

/**
 * @brief Class representing an auxiliary contact in a contactor.
 */
class AuxiliaryContact {
private:
    Port port; /**< Auxiliary contact includes a Port */
    std::string type; /**< Type of the auxiliary contact (NO or NC) */
    double maxCurrent; /**< Maximum current rating of the auxiliary contact */
    double current; /**< Current flowing through the auxiliary contact */

public:
    /**
     * @brief Constructor for AuxiliaryContact.
     * @param portInId ID of the input port.
     * @param portInName Name of the input port.
     * @param portOutId ID of the output port.
     * @param portOutName Name of the output port.
     * @param contactType Type of the contact (NO or NC).
     * @param maxCurr Maximum current rating.
     */
    AuxiliaryContact(int portInId, const std::string& portInName, int portOutId, const std::string& portOutName, const std::string& contactType, double maxCurr) 
        : port(portInId, portInName, portOutId, portOutName), type(contactType), maxCurrent(maxCurr), current(0.0) {}

    /**
     * @brief Method to set the current flowing through the auxiliary contact.
     * @param curr Current to be set.
     */
    void setCurrent(double curr) {
        if (curr > maxCurrent) {
            throw MaxCurrentExceededException("Current exceeds maximum current for auxiliary contact.");
        }
        current = curr;
    }

    /**
     * @brief Method to get the current flowing through the auxiliary contact.
     * @return Current flowing through the auxiliary contact.
     */
    double getCurrent() const { return current; }

    /**
     * @brief Method to toggle the voltage based on coil state.
     * @param coilState State of the coil (true if coil is on, false otherwise).
     */
    void toggleVoltage(bool coilState) {
        if (type == "NO") {
            port.setVoltage(coilState ? port.getInPort().getId() : 0.0);
        } else if (type == "NC") {
            port.setVoltage(coilState ? 0.0 : port.getInPort().getId());
        }
    }
};

#endif // AUXILIARYCONTACT_H
