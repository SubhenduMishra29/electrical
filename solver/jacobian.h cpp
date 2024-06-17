#ifndef JACOBIAN_H
#define JACOBIAN_H

#include <vector>
#include "bus.h"
#include "line.h"

struct Jacobian {
    std::vector<std::vector<double>> J11;
    std::vector<std::vector<double>> J12;
    std::vector<std::vector<double>> J21;
    std::vector<std::vector<double>> J22;
};

Jacobian calculateJacobian(const std::vector<Bus>& buses, const std::vector<Line>& lines);

#endif // JACOBIAN_H
