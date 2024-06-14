// bus.h
#ifndef BUS_H
#define BUS_H

#include <vector>
#include <string>

struct Bus {
    int id;                      // Bus ID
    std::string name;            // Bus name or identifier
    double voltageMagnitude;     // Voltage magnitude in per unit (pu)
    double voltageAngle;         // Voltage angle in degrees
    double realPowerInjection;   // Real power injection in pu
    double reactivePowerInjection; // Reactive power injection in pu
    bool isSlack;                // Flag indicating if it's a slack bus
    std::vector<int> connectedBuses;  // List of connected buses (for adjacency representation)
};

#endif // BUS_H
