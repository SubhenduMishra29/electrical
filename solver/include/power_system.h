/**
 * @file power_system.h
 * @brief This file contains the PowerSystem class which orchestrates power system simulations.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include <string>
#include <iostream>
#include "sld.h"
#include "powerflow.h" // Include power flow analysis functions
#include "PowerSystemError.h"

class PowerSystem {
private:
    const SLD* sld; // Reference to the SLD object
    PowerFlow powerFlow; // PowerFlow object for analysis

public:
    PowerSystem();
    ~PowerSystem() = default; // No need for custom destructor

    void loadSLD(const SLD& sld);
    void runSimulation();

    std::vector<Bus*> getBuses() const;
    std::vector<Transformer*> getTransformers() const;
    std::vector<Generator*> getGenerators() const;
    std::vector<Load*> getLoads() const;
    std::vector<TransmissionLine*> getTransmissionLines() const;
    std::vector<CircuitBreaker*> getCircuitBreakers() const;
    std::vector<Relay*> getRelays() const;
    std::vector<Capacitor*> getCapacitors() const;
    std::vector<Reactor*> getReactors() const;
    Grid* getGrid() const;
};

#endif // POWER_SYSTEM_H
