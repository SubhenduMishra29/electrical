/*
 * File: ladder.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Ladder class for representing the entire ladder logic.
 * License: GPL (General Public License)
 */

#ifndef LADDER_H
#define LADDER_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "rung.h"

// Class representing the entire ladder logic
class Ladder {
private:
    std::vector<std::shared_ptr<Rung>> rungs; // Vector of rungs in the ladder

public:
    // Add a rung to the ladder
    void addRung(std::shared_ptr<Rung> rung);

    // Evaluate the entire ladder logic
    void evaluate(std::unordered_map<std::string, bool>& states);

    // Get all rungs in the ladder
    std::vector<std::shared_ptr<Rung>> getRungs() const { return rungs; }
};

#endif // LADDER_H

