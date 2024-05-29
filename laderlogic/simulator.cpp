#include "simulator.h"

Simulator::Simulator() {}

void Simulator::setInput(const std::string& name, bool state) {
    input_states[name] = state;
}

bool Simulator::getOutput(const std::string& name) {
    return output_states[name];
}

void Simulator::addRung(Rung rung) {
    ladder_logic.push_back(rung);
}

void Simulator::simulate() {
    for (auto& rung : ladder_logic) {
        bool result = rung.evaluate(input_states);
        for (auto& element : rung.getElements()) {
            if (auto output = std::dynamic_pointer_cast<OutputElement>(element)) {
                output_states[output->getName()] = result;
            }
        }
    }
}

void Simulator::reset() {
    for (auto& rung : ladder_logic) {
        rung.resetTimers();
    }
}

