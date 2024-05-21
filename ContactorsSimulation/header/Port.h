/*
 * File: Port.h
 * Author: Subhendu Mishra
 * License: GPL
 * Description: Definition of the Port class, representing ports in a contactor.
 */

#ifndef PORT_H
#define PORT_H

#include <string>

/**
 * @brief Class representing a port with input and output connections.
 */
class Port {
private:
    double inValue; /**< Input value */
    double outValue; /**< Output value */

public:
    /**
     * @brief Constructor for Port.
     */
    Port() : inValue(0.0), outValue(0.0) {}

    /**
     * @brief Set the input value of the port.
     * @param value Input value to set.
     */
    void setInValue(double value) { inValue = value; }

    /**
     * @brief Get the input value of the port.
     * @return Input value of the port.
     */
    double getInValue() const { return inValue; }

    /**
     * @brief Get the output value of the port.
     * @return Output value of the port.
     */
    double getOutValue() const { return outValue; }

    /**
     * @brief Toggle the port state based on the coil state.
     * @param isOn Coil state; if true, set outValue to inValue, else set outValue to 0.
     */
    void togglePort(bool isOn) {
        if (isOn) {
            outValue = inValue;
        } else {
            outValue = 0.0;
        }
    }
};

#endif // PORT_H
