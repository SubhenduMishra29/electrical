#ifndef CURRENT_H
#define CURRENT_H

#include <complex>
#include <iostream>
#include <stdexcept> // For std::invalid_argument

/**
 * @class Current
 * @brief Represents the current in a power system with automatic property updates.
 * 
 * The Current class models electrical current as a complex number, including magnitude,
 * phase, and frequency. It provides methods for manipulating and analyzing the current value.
 */
class Current {
private:
    std::complex<double> value; ///< Current value as a complex number
    double frequency; ///< Frequency of the current in Hz

    /**
     * @brief Updates internal properties based on the current value.
     */
    void updateProperties();

public:
    /**
     * @brief Default constructor for the Current class.
     */
    Current();

    /**
     * @brief Constructs a Current object with a specified value and frequency.
     * @param value The current value as a complex number.
     * @param frequency The frequency of the current in Hz.
     * @throw std::invalid_argument if the provided value is invalid.
     */
    Current(const std::complex<double>& value, double frequency);
    Current(double value);  // New constructor
    /**
     * @brief Gets the current value.
     * @return The current value as a complex number.
     */
    std::complex<double> getValue() const;

    /**
     * @brief Sets the current value and updates properties.
     * @param value The current value to set as a complex number.
     * @throw std::invalid_argument if the provided value is invalid.
     */
    void setValue(const std::complex<double>& value);

    /**
     * @brief Gets the frequency of the current.
     * @return The frequency in Hz.
     */
    double getFrequency() const;

    /**
     * @brief Sets the frequency of the current.
     * @param frequency The frequency to set in Hz.
     */
    void setFrequency(double frequency);

    /**
     * @brief Gets the magnitude of the current.
     * @return The magnitude of the current.
     */
    double getMagnitude() const;

    /**
     * @brief Gets the phase angle of the current.
     * @return The phase angle of the current in radians.
     */
    double getPhase() const;

    /**
     * @brief Adds another current to this current.
     * @param other The Current object to add.
     * @return The resulting Current object after addition.
     */
    Current operator+(const Current& other) const;

    /**
     * @brief Overloads the += operator to add another current to this current.
     * @param other The Current object to add.
     * @return Reference to this Current object.
     */
    Current& operator+=(const Current& other);

    /**
     * @brief Prints the current details to the console.
     */
    void printDetails() const;
};

#endif // CURRENT_H
