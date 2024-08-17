#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

/*
 * File: InputParser.h
 * Author: Subhendu Mishra
 * Description: Header file for the InputParser class, responsible for parsing input files
 *              and initializing the SLD (Single Line Diagram) with the components defined in the file.
 * License: GPL
 */



#include <string>
#include <vector>
#include <istream>
#include <iostream>   // For std::cerr and std::endl
#include <fstream> // Include for std::ifstream

// Forward declarations
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
extern std::stringstream* yyin_stream; // Declaration

void set_input_stream(std::stringstream* stream);

class InputParser {
public:
    // Constructor for file input
    InputParser(const std::string& filename);
    
    // Constructor for CLI input
    InputParser(std::istream* cliStream);

    ~InputParser(); // Destructor to clean up resources

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

private:
    std::string filename;   // Filename for file input
    std::istream* cliStream; // Pointer to stream for CLI input
    std::ifstream* fileStream; // Pointer to file stream for file input

    // Parser and lexer methods
    void resetParserState();

    // Vector containers for parsed data
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