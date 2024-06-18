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
    
    // New methods for power system analysis
    void performLoadFlow(); // Method to perform Load Flow analysis
    void calculateVoltageDrop(); // Method to calculate Voltage Drop
    void performShortCircuitAnalysis(); // Method to perform Short Circuit analysis
    void performDCShortCircuitAnalysis(); // Method to perform DC Short Circuit analysis
    void performDCLoadFlow(); // Method to perform DC Load Flow analysis
};

#endif // POWER_SYSTEM_H
