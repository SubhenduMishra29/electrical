/**
 * @file InputParser.cpp
 * @author Subhendu Mishra
 * @date 2024-08-17
 * @brief Implementation file for the InputParser class, responsible for parsing input files
 *        and initializing the SLD (Single Line Diagram) with the components defined in the file.
 * 
 * This file contains the implementation of the InputParser class methods, which are used
 * to parse input data from files or command-line interfaces (CLI) and store the results as
 * components of a Single Line Diagram (SLD) for power system simulations.
 * 
 * @license GNU General Public License v3.0
 *          This program is free software: you can redistribute it and/or modify
 *          it under the terms of the GNU General Public License as published by
 *          the Free Software Foundation, either version 3 of the License, or
 *          (at your option) any later version.
 *          
 *          This program is distributed in the hope that it will be useful,
 *          but WITHOUT ANY WARRANTY; without even the implied warranty of
 *          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *          GNU General Public License for more details.
 *          
 *          You should have received a copy of the GNU General Public License
 *          along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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
/**
 * @brief Constructs an InputParser object for file input.
 * @param filename The name of the file to be parsed.
 */
InputParser::InputParser(const std::string& filename)
    : filename(filename), cliStream(nullptr) {
    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    } else {
        yyin = file;  // Set yyin to the opened file
    }
}

// Constructor for CLI input
/**
 * @brief Constructs an InputParser object for CLI input.
 * @param cliStream A pointer to an input stream for CLI input.
 */
InputParser::InputParser(std::istream* cliStream) 
    : filename(""), cliStream(cliStream) {
    if (!cliStream) {
        std::cerr << "CLI stream is not set." << std::endl;
    } else {
        yyin = stdin;  // Use stdin for CLI input
    }
}

// Destructor to clean up resources
/**
 * @brief Destructor to clean up resources.
 * Closes the file stream if it was allocated.
 */
InputParser::~InputParser() {
    if (yyin && yyin != stdin) {
        fclose(yyin);  // Close the file if it was opened
    }
}

// Method to parse file input
/**
 * @brief Parses the input file specified in the constructor.
 * Calls the parser and reports if parsing fails.
 */
void InputParser::parseFile() {
    if (!yyin) {
        std::cerr << "Input stream is not set." << std::endl;
        return;
    }

    // Call the parser
    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
    }
}

// Method to parse CLI input
/**
 * @brief Parses the input from the CLI stream specified in the constructor.
 * Calls the parser and reports if parsing fails.
 */
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
/**
 * @brief Resets the state of the parser.
 * Clears all vectors containing parsed data.
 */
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

/**
 * @brief Gets the list of buses parsed from the input.
 * @return A reference to a vector of Bus objects.
 */
std::vector<Bus>& InputParser::getBuses() { return buses; }

/**
 * @brief Gets the list of transformers parsed from the input.
 * @return A reference to a vector of Transformer objects.
 */
std::vector<Transformer>& InputParser::getTransformers() { return transformers; }

/**
 * @brief Gets the list of generators parsed from the input.
 * @return A reference to a vector of Generator objects.
 */
std::vector<Generator>& InputParser::getGenerators() { return generators; }

/**
 * @brief Gets the list of loads parsed from the input.
 * @return A reference to a vector of Load objects.
 */
std::vector<Load>& InputParser::getLoads() { return loads; }

/**
 * @brief Gets the list of transmission lines parsed from the input.
 * @return A reference to a vector of TransmissionLine objects.
 */
std::vector<TransmissionLine>& InputParser::getTransmissionLines() { return transmissionLines; }

/**
 * @brief Gets the list of circuit breakers parsed from the input.
 * @return A reference to a vector of CircuitBreaker objects.
 */
std::vector<CircuitBreaker>& InputParser::getCircuitBreakers() { return circuitBreakers; }

/**
 * @brief Gets the list of relays parsed from the input.
 * @return A reference to a vector of Relay objects.
 */
std::vector<Relay>& InputParser::getRelays() { return relays; }

/**
 * @brief Gets the list of capacitors parsed from the input.
 * @return A reference to a vector of Capacitor objects.
 */
std::vector<Capacitor>& InputParser::getCapacitors() { return capacitors; }

/**
 * @brief Gets the list of reactors parsed from the input.
 * @return A reference to a vector of Reactor objects.
 */
std::vector<Reactor>& InputParser::getReactors() { return reactors; }

/**
 * @brief Gets the list of grids parsed from the input.
 * @return A reference to a vector of Grid objects.
 */
std::vector<Grid>& InputParser::getGrids() { return grids; }

/**
 * @brief Gets the list of lines parsed from the input.
 * @return A reference to a vector of Line objects.
 */
std::vector<Line>& InputParser::getLines() { return lines; }
