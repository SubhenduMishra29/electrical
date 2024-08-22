#ifndef VOLTAGE_H
#define VOLTAGE_H

#include <iostream>  // For std::cout, std::endl
#include <complex>   // For std::complex

/**
 * @file Voltage.h
 * @brief Defines the Voltage class representing voltage at a bus in the power system.
 * 
 * This file contains the declaration of the Voltage class, which encapsulates the voltage 
 * level (as a complex number), active power, reactive power, and power angle associated 
 * with a bus in the power system. The class provides methods to get and set these values.
 * 
 * @author Subhendu Mishra
 * @date [Date]
 */

/**
 * @class Voltage
 * @brief Represents the voltage at a bus in the power system, including magnitude, angle, and associated power.
 * 
 * The Voltage class stores the voltage as a complex number, along with active and reactive 
 * power values. It also includes the power angle in degrees. The class provides methods 
 * to access and modify these values.
 */
class Voltage {
private:
    std::complex<double> voltage; ///< Voltage level as a complex number (magnitude and angle)
    double activePower; ///< Active power in MW
    double reactivePower; ///< Reactive power in MVAR
    double powerAngle; ///< Power angle in degrees

public:
    /**
     * @brief Constructor for the Voltage class.
     * @param voltage The voltage level as a complex number.
     * @param activePower The active power in MW.
     * @param reactivePower The reactive power in MVAR.
     * @param powerAngle The power angle in degrees.
     */
    Voltage(std::complex<double> voltage, double activePower, double reactivePower, double powerAngle);
    Voltage();  // Default constructor

    /**
     * @brief Gets the voltage level.
     * @return The voltage level as a complex number.
     */
    std::complex<double> getVoltage() const;

    /**
     * @brief Sets the voltage level.
     * @param voltage The voltage level to set as a complex number.
     */
    void setVoltage(std::complex<double> voltage);

    /**
     * @brief Gets the active power.
     * @return The active power in MW.
     */
    double getActivePower() const;

    /**
     * @brief Sets the active power.
     * @param activePower The active power to set in MW.
     */
    void setActivePower(double activePower);

    /**
     * @brief Gets the reactive power.
     * @return The reactive power in MVAR.
     */
    double getReactivePower() const;

    /**
     * @brief Sets the reactive power.
     * @param reactivePower The reactive power to set in MVAR.
     */
    void setReactivePower(double reactivePower);

    /**
     * @brief Gets the power angle.
     * @return The power angle in degrees.
     */
    double getPowerAngle() const;

    /**
     * @brief Sets the power angle.
     * @param powerAngle The power angle to set in degrees.
     */
    void setPowerAngle(double powerAngle);

    /**
     * @brief Gets the magnitude of the voltage.
     * @return The magnitude of the voltage.
     */
    double getVoltageMagnitude() const;

    /**
     * @brief Gets the angle of the voltage.
     * @return The angle of the voltage in degrees.
     */
    double getVoltageAngle() const;
};

#endif // VOLTAGE_H
