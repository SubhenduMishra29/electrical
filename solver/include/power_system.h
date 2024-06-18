// power_system.h

#ifndef POWER_SYSTEM_H
#define POWER_SYSTEM_H

#include <vector>
#include "bus.h"  // Include bus header

class PowerSystem {
private:
    std::vector<Bus*> buses;

public:
    PowerSystem();
    void addBus(Bus* bus);
    void runSimulation();
};

#endif // POWER_SYSTEM_H
