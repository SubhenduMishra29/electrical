#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <string>
#include "voltage.h"
#include "current.h"

/**
 * @class Line
 * @brief Represents a transmission line in a power system.
 * 
 * The Line class models a transmission line with properties such as current, impedance, capacitance, and inductance.
 */
class Line {
private:
    std::string id; ///< Line ID
    Current inCurrent; ///< Incoming current (in Amperes)
    Current outCurrent; ///< Outgoing current (in Amperes)
    Voltage voltage; ///< Voltage drop across the line
    double impedance; ///< Impedance of the line
    double capacitance; ///< Capacitance of the line
    double inductance; ///< Inductance of the line

public:
    /**
     * @brief Default constructor for the Line class.
     * Initializes all properties to default values.
     */
    Line();

    /**
     * @brief Constructs a Line object with only an ID.
     * @param id The line ID.
     */
    explicit Line(const std::string& id);

    /**
     * @brief Constructs a Line object with specified properties.
     * @param id The line ID.
     * @param impedance The line impedance.
     * @param capacitance The line capacitance.
     * @param inductance The line inductance.
     */
    Line(const std::string& id, double impedance, double capacitance, double inductance);

    /**
     * @brief Gets the incoming current of the line.
     * @return The incoming current.
     */
    Current getInCurrent() const;

    /**
     * @brief Sets the incoming current of the line.
     * @param current The incoming current.
     */
    void setInCurrent(const Current& current);

    Voltage calculateVoltageDrop() const;

    /**
     * @brief Gets the outgoing current of the line.
     * @return The outgoing current.
     */
    Current getOutCurrent() const;

    /**
     * @brief Sets the outgoing current of the line.
     * @param current The outgoing current.
     */
    void setOutCurrent(const Current& current);

    /**
     * @brief Gets the voltage drop across the line.
     * @return The voltage drop.
     */
    Voltage getVoltage() const;

    /**
     * @brief Sets the voltage drop across the line.
     * @param v The voltage drop.
     */
    void setVoltage(const Voltage& v);

    /**
     * @brief Gets the impedance of the line.
     * @return The impedance.
     */
    double getImpedance() const;

    /**
     * @brief Gets the capacitance of the line.
     * @return The capacitance.
     */
    double getCapacitance() const;

    /**
     * @brief Gets the inductance of the line.
     * @return The inductance.
     */
    double getInductance() const;

    /**
     * @brief Gets the ID of the line.
     * @return The line ID.
     */
    std::string getId() const;

    /**
     * @brief Updates the line properties based on current state.
     */
    void update();

    /**
     * @brief Displays the line information to the console.
     */
    void displayInfo() const;
};

#endif // LINE_H
