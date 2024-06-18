#include "power_system.h"
#include <fstream>
#include <sstream>
#include "input_parser.h" // Include input parsing utility

PowerSystem::PowerSystem() {
    // Initialize any necessary components or configurations
}

void PowerSystem::loadSLD(const std::string& filename) {
    // Use input parsing utility to load data from file
    std::vector<std::string> lines = InputParser::parseInputFile(filename);

    // Iterate through parsed lines and initialize components
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "BUS") {
            std::string busName;
            int voltage;
            iss >> busName >> voltage;
            Bus* bus = new Bus(busName, voltage);
            buses.push_back(bus);
        }
        else if (type == "GENERATOR") {
            std::string genName, busName, genType;
            int capacity;
            iss >> genName >> busName >> capacity >> genType;
            Generator* generator = new Generator(genName, capacity, genType);
            for (auto& bus : buses) {
                if (bus->getName() == busName) {
                    bus->addGenerator(generator);
                    break;
                }
            }
        }
        else if (type == "LOAD") {
            std::string loadName, busName, loadType;
            int powerConsumption;
            iss >> loadName >> busName >> powerConsumption >> loadType;
            Load* load = new Load(loadName, powerConsumption, loadType);
            for (auto& bus : buses) {
                if (bus->getName() == busName) {
                    bus->addLoad(load);
                    break;
                }
            }
        }
        else if (type == "TRANSFORMER") {
            std::string transName, bus1Name, bus2Name;
            double turnsRatio;
            iss >> transName >> bus1Name >> bus2Name >> turnsRatio;
            Bus* bus1 = nullptr;
            Bus* bus2 = nullptr;
            for (auto& bus : buses) {
                if (bus->getName() == bus1Name) {
                    bus1 = bus;
                }
                else if (bus->getName() == bus2Name) {
                    bus2 = bus;
                }
                if (bus1 && bus2) {
                    Transformer* transformer = new Transformer(transName, bus1, bus2, turnsRatio);
                    transformers.push_back(transformer);
                    bus1->addTransformer(transformer);
                    bus2->addTransformer(transformer);
                    break;
                }
            }
        }
    }
}

void PowerSystem::runSimulation() {
    // Implement simulation logic for the entire power system
    // Include transformer effects in the power flow analysis
    for (auto bus : buses) {
        bus->calculatePowerFlow(); // Calculate power flow for each bus
    }
    // Additional logic for simulation as needed
}
