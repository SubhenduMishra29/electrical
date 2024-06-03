#include "simulator.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"
#include "bulb.h"
#include "logic_element.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Simulator::setInput(const std::string& name, bool state) {
    input_states[name] = state;
}

bool Simulator::getOutput(const std::string& name) {
    auto it = output_states.find(name);
    return (it != output_states.end()) ? it->second : false;
}

void Simulator::addRung(Rung rung) {
    ladder_logic.push_back(rung);
}

void Simulator::simulate() {
    std::unordered_map<std::string, bool> updated_output_states = output_states;

    for (auto& rung : ladder_logic) {
        bool result = rung.evaluate(input_states);

        for (auto& element : rung.getElements()) {
            if (auto coil = std::dynamic_pointer_cast<Coil>(element)) {
                updated_output_states[coil->getName()] = result;
            }
        }
    }

    output_states = updated_output_states;
}

std::unordered_map<std::string, bool> Simulator::getOutputStates() const {
    return output_states;
}
