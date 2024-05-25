/*
 * File: State.h
 * Author: Subhendu Mishra
 * License: GPL
 * Description: Definition of the State class representing the state of a contactor.
 */

#ifndef STATE_H
#define STATE_H

#include <stdexcept>

/**
 * @brief Class representing the state of a contactor.
 */
class State {
private:
    bool coilState; /**< State of the coil */
    bool mainContactState; /**< State of the main contacts */
    bool auxiliaryContactState; /**< State of the auxiliary contacts */

public:
    /**
     * @brief Constructor for State.
     * @param coil State of the coil.
     * @param main State of the main contacts.
     * @param auxiliary State of the auxiliary contacts.
     */
    State(bool coil = false, bool main = false, bool auxiliary = false)
        : coilState(coil), mainContactState(main), auxiliaryContactState(auxiliary) {}

    /**
     * @brief Get the state of the coil.
     * @return State of the coil.
     */
    bool getCoilState() const { return coilState; }

    /**
     * @brief Set the state of the coil.
     * @param state New state of the coil.
     */
    void setCoilState(bool state) { coilState = state; }

    /**
     * @brief Get the state of the main contacts.
     * @return State of the main contacts.
     */
    bool getMainContactState() const { return mainContactState; }

    /**
     * @brief Set the state of the main contacts.
     * @param state New state of the main contacts.
     */
    void setMainContactState(bool state) { mainContactState = state; }

    /**
     * @brief Get the state of the auxiliary contacts.
     * @return State of the auxiliary contacts.
     */
    bool getAuxiliaryContactState() const { return auxiliaryContactState; }

    /**
     * @brief Set the state of the auxiliary contacts.
     * @param state New state of the auxiliary contacts.
     */
    void setAuxiliaryContactState(bool state) { auxiliaryContactState = state; }
};

#endif // STATE_H
