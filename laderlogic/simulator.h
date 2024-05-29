#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <unordered_map>
#include <vector>
#include "rung.h"

class Simulator {
private:
    std::unordered_map<std::string, bool> input_states;
    std::unordered_map<std::string, bool> output_states;
    std::vector<Rung> ladder_logic;

public:
    Simulator();
    void setInput(std::string name, bool state);
    bool getOutput(std::string name);
    void addRung(Rung rung);
    void simulate();
};

#endif // SIMULATOR_H