#ifndef JACOBIAN_H
#define JACOBIAN_H

#include <vector>
#include "bus.h"
#include "line.h"

struct Jacobian {
    std::vector<std::vector<double>> H; // dP/dTheta
    std::vector<std::vector<double>> N; // dP/dV
    std::vector<std::vector<double>> J; // dQ/dTheta
    std::vector<std::vector<double>> L; // dQ/dV
};

// Function to calculate the Jacobian matrix
Jacobian calculateJacobian(const std::vector<Bus>& buses, const std::vector<Line>& lines);

#endif // JACOBIAN_H
