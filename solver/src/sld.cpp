#include "SLD.h"
#include "InputParser.h"
#include "Bus.h"
#include "Transformer.h"
#include "Generator.h"
#include "Load.h"
#include "TransmissionLine.h"
#include "CircuitBreaker.h"
#include "Relay.h"
#include "Capacitor.h"
#include "Reactor.h"
#include "Grid.h"
#include "CT.h"
#include "PT.h"
#include "Line.h"

// Constructor
SLD::SLD() {
    // Constructor implementation, if needed
}

// Destructor
SLD::~SLD() {
    // Destructor implementation, if needed
}

// Function to assemble the SLD from a file
void SLD::assemble(const std::string& filename) {
    InputParser parser;
    parser.parseInputFile(filename, *this);
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
