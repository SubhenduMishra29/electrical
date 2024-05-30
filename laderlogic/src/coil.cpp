// File: coil.cpp
// Author: Subhendu Mishra
// Description: Implementation of the Coil class representing a coil element in ladder logic programming.
// License: GPL (General Public License)

#include "coil.h"

// Constructor initializes the coil element with a name.
Coil::Coil(std::string name) : name(name) {}

// Evaluate the coil element based on the current states.
bool Coil::evaluate(std::unordered_map<std::string, bool>& states) {
    // Retrieve the state of the input associated with this coil from the states map.
    return states[name];
}

// Get the name of the coil element.
std::string Coil::getName() const {
    return name;
}
