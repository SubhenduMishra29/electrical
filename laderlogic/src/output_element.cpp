/*
 * File: output_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of OutputElement class for representing an output element.
 * License: GPL (General Public License)
 */

#ifndef OUTPUT_ELEMENT_H
#define OUTPUT_ELEMENT_H

#include <string>
#include <unordered_map>
#include "rung_element.h"

class OutputElement : public RungElement {
private:
    std::string name;
    bool state;

public:
    // Constructor initializes the output element with a name and initial state.
    OutputElement(std::string name, bool state);

    // Evaluate the output element and return its state.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the output element.
    std::string getName() override;

    // Get the state of the output element.
    bool getState();
};

#endif /* OUTPUT_ELEMENT_H */
