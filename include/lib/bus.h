#ifndef BUS_H
#define BUS_H

#include <string>
#include <unordered_map>
#include <memory> // For std::shared_ptr
#include "Line.h"
#include "lib/voltage.h"
#include "lib/current.h"
#include "BusType.h"

/**
 * @class Bus
 * @brief Represents a bus in a power system.
 */
class Bus {
private:
    std::string id;                                   ///< Bus ID
    Voltage voltage;                                  ///< Voltage at the bus
    Current totalCurrent;                             ///< Total current at the bus
    BusType type;                                     ///< Bus type (Slack, PV, PQ)

    // Tracks connected lines, classified as incoming and outgoing
    std::unordered_map<std::string, std::shared_ptr<Line>> incomingLines; ///< Incoming lines
    std::unordered_map<std::string, std::shared_ptr<Line>> outgoingLines; ///< Outgoing lines

public:
    Bus();
    Bus(const std::string& id, const std::string& voltageStr);
    Bus(const std::string& id, const std::string& voltageStr, BusType type);

    /**
     * @brief Adds a line to the bus as either incoming or outgoing.
     * @param line The line to connect to the bus.
     * @param isIncoming True if the line is incoming, false if outgoing.
     */
    void addLine(const std::shared_ptr<Line>& line, bool isIncoming);

    /**
     * @brief Updates the total current at the bus based on connected lines.
     */
    void updateBusValues();

    /**
     * @brief Displays the bus information.
     */
    void displayInfo() const;

    // Accessors
    std::string getId() const { return id; }
    Voltage getVoltage() const { return voltage; }
    BusType getType() const { return type; }
};

#endif // BUS_H
