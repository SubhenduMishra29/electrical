/*
 * File: wire.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Wire class representing a connection between rung elements.
 * License: GPL (General Public License)
 */

#include "wire.h"

// Constructor initializes the wire with start and end elements
Wire::Wire(std::shared_ptr<RungElement> start, std::shared_ptr<RungElement> end)
    : startElement(start), endElement(end) {}

// Get the start element of the wire
std::shared_ptr<RungElement> Wire::getStartElement() const {
    return startElement;
}

// Get the end element of the wire
std::shared_ptr<RungElement> Wire::getEndElement() const {
    return endElement;
}
