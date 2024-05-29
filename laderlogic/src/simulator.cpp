#include "simulator.h"

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
            if (auto coil = std::dynamic_pointer_cast<Coil>(element)) {
                output_states[coil->getName()] = result;
            } else if (auto bulb = std::dynamic_pointer_cast<Bulb>(element)) {
                output_states[bulb->getName()] = result;
            }
        }
    }
}
