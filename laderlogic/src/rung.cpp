/*
 * File: rung.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Rung class representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#include "rung.h"

// Add an element directly to the rung
void Rung::addElement(std::shared_ptr<RungElement> element) {
    elements.push_back(element);
}

// Add a submodule to the rung
void Rung::addSubmodule(std::shared_ptr<RungSubmodule> submodule) {
    submodules.push_back(submodule);
}

// Evaluate the rung based on the current states
bool Rung::evaluate(std::unordered_map<std::string, bool>& states) {
    bool result = true;

    // Evaluate elements directly in the rung
    for (const auto& element : elements) {
        result &= element->evaluate(states);
    }

    // Evaluate submodules within the rung
    for (const auto& submodule : submodules) {
        result &= submodule->evaluate(states);
    }

    return result;
}

// Check continuity of the rung
bool Rung::checkContinuity() {
    // Check continuity within the elements directly in the rung
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        if (!elements[i]->isConnectedTo(elements[i + 1])) {
            return false;
        }
    }

    // Check continuity within submodules
    for (const auto& submodule : submodules) {
        if (!submodule->evaluate(states)) {
            return false;
        }
    }

    // Check if the rung terminates correctly
    if (!elements.empty() && elements.back()->isTerminatingElement()) {
        return true;
    }

    return false;
}
