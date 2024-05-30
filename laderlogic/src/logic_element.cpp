/*
 * File: logic_element.cpp
 * Author: Subhendu Mishra
 * Description: Declaration of LogicElement class representing a logical element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef LOGIC_ELEMENT_H
#define LOGIC_ELEMENT_H

#include <string>
#include <unordered_map>

enum LogicType {
    AND,
    OR,
    NOT
};

class LogicElement {
private:
    std::string name;   // Name of the logical element
    bool state;         // Current state of the logical element
    LogicType type;     // Type of logic operation performed by the element

public:
    // Constructor initializes the logic element with a name, initial state, and logic type.
    LogicElement(std::string name, bool state, LogicType type);

    // Evaluate the logic element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states);
};

#endif /* LOGIC_ELEMENT_H */
