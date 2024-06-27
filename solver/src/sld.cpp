#include "SLD.h"

// Constructor
SLD::SLD() {
    // Constructor implementation, if needed
}

// Function to assemble the SLD
void SLD::assemble() {
    // Example: Assemble the SLD with dummy data for demonstration
    // Initialize buses
    buses.push_back(Bus("Bus1"));
    buses.push_back(Bus("Bus2"));

    // Initialize transformers
    transformers.push_back(Transformer("Transformer1"));
    transformers.push_back(Transformer("Transformer2"));

    // Initialize generators
    generators.push_back(Generator("Generator1"));
    generators.push_back(Generator("Generator2"));

    // Initialize loads
    loads.push_back(Load("Load1"));
    loads.push_back(Load("Load2"));

    // Initialize transmission lines
    transmissionLines.push_back(TransmissionLine("Line1", "Bus1", "Bus2"));
    transmissionLines.push_back(TransmissionLine("Line2", "Bus2", "Bus1"));

    // Initialize circuit breakers
    circuitBreakers.push_back(CircuitBreaker("CB1"));
    circuitBreakers.push_back(CircuitBreaker("CB2"));

    // Initialize relays
    relays.push_back(Relay("Relay1"));
    relays.push_back(Relay("Relay2"));

    // Initialize capacitors
    capacitors.push_back(Capacitor("Capacitor1"));
    capacitors.push_back(Capacitor("Capacitor2"));

    // Initialize reactors
    reactors.push_back(Reactor("Reactor1"));
    reactors.push_back(Reactor("Reactor2"));

    // Initialize grids
    grids.push_back(Grid("Grid1"));
    grids.push_back(Grid("Grid2"));

    // Initialize current transformers
    cts.push_back(CT("CT1"));
    cts.push_back(CT("CT2"));

    // Initialize potential transformers
    pts.push_back(PT("PT1"));
    pts.push_back(PT("PT2"));

    // Initialize lines
    lines.push_back(Line("Line1"));
    lines.push_back(Line("Line2"));
}

// Getters for all components

std::vector<Bus>& SLD::getBuses() {
    return buses;
}

const std::vector<Bus>& SLD::getBuses() const {
    return buses;
}

std::vector<Transformer>& SLD::getTransformers() {
    return transformers;
}

const std::vector<Transformer>& SLD::getTransformers() const {
    return transformers;
}

std::vector<Generator>& SLD::getGenerators() {
    return generators;
}

const std::vector<Generator>& SLD::getGenerators() const {
    return generators;
}

std::vector<Load>& SLD::getLoads() {
    return loads;
}

const std::vector<Load>& SLD::getLoads() const {
    return loads;
}

std::vector<TransmissionLine>& SLD::getTransmissionLines() {
    return transmissionLines;
}

const std::vector<TransmissionLine>& SLD::getTransmissionLines() const {
    return transmissionLines;
}

std::vector<CircuitBreaker>& SLD::getCircuitBreakers() {
    return circuitBreakers;
}

const std::vector<CircuitBreaker>& SLD::getCircuitBreakers() const {
    return circuitBreakers;
}

std::vector<Relay>& SLD::getRelays() {
    return relays;
}

const std::vector<Relay>& SLD::getRelays() const {
    return relays;
}

std::vector<Capacitor>& SLD::getCapacitors() {
    return capacitors;
}

const std::vector<Capacitor>& SLD::getCapacitors() const {
    return capacitors;
}

std::vector<Reactor>& SLD::getReactors() {
    return reactors;
}

const std::vector<Reactor>& SLD::getReactors() const {
    return reactors;
}

std::vector<Grid>& SLD::getGrids() {
    return grids;
}

const std::vector<Grid>& SLD::getGrids() const {
    return grids;
}

std::vector<CT>& SLD::getCTs() {
    return cts;
}

const std::vector<CT>& SLD::getCTs() const {
    return cts;
}

std::vector<PT>& SLD::getPTs() {
    return pts;
}

const std::vector<PT>& SLD::getPTs() const {
    return pts;
}

std::vector<Line>& SLD::getLines() {
    return lines;
}

const std::vector<Line>& SLD::getLines() const {
    return lines;
}
