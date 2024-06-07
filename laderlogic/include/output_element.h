/*
 * File: output_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of the OutputElement class representing an output element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef OUTPUT_ELEMENT_H
#define OUTPUT_ELEMENT_H

#include "rung_element.h"
#include <unordered_map>
#include <string>

class OutputElement : public RungElement {
private:
    std::string name;   // Name of the output element
    bool state;         // Current state of the output element

public:
    // Constructor initializes the output element with a name and initial state.
    OutputElement(std::string name, bool state);

    // Evaluate the output element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the output element.
    std::string getName();

    // Get the state of the output element.
    bool getState();
};

#endif // OUTPUT_ELEMENT_H
