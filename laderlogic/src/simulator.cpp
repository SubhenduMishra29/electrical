/*
 * File: simulator.h
 * Author: Subhendu Mishra
 * Description: Declaration of Simulator class for simulating ladder logic programs.
 * License: GPL (General Public License)
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <unordered_map>
#include <vector>
#include "rung.h"

class Simulator {
private:
    std::unordered_map<std::string, bool> input_states;   // Map to store input states
    std::unordered_map<std::string, bool> output_states;  // Map to store output states
    std::vector<Rung> ladder_logic;                       // Vector to store ladder logic rungs

public:
    // Set the state of an input.
    void setInput(const std::string& name, bool state);

    // Get the state of an output.
    bool getOutput(const std::string& name);

    // Add a rung to the ladder logic.
    void addRung(Rung rung);

    // Simulate the ladder logic program.
    void simulate();

    // Get the output states.
    std::unordered_map<std::string, bool> getOutputStates() const;
};

#endif // SIMULATOR_H
