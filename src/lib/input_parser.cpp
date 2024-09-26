#include "lib/input_parser.h"
#include "parser.tab.hpp"
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <algorithm>

extern "C" {
    void yyerror(const char* msg);
    extern FILE* yyin;
}



InputParser::InputParser() : cliStream(nullptr), filename("") {}

InputParser::InputParser(const std::string& filename)
    : filename(filename), cliStream(nullptr) {
    std::cout << "Loading from file: " << filename << std::endl;
    fileStream.open(filename);
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        throw std::runtime_error("File open failed");
    }
    // Redirect yyin to the file stream if needed
    yyin = fopen(filename.c_str(), "r");
    if (!yyin) {
        std::cerr << "Failed to open file stream: " << strerror(errno) << std::endl;
        throw std::runtime_error("File stream failed");
    }
}

InputParser::InputParser(std::istream* cliStream)
    : cliStream(cliStream), filename("") {
    // Redirect yyin to stdin for CLI input
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
    if (!fileStream.is_open()) {
        std::cerr << "File stream is not open." << std::endl;
        return;
    }
    
    if (yyin) {
        fclose(yyin);
    }
    yyin = fopen(filename.c_str(), "r");
    if (!yyin) {
        std::cerr << "Failed to reopen file stream: " << strerror(errno) << std::endl;
        return;
    }

    std::cout << "Parsing file: " << filename << std::endl;
    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
    }
}

void InputParser::parseCLI() {
    if (!cliStream) {
        std::cerr << "CLI stream is not set." << std::endl;
        return;
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
    yyin = stdin;

    std::cout << "Parsing from CLI input" << std::endl;
    if (yyparse() != 0) {
        std::cerr << "CLI Parsing failed." << std::endl;
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
std::vector<std::shared_ptr<Line>>& InputParser::getLines() { return lines; }

void InputParser::addBus(const std::string& id, const std::string& voltage) {
    std::lock_guard<std::mutex> lock(busMutex);  // Ensure thread safety
    Bus newBus(id, voltage);
    buses.push_back(newBus);
}

void InputParser::addLine(const std::string& id) {
    std::lock_guard<std::mutex> lock(busMutex);
    auto it = std::find_if(lines.begin(), lines.end(), [&id](const std::shared_ptr<Line>& line) {
        return line->getId() == id;
    });
    if (it == lines.end()) {
        lines.push_back(std::make_shared<Line>(id));  // Add shared_ptr to lines
    } else {
        std::cerr << "Line with ID " << id << " already exists." << std::endl;
    }
}

void InputParser::addConnectionToBus(const std::string& busId, const std::string& lineId, bool isIncoming) {
    std::cout << "Entering addConnectionToBus method" << std::endl;

    // Find the bus by its ID
    auto busIt = std::find_if(buses.begin(), buses.end(), [&busId](const Bus& bus) {
        return bus.getId() == busId;
    });

    if (busIt == buses.end()) {
        std::cerr << "Bus with ID " << busId << " not found. Cannot add connection." << std::endl;
        return;
    }

    // Find the line by its ID
    auto lineIt = std::find_if(lines.begin(), lines.end(), [&lineId](const std::shared_ptr<Line>& line) {
        return line->getId() == lineId;
    });

    if (lineIt != lines.end()) {
        busIt->addLine(*lineIt);  // Add line as incoming or outgoing
        std::cout << "Line " << lineId << " connected to Bus " << busId << std::endl;
    } else {
        std::cerr << "Line with ID " << lineId << " not found." << std::endl;
    }
}
void InputParser::addGrid(const std::string& id, const std::string& voltage){
    std::cout << "Entering addGrid method" << std::endl;
    std::lock_guard<std::mutex> lock(busMutex);  // Ensure thread safety
    Grid newGrid(id, voltage);
    grids.push_back(newGrid);
}
void InputParser::displayInfo() const {
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>InputParser Data<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

    std::cout << "Buses:" << std::endl;
    for (const auto& bus : buses) {
        bus.displayInfo(); // Assuming Bus class has a displayInfo() method
    }

    std::cout << "Transformers:" << std::endl;
    for (const auto& transformer : transformers) {
        //transformer.displayInfo(); // Assuming Transformer class has a displayInfo() method
    }

    std::cout << "Generators:" << std::endl;
    for (const auto& generator : generators) {
        //generator.displayInfo(); // Assuming Generator class has a displayInfo() method
    }

    std::cout << "Loads:" << std::endl;
    for (const auto& load : loads) {
        //load.displayInfo(); // Assuming Load class has a displayInfo() method
    }

    std::cout << "Transmission Lines:" << std::endl;
    for (const auto& transmissionLine : transmissionLines) {
        //transmissionLine.displayInfo(); // Assuming TransmissionLine class has a displayInfo() method
    }

    std::cout << "Circuit Breakers:" << std::endl;
    for (const auto& circuitBreaker : circuitBreakers) {
        //circuitBreaker.displayInfo(); // Assuming CircuitBreaker class has a displayInfo() method
    }

    std::cout << "Relays:" << std::endl;
    for (const auto& relay : relays) {
        //relay.displayInfo(); // Assuming Relay class has a displayInfo() method
    }

    std::cout << "Capacitors:" << std::endl;
    for (const auto& capacitor : capacitors) {
        //capacitor.displayInfo(); // Assuming Capacitor class has a displayInfo() method
    }

    std::cout << "Reactors:" << std::endl;
    for (const auto& reactor : reactors) {
        //reactor.displayInfo(); // Assuming Reactor class has a displayInfo() method
    }

    std::cout << "Grids:" << std::endl;
    for (const auto& grid : grids) {
        grid.displayInfo(); // Assuming Grid class has a displayInfo() method
    }

    std::cout << "Lines:" << std::endl;
    for (const auto& line : lines) {
        line->displayInfo(); // Assuming Line class has a displayInfo() method
    }
    std::cout << "################################################################" << std::endl;
}