#include <iostream>
#include <vector>
#include "bus.h"
#include "line.h"
#include "powerflow.h"

int main() {
    // Define buses and lines
    std::vector<Bus> buses = {
        { 1.0, 0.0, 0.0, 0.0, true },   // Slack bus
        { 1.0, 0.0, 0.8, 0.4, false },  // Bus 2
        { 1.0, 0.0, 0.6, 0.3, false },  // Bus 3
        { 1.05, -5.0, 0.0, 0.0, false } // Bus 4
    };

    std::vector<Line> lines = {
        { 0, 1, 0.0 },  // Line from bus 1 to bus 2 with zero impedance (ideal case)
        { 0, 2, 0.0 },  // Line from bus 1 to bus 3 with zero impedance (ideal case)
        { 0, 3, 0.0 }   // Line from bus 1 to bus 4 with zero impedance (ideal case)
    };

    // Solve power flow
    solvePowerFlow(buses, lines);

    return 0;
}
