/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of Rung class for representing a ladder logic rung.
 * License: GPL (General Public License)
 */
// rung.h
#ifndef RUNG_H
#define RUNG_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "rung_element.h"
#include "wire.h" // Include Wire class

class Rung {
private:
    std::vector<std::vector<std::shared_ptr<RungElement>>> rails; // Vector of rails
    std::vector<std::shared_ptr<Wire>> wires; // Vector to store wires

public:
    void addRail(); // Add a new rail
    void addElementToRail(std::shared_ptr<RungElement> element, size_t railIndex); // Add an element to a specific rail
    void connectElements(std::shared_ptr<RungElement> startElement, std::shared_ptr<RungElement> endElement); // Connect two rung elements with a wire
    bool evaluate(std::unordered_map<std::string, bool>& states);
    bool checkContinuity();
};

#endif // RUNG_H
