#ifndef BUS_H
#define BUS_H

#include <vector>
#include <string>  // Ensure the string type is recognized
#include "lib/generator.h"
#include "lib/load.h"
#include "lib/transformer.h" // Include transformer header
#include "lib/PowerSystemError.h"
#include "lib/transmission_line.h"
#include "lib/circuit_breaker.h"
#include "lib/Relay.h"
#include "lib/Capacitor.h"
#include "lib/Reactor.h"
#include "lib/Grid.h"
#include "lib/Line.h"

class Transformer;

/**
 * @class Bus
 * @brief Represents a bus in the power system, containing generators, loads, and transmission lines.
 */
class Bus {
private:
    std::vector<Generator*> generators;
    std::vector<Load*> loads;
    std::vector<TransmissionLine*> transmissionLines;
    std::vector<Transformer*> transformers; ///< Vector to hold transformers
    double voltage;  ///< in kV

public:
    /**
     * @brief Constructor for the Bus class.
     * @param name The name of the bus.
     * @param voltage The voltage level of the bus in kV.
     */
    Bus(const std::string& name, double voltage);

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
     * @brief Calculates the power flow for the bus.
     */
    void calculatePowerFlow();
};

#endif // BUS_H
