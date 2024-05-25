/*
 * File: AuxiliaryContact.h
 * Author: Subhendu Mishra
 * License: GPL
 * Description: Definition of the AuxiliaryContact class for representing an auxiliary contact in a contactor.
 */

#ifndef AUXILIARYCONTACT_H
#define AUXILIARYCONTACT_H

#include "Port.h"
#include <stdexcept> // For std::invalid_argument
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
    /**
     * @brief Constructor for AuxiliaryContact.
     * @param initialInValue0 Initial input value 0 for the port.
     * @param initialInValue1 Initial input value 1 for the port.
     * @param initialState Initial state for the contact.
     * @param contactType Type of the contact (NO or NC).
     */
    AuxiliaryContact(double initialInValue0, double initialInValue1, bool initialState, ContactType contactType)
        : port(initialInValue0, initialInValue1, initialState), state(initialState), type(contactType), maxCurrent(0.0), inputVoltage(0.0) {}

    /**
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

    /**
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

    /**
     * @brief Get the input voltage of the auxiliary contact.
     * @return The input voltage.
     */
    double getInputVoltage() const {
        return inputVoltage;
    }

    /**
     * @brief Get the maximum current of the auxiliary contact.
     * @return The maximum current.
     */
    double getMaxCurrent() const {
        return maxCurrent;
    }

    // Other member functions...
};

#endif // AUXILIARYCONTACT_H
