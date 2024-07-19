#include "lib/sld.h"
#include "lib/input_parser.h"
#include <sstream>
#include <iostream>

SLD::SLD() {
    // Constructor implementation
}

SLD::~SLD() {
    // Destructor implementation
}

void SLD::assemble(const std::string& filename) {
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

void SLD::assembleFromCLI(const std::string& cliInput) {
    std::istringstream input(cliInput);
    InputParser parser("");
    parser.parseCLI(input);

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
