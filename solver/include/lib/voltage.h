#ifndef VOLTAGE_H
#define VOLTAGE_H

#include <complex>
#include <iostream>
#include <stdexcept> // For std::invalid_argument

/**
 * @class Voltage
 * @brief Represents the voltage in a power system with automatic property updates.
 * 
 * The Voltage class models electrical voltage as a complex number, including magnitude,
 * phase, frequency, and provides methods for manipulating and analyzing the voltage value.
 */
class Voltage {
private:
    std::complex<double> value; ///< Voltage value as a complex number
    double frequency; ///< Frequency of the voltage in Hz

    /**
     * @brief Updates internal properties based on the voltage value.
     * This method recalculates the magnitude and phase angle of the voltage.
     */
    void updateProperties();

public:
    /**
     * @brief Default constructor for the Voltage class.
     */
    Voltage();

    /**
     * @brief Constructs a Voltage object with specified real and imaginary parts.
     * @param real The real part of the voltage.
     * @param imaginary The imaginary part of the voltage.
     */
    Voltage(double real, double imaginary);

    /**
     * @brief Constructs a Voltage object with a specified value and frequency.
     * @param value The voltage value as a complex number.
     * @param frequency The frequency of the voltage in Hz.
     * @throw std::invalid_argument if the provided value or frequency is invalid.
     */
    Voltage(const std::complex<double>& value, double frequency);

    /**
     * @brief Sets the real part of the voltage value and updates properties.
     * @param num The real part to set.
     */
    void setReal(double num);

    /**
     * @brief Sets the imaginary part of the voltage value and updates properties.
     * @param num The imaginary part to set.
     */
    void setImaginary(double num);

    /**
     * @brief Gets the voltage value.
     * @return The voltage value as a complex number.
     */
    std::complex<double> getValue() const;

    /**
     * @brief Sets the voltage value and updates properties.
     * @param value The voltage value to set as a complex number.
     * @throw std::invalid_argument if the provided value is invalid.
     */
    void setValue(const std::complex<double>& value);

    /**
     * @brief Gets the frequency of the voltage.
     * @return The frequency in Hz.
     */
    double getFrequency() const;

    /**
     * @brief Sets the frequency of the voltage.
     * @param frequency The frequency to set in Hz.
     */
    void setFrequency(double frequency);

    /**
     * @brief Gets the magnitude of the voltage.
     * @return The magnitude of the voltage.
     */
    double getMagnitude() const;

    /**
     * @brief Gets the phase angle of the voltage.
     * @return The phase angle of the voltage in radians.
     */
    double getPhase() const;

    /**
     * @brief Calculates the voltage difference between this voltage and another voltage.
     * @param other The other Voltage object to compare with.
     * @return The voltage difference as a complex number.
     */
    std::complex<double> calculateDifference(const Voltage& other) const;

    /**
     * @brief Gets the power angle.
     * @return The power angle in degrees.
     */
    double getPowerAngle() const;

    /**
     * @brief Prints the voltage details to the console.
     */
    void printDetails() const;
};

#endif // VOLTAGE_H
