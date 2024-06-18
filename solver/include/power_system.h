#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include <string>
#include "bus.h"
#include "transformer.h"
#include "grid.h"

class PowerSystem {
private:
    std::vector<Bus*> buses;
    std::vector<Transformer*> transformers;
    Grid* grid;

public:
    PowerSystem();
    ~PowerSystem(); // Destructor for cleanup
    void loadSLD(const std::string& filename); // Method to load SLD from file
    void runSimulation();
};

#endif // POWER_SYSTEM_H
