#include "coil.h"

Coil::Coil(std::string name) : name(name) {}

bool Coil::evaluate(std::unordered_map<std::string, bool>& states) {
    return states[name];
}

std::string Coil::getName() const {
    return name;
}
