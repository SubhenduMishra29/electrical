#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "simulator.h"

int main() {
    // Open the ladder logic file
    std::ifstream file("ladder_logic.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // Create a simulator
    Simulator simulator;

    std::string line;
    while (std::getline(file, line)) {
        // Parse the line to extract information about elements
        std::istringstream iss(line);
        std::string elementName, elementType;
        // Extract element name and type from the line
        iss >> elementName >> elementType;

        // Create an instance of the corresponding element class based on the type
        if (elementType == "Input") {
            bool initialState;
            // Extract additional information (e.g., initial state) if needed
            iss >> initialState;
            simulator.addInput(elementName, initialState);
        } else if (elementType == "Output") {
            simulator.addOutput(elementName, false); // Initialize output with false state
        } else if (elementType == "Logic") {
            // Extract additional information (e.g., logic type) if needed
            LogicType logicType;
            // Parse logic type from the line and create LogicElement instance
            simulator.addLogicElement(elementName, logicType);
        }
        // Add support for other element types as needed (e.g., Timer)
    }

    // Close the file
    file.close();

    // Simulate the ladder logic program
    simulator.simulate();

    // Output the final state of the outputs
    std::cout << "Final Output States:" << std::endl;
    auto outputs = simulator.getOutputStates();
    for (const auto& [outputName, state] : outputs) {
        std::cout << outputName << ": " << (state ? "true" : "false") << std::endl;
    }

    return 0;
}
