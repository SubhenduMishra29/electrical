#include "InputParser.h"
#include "Bus.h"
#include "Transformer.h"
#include "Generator.h"
#include "Load.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to parse input file and initialize SLD components
void InputParser::parseInputFile(const std::string& filename, SLD& sld) {
    std::ifstream inputFile(filename);
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (std::getline(inputFile, line)) {
        if (line.find("BUS") == 0) {
            parseBus(line, sld);
        } else if (line.find("TRANSFORMER") == 0) {
            parseTransformer(line, sld);
        } else if (line.find("GENERATOR") == 0) {
            parseGenerator(line, sld);
        } else if (line.find("LOAD") == 0) {
            parseLoad(line, sld);
        } // Add other component parsers as needed
    }
}

// Helper function to parse bus components
void InputParser::parseBus(const std::string& line, SLD& sld) {
    std::istringstream iss(line);
    std::string type, name;
    double voltage;
    iss >> type >> name >> voltage;
    sld.getBuses().push_back(Bus(name, voltage));
}

// Helper function to parse transformer components
void InputParser::parseTransformer(const std::string& line, SLD& sld) {
    std::istringstream iss(line);
    std::string type, name, bus1, bus2;
    double turnsRatio;
    iss >> type >> name >> bus1 >> bus2 >> turnsRatio;
    sld.getTransformers().push_back(Transformer(name, bus1, bus2, turnsRatio));
}

// Helper function to parse generator components
void InputParser::parseGenerator(const std::string& line, SLD& sld) {
    std::istringstream iss(line);
    std::string type, name, bus, fuelType;
    double capacity;
    iss >> type >> name >> bus >> capacity >> fuelType;
    sld.getGenerators().push_back(Generator(name, bus, capacity, fuelType));
}

// Helper function to parse load components
void InputParser::parseLoad(const std::string& line, SLD& sld) {
    std::istringstream iss(line);
    std::string type, name, bus, loadType;
    double load;
    iss >> type >> name >> bus >> load >> loadType;
    sld.getLoads().push_back(Load(name, bus, load, loadType));
}

// Implement other parsing functions as needed
