#include "lib/load_flow.h"
#include "lib/matrix_utils.h"
#include "lib/jacobian.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

LoadFlow::LoadFlow() 
    : convergenceTolerance(1e-6), maxIterations(30) {}

void LoadFlow::setConvergenceCriteria(double tolerance) {
    convergenceTolerance = tolerance;
}

void LoadFlow::setMaxIterations(int maxIterations) {
    this->maxIterations = maxIterations;
}

std::vector<double> LoadFlow::getVoltageMagnitudes() const {
    return voltageMagnitudes;
}

std::vector<double> LoadFlow::getVoltageAngles() const {
    return voltageAngles;
}

void LoadFlow::perform(PowerSystem& powerSystem) {
    initialize(powerSystem);

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        iterate(powerSystem);

        if (checkConvergence()) {
            std::cout << "Load flow converged after " << iteration + 1 << " iterations.\n";
            return;
        }
    }

    std::cerr << "Load flow did not converge within the maximum number of iterations.\n";
}

void LoadFlow::initialize(PowerSystem& powerSystem) {
    // Initialize voltage magnitudes and angles from power system data
    int numBuses = powerSystem.getBuses().size();
    voltageMagnitudes.resize(numBuses, 1.0); // Assuming initial guess of 1.0 p.u. for voltage magnitudes
    voltageAngles.resize(numBuses, 0.0); // Assuming initial guess of 0.0 for voltage angles
}

void LoadFlow::iterate(PowerSystem& powerSystem) {
    // Calculate admittance matrix and Jacobian
    auto Y = setupAdmittanceMatrix(powerSystem);
    Jacobian J = calculateJacobian(powerSystem);

    // Compute power mismatches
    std::vector<double> mismatches = computePowerMismatch(powerSystem);

    // Solve for voltage updates
    std::vector<double> delta = MatrixUtils::multiply(MatrixUtils::invert(J.H), mismatches);

    // Update voltages
    updateVoltages(delta);
}

bool LoadFlow::checkConvergence() const {
    // Check convergence based on the maximum mismatch value
    double maxMismatch = 0.0;
    for (double mismatch : computePowerMismatch(*powerSystem)) {
        maxMismatch = std::max(maxMismatch, std::abs(mismatch));
    }
    return maxMismatch < convergenceTolerance;
}

std::vector<std::vector<double>> LoadFlow::setupAdmittanceMatrix(const PowerSystem& powerSystem) {
    int numBuses = powerSystem.getBuses().size();
    std::vector<std::vector<double>> Y(numBuses, std::vector<double>(numBuses, 0.0));

    // Populate the admittance matrix based on the system's buses and lines
    // ...

    return Y;
}

std::vector<double> LoadFlow::computePowerMismatch(const PowerSystem& powerSystem) {
    int numBuses = powerSystem.getBuses().size();
    std::vector<double> mismatch(numBuses, 0.0);

    // Compute power mismatch for each bus based on current voltage estimates
    // ...

    return mismatch;
}

void LoadFlow::updateVoltages(const std::vector<double>& delta) {
    // Update bus voltage magnitudes and angles based on the computed delta values
    // ...
}
