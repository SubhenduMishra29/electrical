/*
 * File: coil.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Coil class representing a coil element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef COIL_H
#define COIL_H

#include "rung_element.h"

class Coil : public RungElement {
private:
    std::string name;

public:
    // Constructor initializes the coil element with a name.
    Coil(std::string name);

    // Evaluate the coil element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the coil element.
    std::string getName() const override;
};

#endif // COIL_H
