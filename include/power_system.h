/**
 * @file powersystem.h
 * @brief This file contains the PowerSystem class which orchestrates power system simulations.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include <string>
#include "lib/bus.h"
#include "lib/line.h"
#include "lib/sld.h"
#include "lib/powerflow.h"
#include "lib/PowerSystemError.h"

class PowerSystem {
public:
    PowerSystem();

    /**
     * @brief Load the Single Line Diagram (SLD) from a file.
     * @param filename The name of the file containing the SLD data.
     */
    void loadSLDFromFile(const std::string& filename);

    /**
     * @brief Load the Single Line Diagram (SLD) from command-line input.
     * @param cliInput The command-line input string containing the SLD data.
     */
    void loadSLDFromCLI(const std::string& cliInput);

    /**
     * @brief Run the simulation for the power system.
     */
    void runSimulation();

    /**
     * @brief Check if the simulation has converged.
     * @return True if the simulation has converged, otherwise false.
     */
    bool isConverged() const;

    /**
     * @brief Get the list of buses in the power system.
     * @return A reference to the vector of Bus pointers.
     */
    std::vector<Bus*>& getBuses(); // Return reference to vector of Bus pointers

    /**
     * @brief Get the list of buses in the power system.
     * @return A const reference to the vector of Bus pointers.
     */
    const std::vector<Bus*>& getBuses() const; // Const version

    /**
     * @brief Get the list of lines in the power system.
     * @return A reference to the vector of Line pointers.
     */
    std::vector<Line*>& getLines(); // Return reference to vector of Line pointers

    /**
     * @brief Get the list of lines in the power system.
     * @return A const reference to the vector of Line pointers.
     */
    const std::vector<Line*>& getLines() const; // Const version

    /**
     * @brief Get the list of transformers in the power system.
     * @return A vector of pointers to Transformer objects.
     */
    std::vector<Transformer*> getTransformers() const;

    /**
     * @brief Get the list of generators in the power system.
     * @return A vector of pointers to Generator objects.
     */
    std::vector<Generator*> getGenerators() const;

    /**
     * @brief Get the list of loads in the power system.
     * @return A vector of pointers to Load objects.
     */
    std::vector<Load*> getLoads() const;

    /**
     * @brief Get the list of transmission lines in the power system.
     * @return A vector of pointers to TransmissionLine objects.
     */
    std::vector<TransmissionLine*> getTransmissionLines() const;

    /**
     * @brief Get the list of circuit breakers in the power system.
     * @return A vector of pointers to CircuitBreaker objects.
     */
    std::vector<CircuitBreaker*> getCircuitBreakers() const;

    /**
     * @brief Get the list of relays in the power system.
     * @return A vector of pointers to Relay objects.
     */
    std::vector<Relay*> getRelays() const;

    /**
     * @brief Get the list of capacitors in the power system.
     * @return A vector of pointers to Capacitor objects.
     */
    std::vector<Capacitor*> getCapacitors() const;

    /**
     * @brief Get the list of reactors in the power system.
     * @return A vector of pointers to Reactor objects.
     */
    std::vector<Reactor*> getReactors() const;

    /**
     * @brief Get the grid of the power system.
     * @return A pointer to the Grid object.
     */
    Grid* getGrid() const;

private:
    std::vector<Bus*> buses; ///< List of buses in the power system
    std::vector<Line*> lines; ///< List of lines in the power system

    const SLD* sld; ///< Pointer to the Single Line Diagram (SLD)
    bool converged; ///< Flag indicating whether the simulation has converged
    PowerFlow powerFlow; ///< Instance of PowerFlow class for running simulations

    /**
     * @brief Set buses and lines based on the provided SLD.
     * @param sld The Single Line Diagram used to configure the power system.
     */
    void setBusesAndLines(const SLD& sld);
};

#endif // POWER_SYSTEM_H
