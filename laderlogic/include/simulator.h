/*
 * File: simulator.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Simulator class for simulating ladder logic programs.
 * License: GPL (General Public License)
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <unordered_map>
#include <vector>
#include <memory>
#include "rung.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"

class Simulator {
private:
    std::unordered_map<std::string, bool> input_states;
    std::unordered_map<std::string, bool> output_states;
    std::vector<Rung> ladder_logic;

public:
    void setInput(const std::string& name, bool state);
    bool getOutput(const std::string& name);
    void addRung(const Rung& rung);
    void simulate();
    std::unordered_map<std::string, bool> getOutputStates() const;
};

#endif // SIMULATOR_H
