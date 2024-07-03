/**
 * @file jacobian.h
 * @brief Declaration for the Jacobian matrix calculation function.
 * 
 * This file declares the function for calculating the Jacobian matrix,
 * which is used in power flow analysis of an electrical power system.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef JACOBIAN_H
#define JACOBIAN_H

#include <vector>
#include "bus.h"
#include "line.h"
#include "PowerSystemError.h"

/**
 * @struct Jacobian
 * @brief Struct to represent the Jacobian matrix in power flow analysis.
 */
struct Jacobian {
    std::vector<std::vector<double>> H; ///< dP/dTheta
    std::vector<std::vector<double>> N; ///< dP/dV
    std::vector<std::vector<double>> J; ///< dQ/dTheta
    std::vector<std::vector<double>> L; ///< dQ/dV
};

/**
 * @brief Calculate the Jacobian matrix for power flow analysis.
 * 
 * This function calculates the Jacobian matrix based on the state of
 * buses and lines in the power system.
 * 
 * @param buses Vector of Bus objects representing buses in the power system.
 * @param lines Vector of Line objects representing transmission lines in the power system.
 * @return Jacobian matrix containing partial derivatives of power equations.
 */
Jacobian calculateJacobian(const std::vector<Bus>& buses, const std::vector<Line>& lines);

#endif // JACOBIAN_H
