#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

/**
 * @file InputParser.h
 * @author Subhendu Mishra
 * @date 2024-08-17
 * @brief Header file for the InputParser class, responsible for parsing input files
 *        and initializing the SLD (Single Line Diagram) with the components defined in the file.
 * 
 * This file contains the declaration of the InputParser class, which is used to parse
 * input data from files or command-line interfaces (CLI) and initialize the SLD components
 * such as buses, transformers, generators, loads, transmission lines, circuit breakers, 
 * relays, capacitors, reactors, grids, and lines.
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

/**
 * @brief Forward declarations of classes representing SLD components.
 */

#include <string>
#include <vector>
#include <istream>
#include <iostream>   // For std::cerr and std::endl
#include <fstream>    // Include for std::ifstream

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

/**
 * @brief Sets the input stream for the parser.
 * @param stream A pointer to a std::stringstream object to be used as input.
 */
void set_input_stream(std::stringstream* stream);

/**
 * @class InputParser
 * @brief Parses input files and initializes the SLD components.
 * 
 * The InputParser class is responsible for reading data from input files or command-line
 * interfaces and creating instances of SLD components such as buses, transformers, generators,
 * loads, transmission lines, circuit breakers, relays, capacitors, reactors, grids, and lines.
 */
class InputParser {
public:
    /**
     * @brief Constructor for file input.
     * @param filename The name of the file to be parsed.
     */
    InputParser(const std::string& filename);
    
    /**
     * @brief Constructor for CLI input.
     * @param cliStream A pointer to an input stream for CLI input.
     */
    InputParser(std::istream* cliStream);

    /**
     * @brief Destructor to clean up resources.
     */
    ~InputParser();

    /**
     * @brief Parses the input file specified in the constructor.
     */
    void parseFile();

    /**
     * @brief Parses the input from the CLI stream specified in the constructor.
     */
    void parseCLI();

    /**
     * @brief Gets the list of buses parsed from the input.
     * @return A reference to a vector of Bus objects.
     */
    std::vector<Bus>& getBuses();

    /**
     * @brief Gets the list of transformers parsed from the input.
     * @return A reference to a vector of Transformer objects.
     */
    std::vector<Transformer>& getTransformers();

    /**
     * @brief Gets the list of generators parsed from the input.
     * @return A reference to a vector of Generator objects.
     */
    std::vector<Generator>& getGenerators();

    /**
     * @brief Gets the list of loads parsed from the input.
     * @return A reference to a vector of Load objects.
     */
    std::vector<Load>& getLoads();

    /**
     * @brief Gets the list of transmission lines parsed from the input.
     * @return A reference to a vector of TransmissionLine objects.
     */
    std::vector<TransmissionLine>& getTransmissionLines();

    /**
     * @brief Gets the list of circuit breakers parsed from the input.
     * @return A reference to a vector of CircuitBreaker objects.
     */
    std::vector<CircuitBreaker>& getCircuitBreakers();

    /**
     * @brief Gets the list of relays parsed from the input.
     * @return A reference to a vector of Relay objects.
     */
    std::vector<Relay>& getRelays();

    /**
     * @brief Gets the list of capacitors parsed from the input.
     * @return A reference to a vector of Capacitor objects.
     */
    std::vector<Capacitor>& getCapacitors();

    /**
     * @brief Gets the list of reactors parsed from the input.
     * @return A reference to a vector of Reactor objects.
     */
    std::vector<Reactor>& getReactors();

    /**
     * @brief Gets the list of grids parsed from the input.
     * @return A reference to a vector of Grid objects.
     */
    std::vector<Grid>& getGrids();

    /**
     * @brief Gets the list of lines parsed from the input.
     * @return A reference to a vector of Line objects.
     */
    std::vector<Line>& getLines();

private:
    std::string filename;   ///< Filename for file input
    std::istream* cliStream; ///< Pointer to stream for CLI input
    std::ifstream* fileStream; ///< Pointer to file stream for file input

    /**
     * @brief Resets the state of the parser.
     */
    void resetParserState();

    // Vector containers for parsed data
    std::vector<Bus> buses; ///< Vector containing parsed Bus objects
    std::vector<Transformer> transformers; ///< Vector containing parsed Transformer objects
    std::vector<Generator> generators; ///< Vector containing parsed Generator objects
    std::vector<Load> loads; ///< Vector containing parsed Load objects
    std::vector<TransmissionLine> transmissionLines; ///< Vector containing parsed TransmissionLine objects
    std::vector<CircuitBreaker> circuitBreakers; ///< Vector containing parsed CircuitBreaker objects
    std::vector<Relay> relays; ///< Vector containing parsed Relay objects
    std::vector<Capacitor> capacitors; ///< Vector containing parsed Capacitor objects
    std::vector<Reactor> reactors; ///< Vector containing parsed Reactor objects
    std::vector<Grid> grids; ///< Vector containing parsed Grid objects
    std::vector<Line> lines; ///< Vector containing parsed Line objects
};

#endif // INPUT_PARSER_H
