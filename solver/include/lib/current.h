/**
 * @file current.h
 * @brief Header file for the Current class.
 * 
 * This file contains the definition of the Current class, which represents electrical current with various attributes and methods related to current characteristics and simulations.
 * 
 * @author [Your Name]
 * @date [Date]
 * @license [License Type] - [License URL]
 */

#ifndef CURRENT_H
#define CURRENT_H

#include "voltage.h"  ///< Include the header for Voltage class

/**
 * @class Current
 * @brief Represents electrical current with various attributes.
 * 
 * The Current class models electrical current, including its magnitude, phase angle, and other characteristics. It also provides methods for simulating current behavior and handling related calculations.
 * 
 * @author [Your Name]
 * @date [Date]
 */
class Current {
public:
    /**
     * @brief Constructs a Current object with specified attributes.
     * @param magnitude The magnitude of the current in amperes.
     * @param phaseAngle The phase angle of the current in degrees.
     * @param frequency The frequency of the current in Hertz.
     * @param waveformType The type of waveform (e.g., sinusoidal, square).
     */
    Current(double magnitude, double phaseAngle, double frequency, std::string waveformType);
    
    // Getter and setter methods...

    /**
     * @brief Simulates the behavior of the current.
     * 
     * This method simulates the current's behavior under specific conditions, such as varying frequency or amplitude.
     */
    void simulateBehavior();

    /**
     * @brief Calculates the power associated with the current.
     * @param voltage The voltage associated with the current.
     * @return The calculated power in watts.
     */
    double calculatePower(const Voltage& voltage) const;

private:
    double magnitude;       ///< Magnitude of the current in amperes
    double phaseAngle;      ///< Phase angle of the current in degrees
    double frequency;       ///< Frequency of the current in Hertz
    std::string waveformType; ///< Type of waveform (e.g., sinusoidal, square)

    // Additional attributes for advanced calculations...
};

#endif // CURRENT_H
