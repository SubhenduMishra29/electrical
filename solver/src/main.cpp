// main.cpp
#include <iostream>
#include <vector>
#include "bus.h"
#include "line.h"
#include "powerflow.h"

int main() {
    std::vector<Bus> buses = {
        {0, "Bus 1", 1.0, 0.0, true, {1, 2}, {{1.0, 1.0, 0.5, 0.2}, {0.8, 0.8, 0.3, 0.1}}}, // Slack bus with generators
        {1, "Bus 2", 1.0, 0.0, false, {0}, {{0.6, 0.6, 0.3, 0.1}}},                         // Bus 2 with generator
        {2, "Bus 3", 1.0, 0.0, false, {0}, {{0.8, 0.8, 0.4, 0.2}}}                          // Bus 3 with generator
    };

    std::vector<Line> lines = {
        {0, 0, 1, 0.1}, // Line from bus 1 to bus 2 with some impedance
        {1, 0, 2, 0.1}  // Line from bus 1 to bus 3 with some impedance
    };

    solvePowerFlow(buses, lines);

    return 0;
}
