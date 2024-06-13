/*
 * File: rung_element.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the RungElement class, the base class for elements in a ladder logic rung.
 * License: GPL (General Public License)
 */
/*
 * File: rung_element.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the RungElement class.
 * License: GPL (General Public License)
 */

#include "rung_element.h"
#include "wire.h"

// Connect this element to another element
void RungElement::connectTo(std::shared_ptr<RungElement> element) {
    connections.push_back(std::make_shared<Wire>(shared_from_this(), element));
}

// Check if this element is connected to another element
bool RungElement::isConnectedTo(std::shared_ptr<RungElement> element) const {
    for (const auto& connection : connections) {
        if (connection->getEndElement() == element) {
            return true;
        }
    }
    return false;
}
