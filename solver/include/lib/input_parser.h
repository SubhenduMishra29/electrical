#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

/*
 * File: InputParser.h
 * Author: Subhendu Mishra
 * Description: Header file for the InputParser class, responsible for parsing input files
 *              and initializing the SLD (Single Line Diagram) with the components defined in the file.
 * License: GPL
 */

#include <vector>
#include <string>
#include <sstream>
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
#include "line.h"

class InputParser {
public:
    // Constructors
    InputParser();
    explicit InputParser(const std::string& filename);

    // Destructor
    ~InputParser();

    // File and CLI Parsing
    void parseFile();
    void parseCLI(std::istringstream& input);

    // Getter methods for the parsed components
    std::vector<Bus> getBuses() const;
    std::vector<Transformer> getTransformers() const;
    std::vector<Generator> getGenerators() const;
    std::vector<Load> getLoads() const;
    std::vector<TransmissionLine> getTransmissionLines() const;
    std::vector<CircuitBreaker> getCircuitBreakers() const;
    std::vector<Relay> getRelays() const;
    std::vector<Capacitor> getCapacitors() const;
    std::vector<Reactor> getReactors() const;
    std::vector<Grid> getGrids() const;
    std::vector<Line> getLines() const;

    // Methods to add component definitions
    void addBusDefinition(int busNumber, double voltage, double angle, double loadMW, double loadMVAR);
    void addTransformerDefinition(int transformerID, int primaryBus, int secondaryBus, double impedance, double rating);
    void addGridDefinition(double voltage, const std::string& type);
    // Additional methods for other components like generators, lines, etc., can be added here.

private:
    // Private methods
    void parse(std::istream& input); // Common parsing logic

    // Member variables
    std::string filename;
    std::vector<Bus> buses;
    std::vector<Transformer> transformers;
    std::vector<Generator> generators;
    std::vector<Load> loads;
    std::vector<TransmissionLine> transmissionLines;
    std::vector<CircuitBreaker> circuitBreakers;
    std::vector<Relay> relays;
    std::vector<Capacitor> capacitors;
    std::vector<Reactor> reactors;
    std::vector<Grid> grids;
    std::vector<Line> lines;
};

#endif // INPUT_PARSER_H
