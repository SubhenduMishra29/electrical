/*
 * File: AuxiliaryContact.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef AUXILIARYCONTACT_H
#define AUXILIARYCONTACT_H

#include "Port.h" // Include the modified Port class header file
#include "State.h" // Include the State class header file

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
    State state; /**< State of the contactor (coil and contacts) */

public:
    /**
     * @brief Constructor with in port, out port, type, and state.
     * @param inPortName Name of the in port.
     * @param inPortType Type of the in port.
     * @param outPortName Name of the out port.
     * @param outPortType Type of the out port.
     * @param contactType Type of the auxiliary contact (NO or NC).
     */
    AuxiliaryContact(const std::string& inPortName, const std::string& inPortType,
                     const std::string& outPortName, const std::string& outPortType,
                     AuxiliaryContactType contactType)
        : inPort(inPortName, inPortType), outPort(outPortName, outPortType), type(contactType) {}

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

    // Other member variables and methods...
};

#endif // AUXILIARYCONTACT_H
