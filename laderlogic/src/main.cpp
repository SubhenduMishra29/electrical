#include "simulator.h"
#include "ladder_parser.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"
#include "rung.h"
#include <iostream>
#include <unordered_map>

int main() {
    // Parse ladder logic file
    std::unordered_map<std::string, bool> elements = LadderParser::parseLadderFile("ladder_logic.txt");

    // Create a simulator
    Simulator simulator;

    // Process parsed elements
    for (const auto& [elementName, initialState] : elements) {
        if (elementName.find("PushButton") != std::string::npos) {
            auto pushButtonElement = std::make_shared<PushButton>(elementName, initialState);
            simulator.setInput(elementName, initialState);
        } else if (elementName.find("Contact") != std::string::npos) {
            auto contactElement = std::make_shared<Contact>(elementName, initialState);
            simulator.setInput(elementName, initialState);
        } else if (elementName.find("Coil") != std::string::npos) {
            auto coilElement = std::make_shared<Coil>(elementName, initialState);
        } else if (elementName.find("Rung") != std::string::npos) {
            // Extract input and output elements from elementName
            std::string inputName, outputName;
            // Parse inputName and outputName from elementName
            Rung rung;
            rung.addElement(simulator.getElement(inputName));
            rung.addElement(simulator.getElement(outputName));
            simulator.addRung(rung);
        }
    }

    // Simulate the ladder logic
    simulator.simulate();

    // Output the final state of the coil
    std::cout << "Final state of the coil: " << (simulator.getOutput("OutputCoil") ? "true" : "false") << std::endl;

    return 0;
}
