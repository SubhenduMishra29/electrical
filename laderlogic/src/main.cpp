#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "simulator.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"
#include "bulb.h"

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
        std::string elementType, elementName;
        // Extract element type and name from the line
        iss >> elementType >> elementName;

        // Create an instance of the corresponding element class based on the type
        if (elementType == "Input") {
            bool initialState;
            // Extract additional information (e.g., initial state) if needed
            iss >> initialState;
            simulator.addInput(std::make_shared<PushButton>(elementName, initialState));
        } else if (elementType == "Output") {
            simulator.addOutput(std::make_shared<Bulb>(elementName, false)); // Initialize output with false state
        } else if (elementType == "Logic") {
            // Extract additional information (e.g., logic type) if needed
            LogicType logicType;
            // Parse logic type from the line and create LogicElement instance
            simulator.addLogicElement(std::make_shared<Contact>(elementName));
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
