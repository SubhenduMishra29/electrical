/*
 * File: ladder.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Ladder class representing the entire ladder logic.
 * License: GPL (General Public License)
 */

#include "ladder.h"

// Add a rung to the ladder
void Ladder::addRung(std::shared_ptr<Rung> rung) {
    rungs.push_back(rung);
}

// Evaluate the entire ladder logic
void Ladder::evaluate(std::unordered_map<std::string, bool>& states) {
    for (const auto& rung : rungs) {
        rung->evaluate(states);
    }
}

