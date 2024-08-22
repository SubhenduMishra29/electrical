#include "lib/sld.h"
#include "lib/input_parser.h"
#include <sstream>
#include <iostream>
#include <fstream>

// Constructor
SLD::SLD() {
    // Constructor implementation
}

// Destructor
SLD::~SLD() {
    // Destructor implementation
}

// Static method to load SLD from a file
SLD* SLD::loadFromFile(const std::string& filename) {
    SLD* sld = new SLD(); // Create a new SLD object
    sld->assemble(filename); // Initialize SLD from the file
    return sld;
}

// Method to assemble the SLD from a file
void SLD::assemble(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return; // Return early if file cannot be opened
    }

    InputParser parser(filename);
    parser.parseFile();

    buses = parser.getBuses();
    transformers = parser.getTransformers();
    generators = parser.getGenerators();
    loads = parser.getLoads();
    transmissionLines = parser.getTransmissionLines();
    circuitBreakers = parser.getCircuitBreakers();
    relays = parser.getRelays();
    capacitors = parser.getCapacitors();
    reactors = parser.getReactors();
    grids = parser.getGrids();
    lines = parser.getLines();
}

// Static method to create SLD from CLI input
std::unique_ptr<SLD> SLD::createFromCLI(const std::string& cliInput) {
    auto instance = std::make_unique<SLD>();  // Create a unique pointer to a new SLD instance
    instance->assembleFromCLI(cliInput); // Assemble the SLD from CLI input
    return instance;
}

// Method to assemble the SLD from CLI input
void SLD::assembleFromCLI(const std::string& inputString) {
    std::istringstream input(inputString);
    InputParser parser(&input);
    parser.parseCLI();

    // Populate components from parser data
    buses = parser.getBuses();
    transformers = parser.getTransformers();
    generators = parser.getGenerators();
    loads = parser.getLoads();
    transmissionLines = parser.getTransmissionLines();
    circuitBreakers = parser.getCircuitBreakers();
    relays = parser.getRelays();
    capacitors = parser.getCapacitors();
    reactors = parser.getReactors();
    grids = parser.getGrids();
    lines = parser.getLines();
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

std::vector<Line>& SLD::getLines() {
    return lines;
}

const std::vector<Line>& SLD::getLines() const {
    return lines;
}
