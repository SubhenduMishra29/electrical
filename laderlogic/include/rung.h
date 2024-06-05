/*
 * File: rung.h
 * Author: Subhendu Mishra
 * Description: Declaration of Rung class for representing a ladder logic rung with branching support.
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
    std::vector<std::vector<std::shared_ptr<RungElement>>> branches; // Nested vector to represent branches

public:
    // Add an element to the main branch of the rung.
    void addElement(std::shared_ptr<RungElement> element);

    // Add a branch starting from the current state.
    void addBranch(const std::vector<std::shared_ptr<RungElement>>& branch);

    // Evaluate the rung based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states);

    // Get the elements of the rung.
    std::vector<std::vector<std::shared_ptr<RungElement>>>& getBranches();
};

#endif /* RUNG_H */

#endif /* RUNG_H */


#endif /* RUNG_H */
