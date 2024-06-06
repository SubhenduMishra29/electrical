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

class Rung {
private:
    std::vector<std::vector<std::shared_ptr<RungElement>>> rails; // Vector of rails

public:
    void addRail(); // Add a new rail
    void addElementToRail(std::shared_ptr<RungElement> element, size_t railIndex); // Add an element to a specific rail
    bool evaluate(std::unordered_map<std::string, bool>& states);
    bool checkContinuity();
};

#endif // RUNG_H
