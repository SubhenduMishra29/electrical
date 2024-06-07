/*
 * File: bulb.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Bulb class representing a bulb element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef BULB_H
#define BULB_H

#include "rung_element.h"

class Bulb : public RungElement {
private:
    std::string name;

public:
    // Constructor initializes the bulb element with a name.
    Bulb(std::string name);

    // Evaluate the bulb element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the bulb element.
    std::string getName() const override;

    // Method to check if the Bulb is a terminating element.
    bool isTerminatingElement() const override;
};

#endif // BULB_H

