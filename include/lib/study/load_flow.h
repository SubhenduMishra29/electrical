/**
 * @file load_flow.h
 * @brief Header file for the LoadFlow class, which performs load flow analysis using the Newton-Raphson method.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef LOAD_FLOW_H
#define LOAD_FLOW_H

#include <vector>
#include "power_system.h"
class PowerSystem;
/**
 * @class LoadFlow
 * @brief Class to perform load flow analysis using the Newton-Raphson method.
 * 
 * This class provides methods to set up power system matrices, compute the Jacobian matrix,
 * and perform iterative calculations to solve the load flow problem.
 */
class LoadFlow {
public:
    /**
     * @brief Default constructor for LoadFlow.
     */
    LoadFlow();

    /**
     * @brief Perform the load flow analysis.
     * 
     * This method sets up power system matrices, performs Newton-Raphson iterations, and
     * updates bus voltages until convergence is achieved.
     * 
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void perform(PowerSystem& powerSystem);

    /**
     * @brief Set the convergence criteria for the analysis.
     * 
     * @param tolerance The maximum allowable mismatch for convergence.
     */
    void setConvergenceCriteria(double tolerance);

    /**
     * @brief Set the maximum number of iterations for the analysis.
     * 
     * @param maxIterations The maximum number of iterations to perform.
     */
    void setMaxIterations(int maxIterations);

    /**
     * @brief Retrieve the voltage magnitudes after analysis.
     * 
     * @return A vector of voltage magnitudes for each bus.
     */
    std::vector<double> getVoltageMagnitudes() const;

    /**
     * @brief Retrieve the voltage angles after analysis.
     * 
     * @return A vector of voltage angles for each bus.
     */
    std::vector<double> getVoltageAngles() const;

private:
    /**
     * @brief Convergence criteria for the analysis.
     */
    double convergenceTolerance;

    /**
     * @brief Maximum number of iterations for the analysis.
     */
    int maxIterations;

    /**
     * @brief Voltage magnitudes after analysis.
     */
    std::vector<double> voltageMagnitudes;

    /**
     * @brief Voltage angles after analysis.
     */
    std::vector<double> voltageAngles;

    /**
     * @brief Initialize the power system for analysis.
     * 
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void initialize(PowerSystem& powerSystem);

    /**
     * @brief Perform a single iteration of the load flow analysis.
     * 
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void iterate(PowerSystem& powerSystem);

    /**
     * @brief Check if the load flow solution has converged.
     * 
     * @return True if the solution has converged, otherwise false.
     */
    bool checkConvergence() const;

    /**
     * @brief Setup the admittance matrix for the system.
     * 
     * @param powerSystem The PowerSystem object representing the power system state.
     * @return The admittance matrix.
     */
    std::vector<std::vector<double>> setupAdmittanceMatrix(const PowerSystem& powerSystem);

    /**
     * @brief Compute power mismatches based on current voltage estimates.
     * 
     * @param powerSystem The PowerSystem object representing the power system state.
     * @return A vector of power mismatches.
     */
    std::vector<double> computePowerMismatch(const PowerSystem& powerSystem);

    /**
     * @brief Update bus voltages based on the computed delta values.
     * 
     * @param delta The vector of voltage updates.
     */
    void updateVoltages(const std::vector<double>& delta);
};

#endif // LOAD_FLOW_H
