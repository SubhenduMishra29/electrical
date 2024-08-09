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
#include "lib/generator.h"
#include "lib/load.h"
#include "lib/transformer.h"
#include "lib/powersystemerror.h"
#include "lib/transmission_line.h"
#include "lib/circuit_breaker.h"
#include "lib/relay.h"
#include "lib/capacitor.h"
#include "lib/reactor.h"
#include "lib/grid.h"
#include "lib/line.h"
#include "voltage.h"
#include "BusType.h" // Include BusType enum

class Transformer;

/**
 * @class Bus
 * @brief Represents a bus in the power system, containing generators, loads, and transmission lines.
 * 
 * The Bus class manages a list of components connected to the bus, including generators, loads,
 * transmission lines, and transformers. It also maintains the voltage level of the bus.
 */
class Bus {
private:
    std::vector<Generator*> generators; ///< List of generators connected to the bus
    std::vector<Load*> loads; ///< List of loads connected to the bus
    std::vector<TransmissionLine*> transmissionLines; ///< List of transmission lines connected to the bus
    std::vector<Transformer*> transformers; ///< List of transformers connected to the bus
    double voltage; ///< Voltage level of the bus in kV
    BusType type; ///< Type of the bus (SLACK, PV, PQ)

public:
    /**
     * @brief Constructor for the Bus class.
     * @param name The name of the bus.
     * @param voltage The voltage level of the bus in kV.
     * @param type The type of the bus (SLACK, PV, PQ).
     */
    Bus(const std::string& name, double voltage, BusType type);

    /**
     * @brief Destructor for the Bus class.
     */
    ~Bus() = default;

    /**
     * @brief Adds a generator to the bus.
     * @param generator Pointer to the generator to be added.
     */
    void addGenerator(Generator* generator);

    /**
     * @brief Adds a load to the bus.
     * @param load Pointer to the load to be added.
     */
    void addLoad(Load* load);

    /**
     * @brief Adds a transmission line to the bus.
     * @param line Pointer to the transmission line to be added.
     */
    void addTransmissionLine(TransmissionLine* line);

    /**
     * @brief Adds a transformer to the bus.
     * @param transformer Pointer to the transformer to be added.
     */
    void addTransformer(Transformer* transformer);

    /**
     * @brief Gets the voltage of the bus.
     * @return The voltage of the bus in kV.
     */
    double getVoltage() const;

    /**
     * @brief Sets the voltage of the bus.
     * @param voltage The voltage level to set in kV.
     */
    void setVoltage(double voltage);

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

    /**
     * @brief Calculates the power flow for the bus.
     */
    void calculatePowerFlow();
};

#endif // BUS_H
