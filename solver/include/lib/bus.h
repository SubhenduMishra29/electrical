#ifndef BUS_H
#define BUS_H

/**
 * @file Bus.h
 * @brief Header file for the Bus class, representing a bus in the power system.
 * 
 * This file declares the Bus class, which contains generators, loads, transmission lines, and transformers.
 * It includes methods for managing these components, setting and getting voltage, and calculating power flow.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */
#include <vector>
#include <string>
#include <complex>
#include <algorithm> // Include this at the top of your file
#include "lib/load.h"
#include "lib/powersystemerror.h"
#include "lib/transmission_line.h"
#include "lib/line.h"
#include "voltage.h"
#include "current.h"
#include "BusType.h"

class TransmissionLine; // Forward declaration
/**
 * @class Bus
 * @brief Represents a bus in the power system, containing voltage, current, and methods to calculate power flow.
 */
class Bus {
private:
    std::vector<TransmissionLine*> transmissionLines; ///< List of transmission lines connected to the bus
    Voltage busVoltage; ///< Voltage at the bus (complex value with magnitude and angle)
    double current; ///< Current at the bus in amperes
    double inflowPower; ///< Total inflow power in MW
    double outflowPower; ///< Total outflow power in MW
    BusType type; ///< Type of the bus (SLACK, PV, PQ)
    std::string id;
    /**
     * @brief Recalculates the bus voltage and current based on connected transmission lines.
     */
    void recalculateBusState();

    /**
     * @brief Calculates the inflow and outflow power based on connected transmission lines.
     */
    void calculatePowerFlow();

public:
    /**
     * @brief Constructor for the Bus class.
     * @param name The name of the bus.
     * @param busVoltage The initial voltage at the bus.
     * @param type The type of the bus (SLACK, PV, PQ).
     */
    Bus(const std::string& name, const Voltage& busVoltage, BusType type);

    /**
     * @brief Destructor for the Bus class.
     */
    ~Bus() = default;

    /**
     * @brief Adds a transmission line to the bus and recalculates the bus state.
     * @param line Pointer to the transmission line to be added.
     */
    void addTransmissionLine(TransmissionLine* line);

    /**
     * @brief Removes a transmission line from the bus and recalculates the bus state.
     * @param line Pointer to the transmission line to be removed.
     */
    void removeTransmissionLine(TransmissionLine* line);

    /**
     * @brief Gets the voltage at the bus.
     * @return The voltage at the bus as a complex number.
     */
    Voltage getVoltage() const;

    /**
     * @brief Sets the voltage at the bus and recalculates the bus state.
     * @param voltage The voltage to set as a complex number.
     */
    void setVoltage(const Voltage& voltage);

    /**
     * @brief Gets the current at the bus.
     * @return The current at the bus in amperes.
     */
    double getCurrent() const;

    /**
     * @brief Sets the current at the bus and recalculates the bus state.
     * @param current The current to set in amperes.
     */
    void setCurrent(double current);

    /**
     * @brief Gets the inflow power at the bus.
     * @return The inflow power in MW.
     */
    double getInflowPower() const;

    /**
     * @brief Gets the outflow power at the bus.
     * @return The outflow power in MW.
     */
    double getOutflowPower() const;

    /**
     * @brief Gets the type of the bus.
     * @return The type of the bus (SLACK, PV, PQ).
     */
    BusType getType() const;

    /**
     * @brief Sets the type of the bus.
     * @param type The type of the bus (SLACK, PV, PQ).
     */
    void setType(BusType type);
};

#endif // BUS_H

