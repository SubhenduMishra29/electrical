#include "lib/voltage.h"
#include <cmath>
#include <stdexcept> // For std::invalid_argument, std::runtime_error

/**
 * @brief Default constructor for the Voltage class.
 */
Voltage::Voltage() : value(0.0, 0.0), frequency(50.0), powerAngle(0.0) {}

/**
 * @brief Constructs a Voltage object with specified real and imaginary parts.
 * @param real The real part of the voltage.
 * @param imaginary The imaginary part of the voltage.
 */
Voltage::Voltage(double real, double imaginary)
    : value(real, imaginary), frequency(50.0), powerAngle(0.0) {
        setReal(real);
        setImaginary(imaginary);
        updateProperties();
}

/**
 * @brief Constructs a Voltage object with a specified value and frequency.
 * @param value The voltage value as a complex number.
 * @param frequency The frequency of the voltage in Hz.
 * @throw std::invalid_argument if the provided value or frequency is invalid.
 */
Voltage::Voltage(const std::complex<double>& value, double frequency)
    : value(value), frequency(frequency), powerAngle(0.0) {
    if (std::abs(value) < 0) {
        throw std::invalid_argument("Voltage value cannot be negative.");
    }
    if (frequency <= 0) {
        throw std::invalid_argument("Frequency must be positive.");
    }
    updateProperties();
}

/**
 * @brief Updates internal properties based on the voltage value.
 * This method recalculates derived values such as magnitude, phase, and power angle.
 */
void Voltage::updateProperties() {
    // Automatically calculate the power angle in degrees when voltage is updated
    powerAngle = getPhase() * 180.0 / M_PI;  // Convert radians to degrees
}

/**
 * @brief Sets the real part of the voltage value and updates properties.
 * @param num The real part to set.
 */
void Voltage::setReal(double num) {
    value = std::complex<double>(num, value.imag());
    updateProperties();
}

/**
 * @brief Sets the imaginary part of the voltage value and updates properties.
 * @param num The imaginary part to set.
 */
void Voltage::setImaginary(double num) {
    value = std::complex<double>(value.real(), num);
    updateProperties();
}

/**
 * @brief Gets the voltage value.
 * @return The voltage value as a complex number.
 */
std::complex<double> Voltage::getValue() const {
    return value;
}

/**
 * @brief Sets the voltage value and updates properties.
 * @param value The voltage value to set as a complex number.
 * @throw std::invalid_argument if the provided value is invalid.
 */
void Voltage::setValue(const std::complex<double>& value) {
    if (std::abs(value) < 0) {
        throw std::invalid_argument("Voltage value cannot be negative.");
    }
    this->value = value;
    updateProperties();
}

/**
 * @brief Gets the frequency of the voltage.
 * @return The frequency in Hz.
 */
double Voltage::getFrequency() const {
    return frequency;
}

/**
 * @brief Sets the frequency of the voltage.
 * @param frequency The frequency to set in Hz.
 */
void Voltage::setFrequency(double frequency) {
    if (frequency <= 0) {
        throw std::invalid_argument("Frequency must be positive.");
    }
    this->frequency = frequency;
    updateProperties();
}

/**
 * @brief Gets the magnitude of the voltage.
 * @return The magnitude of the voltage.
 */
double Voltage::getMagnitude() const {
    return std::abs(value);
}

/**
 * @brief Gets the phase angle of the voltage.
 * @return The phase angle of the voltage in radians.
 */
double Voltage::getPhase() const {
    return std::arg(value);
}

/**
 * @brief Gets the power angle.
 * @return The power angle in degrees.
 */
double Voltage::getPowerAngle() const {
    return powerAngle;
}

/**
 * @brief Prints the voltage details to the console.
 */
void Voltage::printDetails() const {
    std::cout << "----------------Inside Voltage--------------------- " << std::endl;
    std::cout << "Voltage Value: " << value << std::endl;
    std::cout << "Magnitude: " << getMagnitude() << std::endl;
    std::cout << "Phase: " << getPhase() << " radians" << std::endl;
    std::cout << "Power Angle: " << getPowerAngle() << " degrees" << std::endl;
    std::cout << "Frequency: " << frequency << " Hz" << std::endl;
    std::cout << "---------------------------------------------------- " << value << std::endl;
}
