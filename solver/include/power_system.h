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

    void loadSLDFromFile(const std::string& filename);
    void loadSLDFromCLI(const std::string& cliInput);

    void runSimulation();

    bool isConverged() const;

    std::vector<Bus*>& getBuses(); // Return reference to vector of Bus pointers
    const std::vector<Bus*>& getBuses() const; // Const version

    std::vector<Line*>& getLines(); // Return reference to vector of Line pointers
    const std::vector<Line*>& getLines() const; // Const version

    std::vector<Transformer*> getTransformers() const;
    std::vector<Generator*> getGenerators() const;
    std::vector<Load*> getLoads() const;
    std::vector<TransmissionLine*> getTransmissionLines() const;
    std::vector<CircuitBreaker*> getCircuitBreakers() const;
    std::vector<Relay*> getRelays() const;
    std::vector<Capacitor*> getCapacitors() const;
    std::vector<Reactor*> getReactors() const;
    Grid* getGrid() const;

private:
    std::vector<Bus*> buses;
    std::vector<Line*> lines;

    const SLD* sld;
    bool converged;
    /// @brief 
   PowerFlow powerFlow; 

    void setBusesAndLines(const SLD& sld);
};

#endif // POWER_SYSTEM_H
