/*
 * File: output_element.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the OutputElement class for representing an output element.
 * License: GPL (General Public License)
 */

#include "output_element.h"

// Constructor initializes the output element with a name and initial state
OutputElement::OutputElement(std::string name, bool state) 
    : name(name), state(state) {}

// Evaluate the output element and return its state
bool OutputElement::evaluate(std::unordered_map<std::string, bool>& states) {
    if (states.find(name) != states.end()) {
        state = states[name];
    }
    return state;
}

// Get the name of the output element
std::string OutputElement::getName() {
    return name;
}

// Get the state of the output element
bool OutputElement::getState() {
    return state;
}

