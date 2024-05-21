/*
 * File: AuxiliaryContact.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef AUXILIARYCONTACT_H
#define AUXILIARYCONTACT_H

#include "Port.h" // Include the modified Port class header file
#include "State.h" // Include the State class header file
#include "ErrorHandling.h" // Include the error handling module

/**
 * @brief Enum representing the type of the auxiliary contact.
 */
enum class AuxiliaryContactType {
    NO, /**< Normally Open */
    NC /**< Normally Closed */
};

/**
 * @brief Class representing auxiliary contacts in a contactor.
 */
class AuxiliaryContact {
private:
    Port inPort; /**< In port of the auxiliary contact */
    Port outPort; /**< Out port of the auxiliary contact */
    AuxiliaryContactType type; /**< Type of the auxiliary contact (NO or NC) */
    double maxCurrent; /**< Maximum current rating of the auxiliary contact */
    double current; /**< Current flowing through the auxiliary contact */

public:
    /**
     * @brief Constructor with in port, out port, type, and maximum current.
     * @param inPortName Name of the in port.
     * @param inPortType Type of the in port.
     * @param outPortName Name of the out port.
     * @param outPortType Type of the out port.
     * @param contactType Type of the auxiliary contact (NO or NC).
     * @param maxCurr Maximum current rating of the auxiliary contact.
     */
    AuxiliaryContact(const std::string& inPortName, const std::string& inPortType,
                     const std::string& outPortName, const std::string& outPortType,
                     AuxiliaryContactType contactType, double maxCurr)
        : inPort(inPortName, inPortType), outPort(outPortName, outPortType), type(contactType), maxCurrent(maxCurr), current(0.0) {}

    /**
     * @brief Method to update the out port voltage based on the coil state.
     * If the auxiliary contact is NO type, in port voltage equals out port voltage when coil is on, and vice versa.
     * If the auxiliary contact is NC type, out port voltage is set to 0 when coil is on, and vice versa.
     * @param coilState State of the coil (true if coil is on, false otherwise).
     */
    void updateOutPortVoltage(bool coilState) {
        if (type == AuxiliaryContactType::NO) {
            outPort.setVoltage(coilState ? inPort.getVoltage() : 0.0);
        } else {
            outPort.setVoltage(coilState ? 0.0 : inPort.getVoltage());
        }
    }

    /**
     * @brief Method to set the current flowing through the auxiliary contact.
     * @param curr Current value to be set.
     * @throws MaxCurrentExceededException if the current exceeds the maximum current rating.
     */
    void setCurrent(double curr) {
        if (curr > maxCurrent) {
            throw MaxCurrentExceededException("Current exceeds maximum current for auxiliary contact.");
        }
        current = curr;
    }

    /**
     * @brief Method to get the current flowing through the auxiliary contact.
     * @return Current value.
     */
    double getCurrent() const {
        return current;
    }

    // Other member variables and methods...
};

#endif // AUXILIARYCONTACT_H
