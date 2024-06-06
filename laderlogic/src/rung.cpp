/*
 * File: rung.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Rung class representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#include "rung.h"
#include "rung_submodule.h"


void Rung::addRail() {
    rails.emplace_back();
}

void Rung::addElementToRail(std::shared_ptr<RungElement> element, size_t railIndex) {
    if (railIndex < rails.size()) {
        rails[railIndex].push_back(element);
    }
}

bool Rung::evaluate(std::unordered_map<std::string, bool>& states) {
    // Your existing evaluation logic here
}

bool Rung::checkContinuity() {
    // Check continuity in each rail
    for (const auto& rail : rails) {
        // Check continuity within the rail
        for (size_t i = 0; i < rail.size() - 1; ++i) {
            if (!rail[i]->isConnectedTo(rail[i + 1])) {
                // Discontinuity found
                return false;
            }
        }

        // Check if the rail terminates correctly
        if (!rail.empty() && rail.back()->isTerminatingElement()) {
            // Rail terminates correctly
        } else {
            // Rail does not terminate correctly
            return false;
        }
    }

    // Continuity maintained in all rails and all rails terminate correctly
    return true;
}
