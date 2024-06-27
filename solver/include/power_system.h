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

    void loadSLD(const SLD& sld); // Method to load from SLD object
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
