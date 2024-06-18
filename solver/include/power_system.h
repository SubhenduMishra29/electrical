#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include <string>
#include "bus.h"
#include "transformer.h"

class PowerSystem {
private:
    std::vector<Bus*> buses;
    std::vector<Transformer*> transformers;

public:
    PowerSystem();
    void loadSLD(const std::string& filename); // Method to load SLD from file
    void runSimulation();
    // Add methods as needed for system management
};

#endif // POWER_SYSTEM_H
