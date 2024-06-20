#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include <string>
#include <iostream>
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

// Implementation of methods with error handling

PowerSystem::PowerSystem() {
    // Constructor implementation
}

PowerSystem::~PowerSystem() {
    // Destructor implementation
}

void PowerSystem::loadSLD(const std::string& filename) {
    try {
        // Code to load SLD from file
        if (/* file not found */) {
            throw FileNotFoundError(filename);
        }

        // Rest of the code
    } catch (const std::exception& e) {
        throw;
    }
}

void PowerSystem::runSimulation() {
    try {
        performLoadFlow();
        calculateVoltageDrop();
        performShortCircuitAnalysis();
        // ...

    } catch (const PowerSystemError& e) {
        std::cerr << "Power System Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
}

void PowerSystem::performLoadFlow() {
    try {
        // Perform Load Flow analysis
        if (/* some error condition */) {
            throw LoadFlowError("Specific error details");
        }

    } catch (const std::exception& e) {
        throw;
    }
}

// Implement other methods similarly with error handling
// ...

#endif // POWER_SYSTEM_H
