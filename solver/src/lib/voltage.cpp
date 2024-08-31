#include "lib/Voltage.h"
#include <cmath>

/**
 * @file Voltage.cpp
 * @brief Implements the Voltage class representing voltage at a bus in the power system.
 * 
 * This file contains the implementation of the Voltage class methods, including 
 * getters and setters for voltage, active power, reactive power, and power angle, 
 * as well as methods to get the magnitude and angle of the voltage.
 * 
 * @author Subhendu Mishra
 * @date [Date]
 */

/**
 * @brief Constructor for the Voltage class.
 * @param voltage The voltage level as a complex number.
 * @param activePower The active power in MW.
 * @param reactivePower The reactive power in MVAR.
 * @param powerAngle The power angle in degrees.
 */
Voltage::Voltage(std::complex<double> voltage, double activePower, double reactivePower, double powerAngle)
    : voltage(voltage), activePower(activePower), reactivePower(reactivePower), powerAngle(powerAngle) {}

/**
 * @brief Default constructor for the Voltage class.
 */
Voltage::Voltage() : voltage(0.0, 0.0), activePower(0.0), reactivePower(0.0), powerAngle(0.0) {}

/**
 * @brief Gets the voltage level.
 * @return The voltage level as a complex number.
 */
std::complex<double> Voltage::getVoltage() const {
    return voltage;
}

/**
 * @brief Sets the voltage level.
 * @param voltage The voltage level to set as a complex number.
 */
void Voltage::setVoltage(std::complex<double> voltage) {
    this->voltage = voltage;
}

/**
 * @brief Gets the active power.
 * @return The active power in MW.
 */
double Voltage::getActivePower() const {
    return activePower;
}

/**
 * @brief Sets the active power.
 * @param activePower The active power to set in MW.
 */
void Voltage::setActivePower(double activePower) {
    this->activePower = activePower;
}

/**
 * @brief Gets the reactive power.
 * @return The reactive power in MVAR.
 */
double Voltage::getReactivePower() const {
    return reactivePower;
}

/**
 * @brief Sets the reactive power.
 * @param reactivePower The reactive power to set in MVAR.
 */
void Voltage::setReactivePower(double reactivePower) {
    this->reactivePower = reactivePower;
}

/**
 * @brief Gets the power angle.
 * @return The power angle in degrees.
 */
double Voltage::getPowerAngle() const {
    return powerAngle;
}

/**
 * @brief Sets the power angle.
 * @param powerAngle The power angle to set in degrees.
 */
void Voltage::setPowerAngle(double powerAngle) {
    this->powerAngle = powerAngle;
}

/**
 * @brief Gets the magnitude of the voltage.
 * @return The magnitude of the voltage.
 */
double Voltage::getVoltageMagnitude() const {
    return std::abs(voltage);
}

/**
 * @brief Gets the angle of the voltage.
 * @return The angle of the voltage in degrees.
 */
double Voltage::getVoltageAngle() const {
    return std::arg(voltage) * (180.0 / M_PI);  // Convert from radians to degrees
}
