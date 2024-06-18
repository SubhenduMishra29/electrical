#include "PowerSystem.h"
#include <iostream>
#include <fstream>

// Constructor
PowerSystem::PowerSystem() : grid(nullptr) {}

// Destructor
PowerSystem::~PowerSystem() {
    // Clean up dynamically allocated memory
    for (auto bus : buses) {
        delete bus;
    }
    for (auto transformer : transformers) {
        delete transformer;
    }
    for (auto generator : generators) {
        delete generator;
    }
    for (auto load : loads) {
        delete load;
    }
    for (auto transmissionLine : transmissionLines) {
        delete transmissionLine;
    }
    for (auto circuitBreaker : circuitBreakers) {
        delete circuitBreaker;
    }
    for (auto relay : relays) {
        delete relay;
    }
    for (auto capacitor : capacitors) {
        delete capacitor;
    }
    for (auto reactor : reactors) {
        delete reactor;
    }
    delete grid;
}

// Load SLD from file
void PowerSystem::loadSLD(const std::string& filename) {
    // Logic to read SLD from file and populate buses, transformers, and other components
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    // Example logic to read the file (details depend on the file format)
    std::string componentType;
    while (file >> componentType) {
        if (componentType == "BUS") {
            std::string id;
            file >> id;
            buses.push_back(new Bus(id));
        } else if (componentType == "TRANSFORMER") {
            std::string id;
            file >> id;
            transformers.push_back(new Transformer(id));
        } else if (componentType == "GENERATOR") {
            std::string id;
            double powerOutput;
            file >> id >> powerOutput;
            generators.push_back(new Generator(id, powerOutput));
        } else if (componentType == "LOAD") {
            std::string id;
            double powerDemand;
            file >> id >> powerDemand;
            loads.push_back(new Load(id, powerDemand));
        } else if (componentType == "TRANSMISSION_LINE") {
            std::string id;
            double length, impedance;
            file >> id >> length >> impedance;
            transmissionLines.push_back(new TransmissionLine(id, length, impedance));
        } else if (componentType == "CIRCUIT_BREAKER") {
            std::string id;
            bool isClosed;
            file >> id >> isClosed;
            circuitBreakers.push_back(new CircuitBreaker(id, isClosed));
        } else if (componentType == "RELAY") {
            std::string id;
            double setting;
            file >> id >> setting;
            relays.push_back(new Relay(id, setting));
        } else if (componentType == "CAPACITOR") {
            std::string id;
            double capacitance;
            file >> id >> capacitance;
            capacitors.push_back(new Capacitor(id, capacitance));
        } else if (componentType == "REACTOR") {
            std::string id;
            double inductance;
            file >> id >> inductance;
            reactors.push_back(new Reactor(id, inductance));
        }
    }

    file.close();
}

// Run simulation
void PowerSystem::runSimulation() {
    // Logic to run a general simulation
}

// Perform Load Flow analysis
void PowerSystem::performLoadFlow() {
    // Logic to perform load flow analysis
}

// Calculate Voltage Drop
void PowerSystem::calculateVoltageDrop() {
    // Logic to calculate voltage drop
}

// Perform Short Circuit analysis
void PowerSystem::performShortCircuitAnalysis() {
    // Logic to perform short circuit analysis
}

// Perform DC Short Circuit analysis
void PowerSystem::performDCShortCircuitAnalysis() {
    // Logic to perform DC short circuit analysis
}

// Perform DC Load Flow analysis
void PowerSystem::performDCLoadFlow() {
    // Logic to perform DC load flow analysis
}

// Get the list of buses
std::vector<Bus*> PowerSystem::getBuses() const {
    return buses;
}

// Get the list of transformers
std::vector<Transformer*> PowerSystem::getTransformers() const {
    return transformers;
}

// Get the list of generators
std::vector<Generator*> PowerSystem::getGenerators() const {
    return generators;
}

// Get the list of loads
std::vector<Load*> PowerSystem::getLoads() const {
    return loads;
}

// Get the list of transmission lines
std::vector<TransmissionLine*> PowerSystem::getTransmissionLines() const {
    return transmissionLines;
}

// Get the list of circuit breakers
std::vector<CircuitBreaker*> PowerSystem::getCircuitBreakers() const {
    return circuitBreakers;
}

// Get the list of relays
std::vector<Relay*> PowerSystem::getRelays() const {
    return relays;
}

// Get the list of capacitors
std::vector<Capacitor*> PowerSystem::getCapacitors() const {
    return capacitors;
}

// Get the list of reactors
std::vector<Reactor*> PowerSystem::getReactors() const {
    return reactors;
}

// Get the grid information
Grid* PowerSystem::getGrid() const {
    return grid;
}
