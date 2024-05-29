#include "simulator.h"
#include <iostream>

Simulator::Simulator() {}

void Simulator::setInput(std::string name, bool state) {
    input_states[name] = state;
}

bool Simulator::getOutput(std::string name) {
    return output_states[name];
}

void Simulator::addRung(Rung rung) {
    ladder_logic.push_back(rung);
}

void Simulator::simulate() {
    for (auto& rung : ladder_logic) {
        bool result = rung.evaluate(input_states);
        for (auto& element : rung.getElements()) {
            if (input_states.find(element.first) == input_states.end()) {
                output_states[element.first] = result;
                break;
            }
        }
    }
}
