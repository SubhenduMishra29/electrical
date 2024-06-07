/*
 * File: logic_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of the LogicElement class representing a logical element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef LOGIC_ELEMENT_H
#define LOGIC_ELEMENT_H

#include "rung_element.h"

// Enumeration for different types of logical operations
enum LogicType { AND, OR, NOT };

class LogicElement : public RungElement {
private:
    std::string name;   // Name of the logical element
    bool state;         // Current state of the logical element
    LogicType type;     // Type of logical operation performed by the element

public:
    // Constructor initializes the logical element with a name, initial state, and logic type.
    LogicElement(std::string name, bool state, LogicType type);

    // Evaluate the logical element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
};

#endif // LOGIC_ELEMENT_H

