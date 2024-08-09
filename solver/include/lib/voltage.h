#ifndef VOLTAGE_H
#define VOLTAGE_H

#include <complex> // For std::complex

/**
 * @class Voltage
 * @brief Represents the voltage at a bus in the power system, including magnitude, angle, and associated power.
 */
class Voltage {
private:
    std::complex<double> voltage; ///< Voltage level as a complex number (magnitude and angle)
    double activePower; ///< Active power in MW
    double reactivePower; ///< Reactive power in MVAR

public:
    /**
     * @brief Constructor for the Voltage class.
     * @param voltage The voltage level as a complex number.
     * @param activePower The active power in MW.
     * @param reactivePower The reactive power in MVAR.
     */
    Voltage(std::complex<double> voltage, double activePower, double reactivePower);

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
};

#endif // VOLTAGE_H
