/*
 * File: simulator.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Simulator class for simulating ladder logic programs.
 * License: GPL (General Public License)
 */

#include "simulator.h"
#include "ladder_parser.h"
#include "parser.h"

// Constructor initializes the simulator with a ladder logic file
Simulator::Simulator(const std::string& filename) {
    // Parse ladder logic file to initialize input states
    input_states = LadderParser::parseLadderFile(filename);

    // Parse ladder logic file to initialize ladder logic structure
    ladder_logic = Parser::parseLadderFile(filename, input_states);
}

// Set an input state
void Simulator::setInput(const std::string& name, bool state) {
    input_states[name] = state;
}

// Get an output state
bool Simulator::getOutput(const std::string& name) {
    if (output_states.find(name) != output_states.end()) {
        return output_states[name];
    }
    return false;
}

// Run the simulation
void Simulator::simulate() {
    output_states.clear(); // Clear previous output states

    std::unordered_map<std::string, bool> states = input_states; // Copy input states for simulation

    // Evaluate ladder logic
    ladder_logic->evaluate(states);

    // Collect output states from ladder logic elements
    for (const auto& rung : ladder_logic->getRungs()) {
        for (const auto& element : rung->getElements()) {
            if (element->isTerminatingElement()) {
                output_states[element->getName()] = states[element->getName()];
            }
        }
    }
}

// Get the output states map
std::unordered_map<std::string, bool> Simulator::getOutputStates() const {
    return output_states;
}
