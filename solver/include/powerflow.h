#ifndef POWERFLOW_H
#define POWERFLOW_H

#include <vector>
#include "bus.h"
#include "line.h"
#include "jacobian.h"

// Function to calculate power mismatches
std::vector<Mismatch> calculateMismatches(const std::vector<Bus>& buses, const std::vector<Line>& lines);

// Function to solve power flow
void solvePowerFlow(std::vector<Bus>& buses, const std::vector<Line>& lines);

#endif // POWERFLOW_H

