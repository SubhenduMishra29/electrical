#ifndef POWERFLOW_H
#define POWERFLOW_H

#include <vector>
#include "bus.h"
#include "line.h"

void solvePowerFlow(std::vector<Bus>& buses, const std::vector<Line>& lines);

#endif // POWERFLOW_H
