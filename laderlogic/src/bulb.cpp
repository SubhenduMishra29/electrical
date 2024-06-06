// File: bulb.cpp
// Author: Subhendu Mishra
// Description: Implementation of the Bulb class representing a bulb element in ladder logic programming.
// License: GPL (General Public License)

// bulb.cpp
#include "bulb.h"

Bulb::Bulb(std::string name) : name(name) {}

bool Bulb::evaluate(std::unordered_map<std::string, bool>& states) {
    return states[name];
}

std::string Bulb::getName() const {
    return name;
}

bool Bulb::isTerminatingElement() const {
    return true; // Bulb is a terminating element
}
