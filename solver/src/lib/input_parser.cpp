#include "lib/input_parser.h"
#include <iostream>   // For std::cerr and std::endl
#include <fstream>    // For std::ifstream
#include <cstdio>     // For FILE* and fopen

#include "parser.tab.hpp"  // Include your generated parser header

#include "lib/bus.h"           // Include full definition of Bus
#include "lib/transformer.h"   // Include full definition of Transformer
#include "lib/generator.h"     // Include full definition of Generator
#include "lib/load.h"          // Include full definition of Load
#include "lib/transmission_line.h" // Include full definition of TransmissionLine
#include "lib/circuit_breaker.h"   // Include full definition of CircuitBreaker
#include "lib/relay.h"        // Include full definition of Relay
#include "lib/capacitor.h"    // Include full definition of Capacitor
#include "lib/reactor.h"      // Include full definition of Reactor
#include "lib/grid.h"         // Include full definition of Grid
#include "lib/line.h"         // Include full definition of Line

// Forward declarations of parser and lexer functions
extern "C" {
    void yyerror(const char*);
    extern FILE* yyin;  // Use the FILE* global variable for Flex
}

// Constructor for file input
InputParser::InputParser(const std::string& filename)
    : filename(filename), cliStream(nullptr), fileStream(nullptr) {
    // Open file using C FILE* for Flex
    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    } else {
        yyin = file;  // Set yyin to the opened file
    }
}

// Constructor for CLI input
InputParser::InputParser(std::istream* cliStream) 
    : filename(""), cliStream(cliStream), fileStream(nullptr) {
    if (!cliStream) {
        std::cerr << "CLI stream is not set." << std::endl;
    } else {
        yyin = stdin;  // Use stdin for CLI input
    }
}

// Destructor to clean up resources
InputParser::~InputParser() {
    // Clean up the file stream if it was allocated
    if (yyin && yyin != stdin) {
        fclose(yyin);  // Close the file if it was opened
    }
}

// Method to parse file input
void InputParser::parseFile() {
    if (!yyin) {
        std::cerr << "Failed to open or read file: " << filename << std::endl;
        return;
    }

    // Call the parser
    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
    }
}

// Method to parse CLI input
void InputParser::parseCLI() {
    if (!cliStream) {
        std::cerr << "CLI stream is not set." << std::endl;
        return;
    }

    yyin = stdin;  // Use stdin for CLI input

    // Call the parser
    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
    }
}

// Reset parser state
void InputParser::resetParserState() {
    buses.clear();
    transformers.clear();
    generators.clear();
    loads.clear();
    transmissionLines.clear();
    circuitBreakers.clear();
    relays.clear();
    capacitors.clear();
    reactors.clear();
    grids.clear();
    lines.clear();
}

// Getter methods for parsed data
std::vector<Bus>& InputParser::getBuses() {
    return buses;
}

std::vector<Transformer>& InputParser::getTransformers() {
    return transformers;
}

std::vector<Generator>& InputParser::getGenerators() {
    return generators;
}

std::vector<Load>& InputParser::getLoads() {
    return loads;
}

std::vector<TransmissionLine>& InputParser::getTransmissionLines() {
    return transmissionLines;
}

std::vector<CircuitBreaker>& InputParser::getCircuitBreakers() {
    return circuitBreakers;
}

std::vector<Relay>& InputParser::getRelays() {
    return relays;
}

std::vector<Capacitor>& InputParser::getCapacitors() {
    return capacitors;
}

std::vector<Reactor>& InputParser::getReactors() {
    return reactors;
}

std::vector<Grid>& InputParser::getGrids() {
    return grids;
}

std::vector<Line>& InputParser::getLines() {
    return lines;
}