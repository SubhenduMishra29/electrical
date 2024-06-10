// File: contact.cpp
// Author: Subhendu Mishra
// Description: Implementation of the Contact class representing a contact element in ladder logic programming.
// License: GPL (General Public License)

#include "contact.h"
#include "wire.h" // Include Wire class header
#include "coil.h" // Include Coil class header

Contact::Contact(std::string name, bool normallyOpen) : name(name), normallyOpen(normallyOpen) {}

bool Contact::evaluate(std::unordered_map<std::string, bool>& states) {
    // Retrieve the state of the input associated with this contact from the states map
    bool state = states[name];
    
    // If the contact is normally open, return its state directly.
    // If the contact is normally closed, return the opposite of its state.
    return normallyOpen ? state : !state;
}

std::string Contact::getName() const {
    return name;
}

void Contact::connectTo(std::shared_ptr<RungElement> element) {
    // Create a wire only if not already connected to the same element
    if (!isConnectedTo(element)) {
        auto wire = std::make_shared<Wire>(shared_from_this(), element);
        connections.push_back(wire);
    }
}

void Contact::disconnectFrom(std::shared_ptr<RungElement> element) {
    // Remove all wires connected to the specified element
    connections.erase(std::remove_if(connections.begin(), connections.end(),
        [element](const std::shared_ptr<Wire>& wire) {
            return wire->getEndElement() == element;
        }), connections.end());
}

bool Contact::isConnectedTo(std::shared_ptr<RungElement> element) const {
    // Check if any wire is connected to the specified element
    for (const auto& wire : connections) {
        if (wire->getEndElement() == element) {
            return true;
        }
    }
    return false;
}

void Contact::linkToCoil(std::shared_ptr<Coil> coil) {
    linkedCoil = coil;
    // Optionally, you can also connect this contact to the coil
    connectTo(coil);
}

bool Contact::isLinkedToCoil() const {
    return linkedCoil != nullptr;
}
