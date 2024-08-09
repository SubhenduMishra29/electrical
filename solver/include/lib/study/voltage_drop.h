// voltage_drop.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef VOLTAGE_DROP_H
#define VOLTAGE_DROP_H

class PowerSystem;  // Forward declaration

class VoltageDrop {
public:
    VoltageDrop(); // Constructor

    void calculate(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // VOLTAGE_DROP_H
