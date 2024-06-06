/*
 * File: pushbutton.cpp
 * Author: Subhendu Mishra
 * Description: Declaration of PushButton class for representing a push button element.
 * License: GPL (General Public License)
 */

// pushbutton.cpp
#include "pushbutton.h"
#include "wire.h" // Include Wire class header

PushButton::PushButton(std::string name, bool state) : name(name), state(state) {}

bool PushButton::evaluate(std::unordered_map<std::string, bool>& states) {
    // Evaluate the push button based on its current state
    return state;
}

std::string PushButton::getName() const {
    return name;
}

void PushButton::setState(bool state) {
    this->state = state;
}

void PushButton::connectTo(std::shared_ptr<RungElement> element) {
    // Create a wire and add it to connections vector
    auto wire = std::make_shared<Wire>(shared_from_this(), element);
    connections.push_back(wire);
}

void PushButton::disconnectFrom(std::shared_ptr<RungElement> element) {
    // Remove all wires connected to the specified element
    connections.erase(std::remove_if(connections.begin(), connections.end(),
        [element](const std::shared_ptr<Wire>& wire) {
            return wire->getEndElement() == element;
        }), connections.end());
}

bool PushButton::isConnectedTo(std::shared_ptr<RungElement> element) const {
    // Check if any wire is connected to the specified element
    for (const auto& wire : connections) {
        if (wire->getEndElement() == element) {
            return true;
        }
    }
    return false;
}
