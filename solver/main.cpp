// main.cpp
#include <iostream>
#include <vector>
#include "bus.h"
#include "line.h"
#include "powerflow.h"

int main() {
    // Define buses and lines for a sample power system
    std::vector<Bus> buses = {
        { 0, "Bus 1", 1.0, 0.0, 0.0, 0.0, true, {1, 2} },     // Slack bus
        { 1, "Bus 2", 1.0, 0.0, 0.8, 0.4, false, {0} },       // Bus 2
        { 2, "Bus 3", 1.0, 0.0, 0.6, 0.3, false, {0} },       // Bus 3
        { 3, "Bus 4", 1.05, -5.0, 0.0, 0.0, false, {0} }      // Bus 4
        // Add more buses as needed
    };

    std::vector<Line> lines = {
        { 0, 0, 1, 0.0 },   // Line from bus 1 to bus 2 with zero impedance (ideal case)
        { 1, 0, 2, 0.0 },   // Line from bus 1 to bus 3 with zero impedance (ideal case)
        { 2, 0, 3, 0.0 }    // Line from bus 1 to bus 4 with zero impedance (ideal case)
        // Add more lines as needed
    };

    // Solve power flow
    solvePowerFlow(buses, lines);

    return 0;
}
