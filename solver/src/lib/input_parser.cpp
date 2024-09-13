#include "lib/input_parser.h"
#include "parser.tab.hpp"
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring> // For strerror

extern "C" {
    void yyerror(const char* msg);
    extern FILE* yyin;
}
InputParser::InputParser(){

}
InputParser::InputParser(const std::string& filename)
    : filename(filename), cliStream(nullptr) {
        std::cout << "Loading from file in InputParser : " << filename << std::endl;// Load from file
        fileStream.open(filename);
        if (!fileStream.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
        } else {
        // Set yyin to the file pointer
        yyin = fopen(filename.c_str(), "r");
        if (!yyin) {
            std::cerr << "Failed to open file stream: " << strerror(errno) << std::endl;
        }
    }
}

InputParser::InputParser(std::istream* cliStream)
    : filename(""), cliStream(cliStream) {
    // Set yyin to stdin for CLI input
    yyin = stdin;
}

InputParser::~InputParser() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
}

void InputParser::parseFile() {
    std::cout << "Entered parseFile in InputParser with file: " << filename << std::endl;
    if (!fileStream.is_open()) {
        std::cerr << "File stream is not open." << std::endl;
        return;
    }
    // Redirect yyin to the opened file
    if (yyin) {
        fclose(yyin);
    }
    yyin = fopen(filename.c_str(), "r");
    if (!yyin) {
        std::cerr << "Failed to open file stream: " << strerror(errno) << std::endl;
        return;
    }
    std::cout << "yyin is set to fileStream" << std::endl;
    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
    }
}

void InputParser::parseCLI() {
    if (!cliStream) {
        std::cerr << "CLI stream is not set." << std::endl;
        return;
    }
    // Redirect yyin to stdin
    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
    yyin = stdin;
    std::cout << "yyin is set to stdin" << std::endl;
    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
    }
}

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

std::vector<Bus>& InputParser::getBuses() { return buses; }
std::vector<Transformer>& InputParser::getTransformers() { return transformers; }
std::vector<Generator>& InputParser::getGenerators() { return generators; }
std::vector<Load>& InputParser::getLoads() { return loads; }
std::vector<TransmissionLine>& InputParser::getTransmissionLines() { return transmissionLines; }
std::vector<CircuitBreaker>& InputParser::getCircuitBreakers() { return circuitBreakers; }
std::vector<Relay>& InputParser::getRelays() { return relays; }
std::vector<Capacitor>& InputParser::getCapacitors() { return capacitors; }
std::vector<Reactor>& InputParser::getReactors() { return reactors; }
std::vector<Grid>& InputParser::getGrids() { return grids; }
std::vector<Line>& InputParser::getLines() { return lines; }

void InputParser::addBus(const std::string& id, const std::string& voltage) {
    std::cout << "Entering addBus method" << std::endl;

    // Mutex removed for testing
    // std::lock_guard<std::mutex> lock(busMutex);

    try {
        std::cout << "Checking buses capacity" << std::endl;
        std::cout << "Current buses capacity: " << buses.capacity() << std::endl;
        std::cout << "Creating new Bus object" << std::endl;
        Bus newBus(id, voltage);
        std::cout << "New Bus object created successfully" << std::endl;
        std::cout << "Adding Bus to vector" << std::endl;
        buses.push_back(newBus);
        std::cout << "Bus added to the vector. Current size: " << buses.size() << std::endl;
        std::cout << "Displaying all buses" << std::endl;
        for (const auto& bus : buses) {
            bus.displayInfo();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while adding a bus: " << e.what() << std::endl;
    }
}
