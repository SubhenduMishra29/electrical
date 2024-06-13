/*
 * File: wire.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Wire class representing a connection between rung elements.
 * License: GPL (General Public License)
 */

#ifndef WIRE_H
#define WIRE_H

#include <memory>
#include "rung_element.h"

// Class representing a wire connecting two elements in a rung
class Wire {
private:
    std::shared_ptr<RungElement> startElement; // Starting element of the wire
    std::shared_ptr<RungElement> endElement;   // Ending element of the wire

public:
    // Constructor initializes the wire with start and end elements
    Wire(std::shared_ptr<RungElement> start, std::shared_ptr<RungElement> end);

    // Get the start element of the wire
    std::shared_ptr<RungElement> getStartElement() const;

    // Get the end element of the wire
    std::shared_ptr<RungElement> getEndElement() const;
};

#endif // WIRE_H
