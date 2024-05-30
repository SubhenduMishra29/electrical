// File: bulb.cpp
// Author: Subhendu Mishra
// Description: Implementation of the Bulb class representing a bulb element in ladder logic programming.
// License: GPL (General Public License)

#include "bulb.h"

// Constructor initializes the bulb element with a name.
Bulb::Bulb(std::string name) : name(name) {}

// Evaluate the bulb element based on the current states.
bool Bulb::evaluate(std::unordered_map<std::string, bool>& states) {
    // Retrieve the state of the input associated with this bulb from the states map.
    return states[name];
}

// Get the name of the bulb element.
std::string Bulb::getName() const {
    return name;
}
