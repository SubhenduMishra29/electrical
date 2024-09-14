#ifndef BUS_H
#define BUS_H

#include <string>
#include <unordered_map>
#include "Line.h"
#include "lib/voltage.h"
#include "lib/current.h"
#include "BusType.h"

/**
 * @class Bus
 * @brief Represents a bus in a power system.
 * 
 * A bus in a power system connects multiple lines and components (such as generators, loads, etc.)
 * and can have different types (Slack, PV, PQ). It tracks voltage, current, and incoming/outgoing lines.
 */
class Bus {
private:
    std::string id;                                    ///< Bus ID
    Voltage voltage;                                   ///< Voltage at the bus
    Current totalCurrent;                              ///< Total current at the bus
    BusType type;                                      ///< Bus type (Slack, PV, PQ)
    
    // Tracks connected lines, classified as incoming and outgoing
    std::unordered_map<std::string, Line*> incomingLines; ///< Lines injecting current into the bus
    std::unordered_map<std::string, Line*> outgoingLines; ///< Lines drawing current from the bus

public:
    /**
     * @brief Default constructor for the Bus class.
     */
    Bus();

    /**
     * @brief Constructs a Bus object with specified parameters.
     * @param id The bus ID.
     * @param voltageStr The voltage at the bus in string format.
     */
    Bus(const std::string& id, const std::string& voltageStr);

    /**
     * @brief Constructs a Bus object with specified parameters including bus type.
     * @param id The bus ID.
     * @param voltageStr The voltage at the bus in string format.
     * @param type The type of bus (Slack, PV, PQ).
     */
    Bus(const std::string& id, const std::string& voltageStr, BusType type);

    /**
     * @brief Adds a line to the bus as either incoming or outgoing.
     * @param line The line to connect to the bus.
     * @param isIncoming True if the line is incoming, false if outgoing.
     */
    void addLine(Line* line, bool isIncoming);

    /**
     * @brief Updates the total current at the bus based on connected lines.
     * The total current is the sum of currents from incoming and outgoing lines.
     */
    void updateBusValues();

    /**
     * @brief Displays the bus information (ID, voltage, current, type) to the console.
     */
    void displayInfo() const;

    // Accessors
    std::string getId() const { return id; }
    Voltage getVoltage() const { return voltage; }
    BusType getType() const { return type; }
};

#endif // BUS_H
