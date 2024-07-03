/**
 * @file powerflow.h
 * @brief Declarations for power flow analysis functions.
 * 
 * This file declares functions related to power flow analysis in an electrical power system.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef POWERFLOW_H
#define POWERFLOW_H

#include <vector>
#include "bus.h"
#include "line.h"
#include "jacobian.h"
#include "PowerSystemError.h"

/**
 * @struct Mismatch
 * @brief Struct to represent active and reactive power mismatches.
 */
struct Mismatch {
    double P; ///< Active power mismatch
    double Q; ///< Reactive power mismatch
};

/**
 * @brief Calculate power mismatches in the electrical power system.
 * 
 * This function calculates the active and reactive power mismatches
 * based on the state of buses and lines in the power system.
 * 
 * @param buses Vector of Bus objects representing buses in the power system.
 * @param lines Vector of Line objects representing transmission lines in the power system.
 * @return Vector of Mismatch structs representing active and reactive power mismatches at each bus.
 */
std::vector<Mismatch> calculateMismatches(const std::vector<Bus>& buses, const std::vector<Line>& lines);

/**
 * @brief Solve power flow in the electrical power system.
 * 
 * This function attempts to solve the power flow in the power system represented
 * by the provided vectors of buses and lines. It modifies the state of buses to
 * converge to a solution.
 * 
 * @param buses Vector of Bus objects representing buses in the power system.
 * @param lines Vector of Line objects representing transmission lines in the power system.
 * 
 * @throws LoadFlowError if the power flow does not converge within specified iterations.
 */
void solvePowerFlow(std::vector<Bus>& buses, const std::vector<Line>& lines);

#endif // POWERFLOW_H
