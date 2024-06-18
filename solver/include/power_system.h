#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

/**
 * @file PowerSystem.h
 * @brief Definition of the PowerSystem class for power system analysis.
 * 
 * This file defines the PowerSystem class which includes methods for
 * Load Flow & Voltage Drop, Short Circuit, DC Short Circuit, and DC Load Flow analysis.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <vector>
#include <string>
#include "bus.h"
#include "transformer.h"
#include "generator.h"
#include "load.h"
#include "transmission_line.h"
#include "circuit_breaker.h"
#include "relay.h"
#include "capacitor.h"
#include "reactor.h"
#include "grid.h"

class PowerSystem {
private:
    std::vector<Bus*> buses;
    std::vector<Transformer*> transformers;
    std::vector<Generator*> generators;
    std::vector<Load*> loads;
    std::vector<TransmissionLine*> transmissionLines;
    std::vector<CircuitBreaker*> circuitBreakers;
    std::vector<Relay*> relays;
    std::vector<Capacitor*> capacitors;
    std::vector<Reactor*> reactors;
    Grid* grid;

public:
    PowerSystem();
    ~PowerSystem(); // Destructor for cleanup
    void loadSLD(const std::string& filename); // Method to load SLD from file
    void runSimulation();

    // New methods for power system analysis
    void performLoadFlow(); // Method to perform Load Flow analysis
    void calculateVoltageDrop(); // Method to calculate Voltage Drop
    void performShortCircuitAnalysis(); // Method to perform Short Circuit analysis
    void performDCShortCircuitAnalysis(); // Method to perform DC Short Circuit analysis
    void performDCLoadFlow(); // Method to perform DC Load Flow analysis

    // Methods to list power system components
    std::vector<Bus*> getBuses() const; // Method to get the list of buses
    std::vector<Transformer*> getTransformers() const; // Method to get the list of transformers
    std::vector<Generator*> getGenerators() const; // Method to get the list of generators
    std::vector<Load*> getLoads() const; // Method to get the list of loads
    std::vector<TransmissionLine*> getTransmissionLines() const; // Method to get the list of transmission lines
    std::vector<CircuitBreaker*> getCircuitBreakers() const; // Method to get the list of circuit breakers
    std::vector<Relay*> getRelays() const; // Method to get the list of relays
    std::vector<Capacitor*> getCapacitors() const; // Method to get the list of capacitors
    std::vector<Reactor*> getReactors() const; // Method to get the list of reactors
    Grid* getGrid() const; // Method to get the grid information
};

#endif // POWER_SYSTEM_H
