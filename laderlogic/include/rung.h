/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Rung class for representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_H
#define RUNG_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "rung_element.h"
#include "rung_submodule.h"

class Rung {
private:
    std::vector<std::shared_ptr<RungElement>> elements;             // Vector to store elements directly in the rung
    std::vector<std::shared_ptr<RungSubmodule>> submodules;         // Vector to store submodules

public:
    void addElement(std::shared_ptr<RungElement> element);          // Add an element directly to the rung
    void addSubmodule(std::shared_ptr<RungSubmodule> submodule);    // Add a submodule to the rung
    bool evaluate(std::unordered_map<std::string, bool>& states);   // Evaluate the rung based on the current states

    // Additional methods for rung operations can be added here
};

#endif // RUNG_H
