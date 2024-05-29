// rung.cpp
#include "rung.h"
#include <unordered_map>

Rung::Rung() {}

void Rung::addElement(std::string name, bool state) {
    elements.push_back(std::make_pair(name, state));
}

bool Rung::evaluate(std::unordered_map<std::string, bool>& input_states) {
    bool result = true;
    for (auto& element : elements) {
        if (input_states.find(element.first) != input_states.end()) {
            if (input_states[element.first] != element.second) {
                result = false;
                break;
            }
        }
    }
    return result;
}

