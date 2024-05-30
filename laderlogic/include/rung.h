/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of Rung class representing a rung in a ladder logic program.
 * License: GPL (General Public License)
 */

#ifndef RUNG_H
#define RUNG_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "rung_element.h"

class Rung {
private:
    std::vector<std::shared_ptr<RungElement>> elements; // Vector to store elements of the rung

public:
    // Add an element to the rung.
    void addElement(std::shared_ptr<RungElement> element);

    // Evaluate the rung based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states);

    // Get the elements of the rung.
    std::vector<std::shared_ptr<RungElement>>& getElements();
};

#endif // RUNG_H

