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
    double inValue0;  /**< Input value 0 */
    double outValue0; /**< Output value 0 */
    double inValue1;  /**< Input value 1 */
    double outValue1; /**< Output value 1 */
    bool state;       /**< State of the port */

public:
    /**
     * @brief Constructor for Port.
     * Initializes inValue and state with provided values.
     * @param inVal0 Initial input value 0.
     * @param inVal1 Initial input value 1.
     * @param portState Initial state of the port.
     */
    Port(double inVal0, double inVal1, bool portState) : inValue0(inVal0), inValue1(inVal1), state(portState), outValue0(0.0), outValue1(0.0) {}

    /**
     * @brief Set the input values of the port.
     * @param value0 Input value 0 to set.
     * @param value1 Input value 1 to set.
     */
    void setInValues(double value0, double value1) { inValue0 = value0; inValue1 = value1; }

    /**
     * @brief Get the input value 0 of the port.
     * @return Input value 0 of the port.
     */
    double getInValue0() const { return inValue0; }

    /**
     * @brief Get the input value 1 of the port.
     * @return Input value 1 of the port.
     */
    double getInValue1() const { return inValue1; }

    /**
     * @brief Get the output value 0 of the port.
     * @return Output value 0 of the port.
     */
    double getOutValue0() const { return outValue0; }

    /**
     * @brief Get the output value 1 of the port.
     * @return Output value 1 of the port.
     */
    double getOutValue1() const { return outValue1; }

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
     * @brief Update the output values of the port based on its state.
     */
    void updateOutput() {
        if (state) {
            outValue0 = inValue0;
            outValue1 = inValue1;
        } else {
            outValue0 = 0.0;
            outValue1 = 0.0;
        }
    }
};

#endif // PORT_H
