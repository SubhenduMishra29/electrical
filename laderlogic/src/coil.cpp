// File: coil.cpp
// Author: Subhendu Mishra
// Description: Implementation of the Coil class representing a coil element in ladder logic programming.
// License: GPL (General Public License)


#include "coil.h"
#include "wire.h" // Include Wire class header

Coil::Coil(std::string name) : name(name) {}

bool Coil::evaluate(std::unordered_map<std::string, bool>& states) {
    // Coil evaluation logic based on the current states
    // For simplicity, let's assume it evaluates based on connections
    for (const auto& connection : connections) {
        // Evaluate based on connected element's state
        if (connection->getStartElement()->evaluate(states)) {
            return true; // Coil is ON if at least one connection is active
        }
    }
    return false; // Coil is OFF if no connection is active
}

std::string Coil::getName() const {
    return name;
}

void Coil::connectTo(std::shared_ptr<RungElement> element) {
    // Create a wire and add it to connections vector
    auto wire = std::make_shared<Wire>(shared_from_this(), element);
    connections.push_back(wire);
}

void Coil::disconnectFrom(std::shared_ptr<RungElement> element) {
    // Remove all wires connected to the specified element
    connections.erase(std::remove_if(connections.begin(), connections.end(),
        [element](const std::shared_ptr<Wire>& wire) {
            return wire->getEndElement() == element;
        }), connections.end());
}

bool Coil::isConnectedTo(std::shared_ptr<RungElement> element) const {
    // Check if any wire is connected to the specified element
    for (const auto& wire : connections) {
        if (wire->getEndElement() == element) {
            return true;
        }
    }
    return false;
}
