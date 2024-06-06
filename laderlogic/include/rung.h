/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of Rung class for representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_H
#define RUNG_H

#include <vector>
#include <memory>
#include "rung_element.h"

class Rung {
private:
    std::vector<std::shared_ptr<RungElement>> positiveRail; // Positive rail of the rung
    std::vector<std::shared_ptr<RungElement>> negativeRail; // Negative rail of the rung

public:
    /*
     * Add an element to the rung, adding it to the positive rail
     * @param element: The element to add to the rung
     */
    void addElement(std::shared_ptr<RungElement> element);

    /*
     * Evaluate the rung based on the current states of inputs
     * @param states: The states of inputs to evaluate against
     * @return: The evaluation result of the rung
     */
    bool evaluate(std::unordered_map<std::string, bool>& states);
};

#endif // RUNG_H
