/*
 * File: AuxiliaryContact.h
 * Author: Subhendu Mishra
 * License: GPL
 * Description: Definition of the AuxiliaryContact class for representing an auxiliary contact in a contactor.
 */

#ifndef AUXILIARYCONTACT_H
#define AUXILIARYCONTACT_H

#include "Port.h"
#include <stdexcept> // For std::runtime_error
#include <iostream>  // For input and output operations



enum ContactType {
    NO, /**< Normally Open */
    NC  /**< Normally Closed */
};

class AuxiliaryContact {
private:
    Port port;
    bool state;
    ContactType type;
    double maxCurrent;
    double inputVoltage;

public:
    /*
     * @brief Constructor for AuxiliaryContact.
     * @param initialInValue Initial input value for the port.
     * @param initialState Initial state for the contact.
     * @param contactType Type of the contact (NO or NC).
     */
    AuxiliaryContact(double initialInValue, bool initialState, ContactType contactType) 
        : port(initialInValue, initialState), state(initialState), type(contactType), maxCurrent(0.0), inputVoltage(0.0) {}

    /*
     * @brief Set the input voltage for the auxiliary contact.
     * @param voltage Input voltage to set.
     * @throws std::invalid_argument if the voltage is negative.
     */
    void setInputVoltage(double voltage) {
        if (voltage < 0.0) {
            throw std::invalid_argument("Input voltage cannot be negative.");
        }
        inputVoltage = voltage;
    }

    /*
     * @brief Set the maximum current for the auxiliary contact.
     * @param curr Maximum current to set.
     * @throws std::invalid_argument if the current is negative.
     */
    void setMaxCurrent(double curr) {
        if (curr < 0.0) {
            throw std::invalid_argument("Maximum current cannot be negative.");
        }
        maxCurrent = curr;
    }

    /*
     * @brief Get the input voltage of the auxiliary contact.
     * @return The input voltage.
     */
    double getInputVoltage() const {
        return inputVoltage;
    }

    /*
     * @brief Get the maximum current of the auxiliary contact.
     * @return The maximum current.
     */
    double getMaxCurrent() const {
        return maxCurrent;
    }

    // Other member functions...
};

#endif // AUXILIARYCONTACT_H
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
