/*
 * File: simulator.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Simulator class for simulating ladder logic programs.
 * License: GPL (General Public License)
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <unordered_map>
#include <memory>
#include "ladder.h"

// Class for simulating ladder logic programs
class Simulator {
private:
    std::unordered_map<std::string, bool> input_states; // Input states map
    std::unordered_map<std::string, bool> output_states; // Output states map
    std::shared_ptr<Ladder> ladder_logic; // Ladder logic object

public:
    // Constructor initializes the simulator with a ladder logic file
    Simulator(const std::string& filename);

    // Set an input state
    void setInput(const std::string& name, bool state);

    // Get an output state
    bool getOutput(const std::string& name);

    // Run the simulation
    void simulate();

    // Get the output states map
    std::unordered_map<std::string, bool> getOutputStates() const;
};

#endif // SIMULATOR_H
