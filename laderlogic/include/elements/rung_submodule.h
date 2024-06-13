/*
 * File: rung_submodule.h
 * Author: Subhendu Mishra
 * Description: Declaration of the RungSubmodule class for representing a submodule in a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_SUBMODULE_H
#define RUNG_SUBMODULE_H

#include <memory>
#include <unordered_map>
#include <vector>
#include "rung_element.h"

class RungSubmodule {
private:
    std::vector<std::shared_ptr<RungElement>> elements; // Vector to store elements of the submodule

public:
    // Add an element to the submodule.
    void addElement(std::shared_ptr<RungElement> element);

    // Evaluate the submodule based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states);

    // Get the elements of the submodule.
    std::vector<std::shared_ptr<RungElement>>& getElements();
};

#endif // RUNG_SUBMODULE_H
