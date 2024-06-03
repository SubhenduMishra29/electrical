#include "simulator.h"
#include "file_handler.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"
#include "rung.h"
#include <iostream>
#include <unordered_map>

int main() {
    // Parse ladder logic file
    std::unordered_map<std::string, bool> elements = FileHandler::parseInputFile("ladder_logic.txt");

    // Create a simulator
    Simulator simulator;

    std::unordered_map<std::string, std::shared_ptr<RungElement>> element_map;
    for (const auto& [elementName, initialState] : elements) {
        if (elementName.find("PushButton") != std::string::npos) {
            auto pushButtonElement = std::make_shared<PushButton>(elementName, initialState);
            simulator.setInput(elementName, initialState);
            element_map[elementName] = pushButtonElement;
        } else if (elementName.find("Contact") != std::string::npos) {
            auto contactElement = std::make_shared<Contact>(elementName, initialState);
            simulator.setInput(elementName, initialState);
            element_map[elementName] = contactElement;
        } else if (elementName.find("Coil") != std::string::npos) {
            auto coilElement = std::make_shared<Coil>(elementName, initialState);
            element_map[elementName] = coilElement;
        } else if (elementName.find("Rung") != std::string::npos) {
            // Extract input and output elements from elementName
            std::string inputName, outputName;
            // Parse inputName and outputName from elementName
            Rung rung;
            rung.addElement(element_map[inputName]);
            rung.addElement(element_map[outputName]);
            simulator.addRung(rung);
        }
    }

    // Simulate the ladder logic
    simulator.simulate();

    // Output the final state of the coil
    std::cout << "Final state of the coil: " << (simulator.getOutput("OutputCoil") ? "true" : "false") << std::endl;

    return 0;
}
#include "simulator.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"
#include "logic_element.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

int main() {
    // Open the ladder logic file
    std::ifstream file("ladder_logic.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // Create a simulator
    Simulator simulator;

    std::unordered_map<std::string, std::shared_ptr<RungElement>> element_map;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string elementType, elementName, logicType, input1, input2;

        iss >> elementType >> elementName;

        if (elementType == "Input") {
            bool initialState;
            iss >> initialState;
            auto inputElement = std::make_shared<PushButton>(elementName, initialState);
            simulator.setInput(elementName, initialState);
            element_map[elementName] = inputElement;
        } else if (elementType == "Coil") {
            auto coilElement = std::make_shared<Coil>(elementName, false);
            element_map[elementName] = coilElement;
            Rung rung;
            rung.addElement(coilElement);
            simulator.addRung(rung);
        } else if (elementType == "Logic") {
            iss >> logicType >> input1 >> input2;
            LogicType logic_type = (logicType == "AND") ? LogicType::AND : LogicType::OR;
            auto logicElement = std::make_shared<LogicElement>(elementName, true, logic_type);
            element_map[elementName] = logicElement;
            Rung rung;
            rung.addElement(element_map[input1]);
            rung.addElement(element_map[input2]);
            rung.addElement(logicElement);
            simulator.addRung(rung);
        }
    }

    file.close();

    simulator.simulate();

    // Output the final state of the outputs
    std::cout << "Final Output States:" << std::endl;
    auto outputs = simulator.getOutputStates();
    for (const auto& [outputName, state] : outputs) {
        std::cout << outputName << ": " << (state ? "true" : "false") << std::endl;
    }

    return 0;
}
