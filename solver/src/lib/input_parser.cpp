#include "lib/input_parser.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include "parser.tab.hpp" // Include the Bison-generated header
extern FILE* yyin;

InputParser::InputParser(const std::string& filename) : filename(filename) {}

void InputParser::parseFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    parse(file);
}

void InputParser::parseCLI(std::istringstream& input) {
    parse(input);
}

void InputParser::parse(std::istream& input) {
    // Create a temporary file
    std::ofstream tempFile("temp_input.txt");
    if (!tempFile.is_open()) {
        std::cerr << "Failed to create temporary file for parsing." << std::endl;
        return;
    }

    // Write the input stream to the temporary file
    tempFile << input.rdbuf();
    tempFile.close();

    // Open the temporary file for reading
    FILE* tempInput = fopen("temp_input.txt", "r");
    if (!tempInput) {
        std::cerr << "Failed to open temporary file for parsing." << std::endl;
        return;
    }

    // Set the input for the lexer
    yyin = tempInput;

    // Call the parser
    if (yyparse() != 0) {
        std::cerr << "Parsing failed!" << std::endl;
    }

    // Clean up
    fclose(tempInput);
    remove("temp_input.txt");
}

std::vector<Bus> InputParser::getBuses() const {
    return buses;
}

std::vector<Transformer> InputParser::getTransformers() const {
    return transformers;
}

std::vector<Generator> InputParser::getGenerators() const {
    return generators;
}

std::vector<Load> InputParser::getLoads() const {
    return loads;
}

std::vector<TransmissionLine> InputParser::getTransmissionLines() const {
    return transmissionLines;
}

std::vector<CircuitBreaker> InputParser::getCircuitBreakers() const {
    return circuitBreakers;
}

std::vector<Relay> InputParser::getRelays() const {
    return relays;
}

std::vector<Capacitor> InputParser::getCapacitors() const {
    return capacitors;
}

std::vector<Reactor> InputParser::getReactors() const {
    return reactors;
}

std::vector<Grid> InputParser::getGrids() const {
    return grids;
}

std::vector<Line> InputParser::getLines() const {
    return lines;
}
