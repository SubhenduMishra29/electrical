#include "lib/current.h"

// Constructor
/**
 * @brief Constructs a Current object with specified attributes.
 * @param magnitude The magnitude of the current in amperes.
 * @param phaseAngle The phase angle of the current in degrees.
 * @param frequency The frequency of the current in Hertz.
 * @param waveformType The type of waveform (e.g., sinusoidal, square).
 */
Current::Current(double magnitude, double phaseAngle, double frequency, std::string waveformType)
    : magnitude(magnitude), phaseAngle(phaseAngle), frequency(frequency), waveformType(waveformType) {
    // Initialize all attributes
}

// Getter methods...

// Setters...

/**
 * @brief Simulates the behavior of the current.
 * 
 * This method simulates the current's behavior under specific conditions, such as varying frequency or amplitude.
 */
void Current::simulateBehavior() {
    // Placeholder: Simulate the current behavior
    // Example: Adjust magnitude or phase angle based on conditions
}

/**
 * @brief Calculates the power associated with the current.
 * @param voltage The voltage associated with the current.
 * @return The calculated power in watts.
 */
double Current::calculatePower(const Voltage& voltage) const {
    // Assuming Voltage class has a method getMagnitude() to get voltage magnitude
    double voltageMagnitude = voltage.getMagnitude();
    // Calculate power using the formula: P = V * I * cos(θ)
    // Note: Adjust the formula if phase angle needs to be converted to radians
    return voltageMagnitude * magnitude * cos(phaseAngle * M_PI / 180.0); // Convert angle to radians
}
