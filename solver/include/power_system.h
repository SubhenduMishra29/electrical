#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include "bus.h"

class PowerSystem {
private:
    std::vector<Bus*> buses;
    std::vector<Transformer*> transformers; // Vector to hold system transformers

public:
    PowerSystem();
    void addBus(Bus* bus);
    void addTransformer(Transformer* transformer); // Method to add transformer to system
    void runSimulation();
};

#endif // POWER_SYSTEM_H
