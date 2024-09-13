#ifndef BUS_H
#define BUS_H

#include <vector>
#include <string>
#include <unordered_set>
#include "Line.h"

/**
 * @class Bus
 * @brief Represents a bus in a power system.
 * 
 * The Bus class models a bus that can be connected to multiple lines and has a voltage attribute.
 */
class Bus {
private:
    std::string id; ///< Bus ID
    double voltage; ///< Voltage at the bus
    double totalCurrent; ///< Total current flowing through the bus
    std::unordered_set<std::string> lineIds; ///< Set to track line IDs for uniqueness

public:
    /**
     * @brief Default constructor for the Bus class.
     * Initializes the bus with default values.
     */
    Bus();

    /**
     * @brief Constructs a Bus object with specified parameters.
     * @param id The bus ID.
     * @param voltageStr The voltage at the bus in string format.
     */
    Bus(const std::string& id, const std::string& voltageStr);

    /**
     * @brief Adds a line ID to the bus.
     * Checks for duplicate line IDs before adding.
     * @param lineId The ID of the line to add.
     * @return True if the line ID was added successfully, false if the line ID already exists.
     */
    // bool addLineId(const std::string& lineId);

    /**
     * @brief Gets the list of line IDs connected to this bus.
     * @return A vector of line IDs.
     */
    // std::vector<std::string> getLineIds() const;

    /**
     * @brief Updates the bus values based on connected lines.
     */
    void updateBusValues();

    /**
     * @brief Displays the bus information to the console.
     */
    void displayInfo() const;

    std::string getId() const { return id; }
    double getVoltage() const { return voltage; }
};

#endif // BUS_H
