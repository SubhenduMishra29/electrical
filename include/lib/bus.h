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

    // Tracks connected lines
    std::unordered_map<std::string, std::shared_ptr<Line>> lines; ///< Lines connected to this bus

    // New attributes for generator and reference status
    bool hasGenerator;                               ///< Indicates if this bus is connected to a generator
    bool isReferenceBus;                             ///< Indicates if this bus is the reference (slack) bus

    /**
     * @brief Dynamically updates the bus type based on conditions (slack bus, generator).
     */
    void updateBusType();

public:
    Bus();
    Bus(const std::string& id, const std::string& voltageStr);
    Bus(const std::string& id, const std::string& voltageStr, BusType type);

    void addLine(const std::shared_ptr<Line>& line);
    void setVoltage(const Voltage& v);


    void updateBusValues();

    void displayInfo() const;

    // Accessors
    std::string getId() const { return id; }
    Voltage getVoltage() const { return voltage; }
    BusType getType() const { return type; }

    // Methods to set generator and reference status
    void setHasGenerator(bool hasGen) { hasGenerator = hasGen; }
    void setIsReferenceBus(bool isRef) { isReferenceBus = isRef; }
};

#endif // BUS_H
