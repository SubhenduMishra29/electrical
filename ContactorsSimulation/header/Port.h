/*
 * File: Port.h
 * Author: Subhendu Mishra
 * License: GPL
 * Description: Definition of the Port class, representing ports in a contactor.
 */

#ifndef PORT_H
#define PORT_H

/**
 * @brief Class representing a port with input and output connections.
 */
class Port {
private:
    double inValue;  /**< Input value */
    double outValue; /**< Output value */
    bool state;      /**< State of the port */

public:
    /**
     * @brief Constructor for Port.
     * Initializes inValue and state with provided values.
     * @param inVal Initial input value.
     * @param portState Initial state of the port.
     */
    Port(double inVal, bool portState) : inValue(inVal), state(portState), outValue(0.0) {}

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
     * @brief Get the state of the port.
     * @return State of the port.
     */
    bool getState() const { return state; }

    /**
     * @brief Set the state of the port.
     * @param newState New state to set.
     */
    void setState(bool newState) { state = newState; }

    /**
     * @brief Update the output value of the port based on its state.
     */
    void updateOutput() {
        if (state) {
            outValue = inValue;
        } else {
            outValue = 0.0;
        }
    }
};

#endif // PORT_H
