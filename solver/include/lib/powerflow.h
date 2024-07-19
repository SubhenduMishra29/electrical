// powerflow.h

#ifndef POWERFLOW_H
#define POWERFLOW_H

#include "power_system.h"
#include "lib/PowerSystemError.h"
class PowerSystem;
class PowerFlow {
public:
    PowerFlow(); // Constructor, if needed

    void performLoadFlow(PowerSystem& powerSystem);
    void calculateVoltageDrop(PowerSystem& powerSystem);
    void performShortCircuitAnalysis(PowerSystem& powerSystem);
    void performDCShortCircuitAnalysis(PowerSystem& powerSystem);
    void performDCLoadFlow(PowerSystem& powerSystem);

private:
    // Optional private members or methods
};

#endif // POWERFLOW_H
