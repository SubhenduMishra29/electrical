#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>
#include <vector>
#include <istream>
#include <iostream>
#include <fstream>
#include <mutex>
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

// Forward declarations of classes representing SLD components.
class Bus;
class Transformer;
class Generator;
class Load;
class TransmissionLine;
class CircuitBreaker;
class Relay;
class Capacitor;
class Reactor;
class Grid;
class Line;

/**
 * @brief Sets the input stream for the parser.
 * @param stream A pointer to a std::stringstream object to be used as input.
 */
void set_input_stream(std::stringstream* stream);

/**
 * @class InputParser
 * @brief Parses input files and initializes the SLD components.
 * 
 * The InputParser class reads data from input files or command-line interfaces
 * to create instances of various SLD components such as buses, transformers,
 * generators, loads, transmission lines, circuit breakers, relays, capacitors,
 * reactors, grids, and lines.
 */
class InputParser {
public:
    InputParser();
    InputParser(const std::string& filename);
    InputParser(std::istream* cliStream);
    ~InputParser();

    void parseFile();
    void parseCLI();

    std::vector<Bus>& getBuses();
    std::vector<Transformer>& getTransformers();
    std::vector<Generator>& getGenerators();
    std::vector<Load>& getLoads();
    std::vector<TransmissionLine>& getTransmissionLines();
    std::vector<CircuitBreaker>& getCircuitBreakers();
    std::vector<Relay>& getRelays();
    std::vector<Capacitor>& getCapacitors();
    std::vector<Reactor>& getReactors();
    std::vector<Grid>& getGrids();
    std::vector<Line>& getLines();

    void addBus(const std::string& id, const std::string& voltage);

private:
    std::string filename;
    std::istream* cliStream;
    std::ifstream fileStream;
    std::mutex busMutex;

    void resetParserState();

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
