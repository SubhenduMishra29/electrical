// voltage_imbalance.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef VOLTAGE_IMBALANCE_H
#define VOLTAGE_IMBALANCE_H

class PowerSystem;  // Forward declaration

class VoltageImbalance {
public:
    VoltageImbalance(); // Constructor

    void perform(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // VOLTAGE_IMBALANCE_H
