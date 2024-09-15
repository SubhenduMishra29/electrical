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
#include "power_system.h" // Include PowerSystem header for type definition


// Forward declaration of PowerSystem class
class PowerSystem;

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
 * @param powerSystem The PowerSystem object representing the power system state.
 * @return Jacobian matrix containing partial derivatives of power equations.
 */
Jacobian calculateJacobian(const PowerSystem& powerSystem);

#endif // JACOBIAN_H
