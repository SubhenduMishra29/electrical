#ifndef TRANSMISSION_LINE_H
#define TRANSMISSION_LINE_H

#include <string>
#include "PowerSystemError.h"
#include "Voltage.h"
#include "Bus.h"

/**
 * @class TransmissionLine
 * @brief Represents a transmission line in the power system.
 * 
 * This class encapsulates the properties of a transmission line, including its ID, length, and impedance.
 * It provides methods to get these properties and retrieve the voltage of the buses connected by the line.
 */
class Bus;  // Forward declaration
class TransmissionLine {
private:
    std::string id; ///< Unique identifier for the transmission line
    double length; ///< Length of the transmission line in kilometers
    double impedance; ///< Impedance of the transmission line in ohms
    Bus* bus1; ///< Pointer to the first bus connected by this transmission line
    Bus* bus2; ///< Pointer to the second bus connected by this transmission line

public:
    /**
     * @brief Constructor for the TransmissionLine class.
     * @param id The unique identifier for the transmission line.
     * @param length The length of the transmission line in kilometers.
     * @param impedance The impedance of the transmission line in ohms.
     * @param bus1 Pointer to the first bus connected by the transmission line.
     * @param bus2 Pointer to the second bus connected by the transmission line.
     */
    TransmissionLine(const std::string& id, double length, double impedance, Bus* bus1, Bus* bus2);
    
    /**
     * @brief Destructor for the TransmissionLine class.
     */
    ~TransmissionLine();

    /**
     * @brief Gets the ID of the transmission line.
     * @return The ID of the transmission line.
     */
    std::string getId() const;

    /**
     * @brief Gets the length of the transmission line.
     * @return The length of the transmission line in kilometers.
     */
    double getLength() const;

    /**
     * @brief Gets the impedance of the transmission line.
     * @return The impedance of the transmission line in ohms.
     */
    double getImpedance() const;

    /**
     * @brief Gets the voltage of the bus connected by this transmission line.
     * @param bus Pointer to the bus whose voltage is to be retrieved.
     * @return The voltage of the connected bus.
     */
    Voltage getConnectedBusVoltage(const Bus* bus) const;
};

#endif // TRANSMISSION_LINE_H
