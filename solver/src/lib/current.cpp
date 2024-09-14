#include "lib/current.h"
#include <cmath>
#include <stdexcept> // For std::invalid_argument

/**
 * @brief Default constructor for the Current class.
 */
Current::Current() : value(0.0, 0.0), frequency(50.0) {}

/**
 * @brief Constructs a Current object with a specified value and frequency.
 * @param value The current value as a complex number.
 * @param frequency The frequency of the current in Hz.
 * @throw std::invalid_argument if the provided value or frequency is invalid.
 */
Current::Current(const std::complex<double>& value, double frequency)
    : value(value), frequency(frequency) {
    if (std::abs(value) < 0) {
        throw std::invalid_argument("Current value cannot be negative.");
    }
    if (frequency <= 0) {
        throw std::invalid_argument("Frequency must be positive.");
    }
    updateProperties();
}

/**
 * @brief Constructs a Current object with a double value (real part, imaginary is 0, default frequency).
 * @param value The current value as a real number.
 */
Current::Current(double value) : value(value, 0.0), frequency(50.0) {
    updateProperties();
}

/**
 * @brief Constructs a Current object with specified real and imaginary parts.
 * @param real The real part of the current.
 * @param imag The imaginary part of the current.
 */
Current::Current(double real, double imag) : value(real, imag), frequency(50.0) {
    updateProperties();
}

/**
 * @brief Updates internal properties based on the current value.
 */
void Current::updateProperties() {
    // Implement any property updates needed when the value changes
    // Example: Update derived values or check constraints
}

/**
 * @brief Gets the current value.
 * @return The current value as a complex number.
 */
std::complex<double> Current::getValue() const {
    return value;
}

/**
 * @brief Sets the current value and updates properties.
 * @param value The current value to set as a complex number.
 * @throw std::invalid_argument if the provided value is invalid.
 */
void Current::setValue(const std::complex<double>& value) {
    if (std::abs(value) < 0) {
        throw std::invalid_argument("Current value cannot be negative.");
    }
    this->value = value;
    updateProperties();
}

/**
 * @brief Gets the frequency of the current.
 * @return The frequency in Hz.
 */
double Current::getFrequency() const {
    return frequency;
}

/**
 * @brief Sets the frequency of the current.
 * @param frequency The frequency to set in Hz.
 * @throw std::invalid_argument if the provided frequency is invalid.
 */
void Current::setFrequency(double frequency) {
    if (frequency <= 0) {
        throw std::invalid_argument("Frequency must be positive.");
    }
    this->frequency = frequency;
    updateProperties();
}

/**
 * @brief Gets the magnitude of the current.
 * @return The magnitude of the current.
 */
double Current::getMagnitude() const {
    return std::abs(value);
}

/**
 * @brief Gets the phase angle of the current.
 * @return The phase angle of the current in radians.
 */
double Current::getPhase() const {
    return std::arg(value);
}

/**
 * @brief Adds another current to this current.
 * @param other The Current object to add.
 * @return The resulting Current object after addition.
 */
Current Current::operator+(const Current& other) const {
    return Current(value + other.value, frequency);
}

/**
 * @brief Overloads the += operator to add another current to this current.
 * @param other The Current object to add.
 * @return Reference to this Current object.
 */
Current& Current::operator+=(const Current& other) {
    value += other.value;
    updateProperties();
    return *this;
}

/**
 * @brief Adds a complex number to this current.
 * @param other The complex number to add.
 * @return The resulting Current object after addition.
 */
Current Current::operator+(const std::complex<double>& other) const {
    return Current(value + other, frequency);
}

/**
 * @brief Subtracts another current from this current.
 * @param other The Current object to subtract.
 * @return The resulting Current object after subtraction.
 */
Current Current::operator-(const Current& other) const {
    return Current(value - other.value, frequency);
}

/**
 * @brief Prints the current details to the console.
 */
void Current::printDetails() const {
    std::cout << "---------------- Inside Current ------------------" << std::endl;
    std::cout << "Current Value: " << value << std::endl;
    std::cout << "Magnitude: " << getMagnitude() << std::endl;
    std::cout << "Phase Angle: " << getPhase() << " radians" << std::endl;
    std::cout << "Frequency: " << frequency << " Hz" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}
