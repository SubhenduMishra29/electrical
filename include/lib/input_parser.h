#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>
#include <vector>
#include <istream>
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
 * @class InputParser
 * @brief Parses input files and initializes the SLD components.
 */
class InputParser {
public:
    InputParser();
    explicit InputParser(const std::string& filename);
    explicit InputParser(std::istream* cliStream);
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
    std::vector<std::shared_ptr<Line>>& getLines();  // Update return type to shared_ptr

    // New method for displaying parsed data
    void displayInfo() const;
    void addBus(const std::string& id, const std::string& voltage);
    void addLine(const std::string& id);
    void addConnectionToBus(const std::string& busId, const std::string& lineId, bool isIncoming);
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
    std::vector<std::shared_ptr<Line>> lines;
//extern InputParser parser; // Declare the global instance

};

#endif // INPUT_PARSER_H
