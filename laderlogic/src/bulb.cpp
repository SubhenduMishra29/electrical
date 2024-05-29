#include "bulb.h"

Bulb::Bulb(std::string name) : name(name) {}

bool Bulb::evaluate(std::unordered_map<std::string, bool>& states) {
    return states[name];
}

std::string Bulb::getName() const {
    return name;
}
