/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of Rung class for representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_H
#define RUNG_H

#include <memory>
#include <unordered_map>
#include <vector>
#include "rung_element.h"

class Rung {
private:
    std::vector<std::shared_ptr<RungElement>> elements;

public:
    // Add an element to the rung.
    void addElement(std::shared_ptr<RungElement> element);

    // Evaluate the rung based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states);

    // Get the elements of the rung.
    std::vector<std::shared_ptr<RungElement>>& getElements();
};

#endif /* RUNG_H */
