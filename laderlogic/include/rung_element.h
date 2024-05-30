/*
 * File: rung_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of RungElement class, the base class for elements in a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_ELEMENT_H
#define RUNG_ELEMENT_H

#include <string>
#include <unordered_map>

class RungElement {
public:
    // Evaluate the rung element based on the current states.
    virtual bool evaluate(std::unordered_map<std::string, bool>& states) = 0;

    // Get the name of the rung element.
    virtual std::string getName() const = 0;

    // Virtual destructor for proper polymorphic behavior.
    virtual ~RungElement() = default;
};

#endif // RUNG_ELEMENT_H

