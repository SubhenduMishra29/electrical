// rung_element.cpp
#include "rung_element.h"

void RungElement::connectTo(std::shared_ptr<RungElement> element) {
    // Create a wire and add it to connections vector
    auto wire = std::make_shared<Wire>(shared_from_this(), element);
    connections.push_back(wire);
}

void RungElement::disconnectFrom(std::shared_ptr<RungElement> element) {
    // Remove all wires connected to the specified element
    connections.erase(std::remove_if(connections.begin(), connections.end(),
        [element](const std::shared_ptr<Wire>& wire) {
            return wire->getEndElement() == element;
        }), connections.end());
}

bool RungElement::isConnectedTo(std::shared_ptr<RungElement> element) const {
    // Check if any wire is connected to the specified element
    for (const auto& wire : connections) {
        if (wire->getEndElement() == element) {
            return true;
        }
    }
    return false;
}
