#include "powerflow.h"
#include "jacobian.h"
#include <iostream>
#include <cmath>
#include <vector>

// Struct to store power mismatches (P and Q)
struct Mismatch {
    double P;
    double Q;
};

// Function to calculate power mismatches
std::vector<Mismatch> calculateMismatches(const std::vector<Bus>& buses, const std::vector<Line>& lines) {
    std::vector<Mismatch> mismatches(buses.size());

    // Calculate power mismatches due to power flow in lines
    for (const auto& line : lines) {
        int from = line.fromBus;
        int to = line.toBus;

        // Calculate power flow based on current bus voltages
        double Vfrom = buses[from].getVoltageMagnitude();
        double Vto = buses[to].getVoltageMagnitude();
        double thetaFrom = buses[from].getVoltageAngle() * M_PI / 180.0;
        double thetaTo = buses[to].getVoltageAngle() * M_PI / 180.0;
        
        // For simplicity, assume line impedance is purely reactive (X only)
        double X = line.impedance;

        double PfromTo = (Vfrom * Vto / X) * sin(thetaFrom - thetaTo);
        double QfromTo = (Vfrom * Vto / X) * cos(thetaFrom - thetaTo);

        mismatches[from].P -= PfromTo;
        mismatches[to].P += PfromTo;
        mismatches[from].Q -= QfromTo;
        mismatches[to].Q += QfromTo;
    }

    // Calculate power mismatches due to generation and load at buses
    for (size_t i = 0; i < buses.size(); ++i) {
        double totalGenP = 0.0;
        double totalGenQ = 0.0;
        for (const auto& gen : buses[i].getGenerators()) {
            totalGenP += gen.activePower;
            totalGenQ += gen.reactivePower;
        }

        double totalLoadP = 0.0;
        double totalLoadQ = 0.0;
        for (const auto& load : buses[i].getLoads()) {
            totalLoadP += load.activePowerDemand;
            totalLoadQ += load.reactivePowerDemand;
        }

        mismatches[i].P += (totalGenP - totalLoadP);
        mismatches[i].Q += (totalGenQ - totalLoadQ);
    }

    return mismatches;
}

// Function to solve power flow using Newton-Raphson method
void solvePowerFlow(std::vector<Bus>& buses, const std::vector<Line>& lines) {
    const double tolerance = 1e-6;
    const int maxIterations = 50;
    int iteration = 0;
    bool converged = false;

    while (!converged && iteration < maxIterations) {
        // Calculate power mismatches
        std::vector<Mismatch> mismatches = calculateMismatches(buses, lines);

        // Calculate Jacobian matrix
        Jacobian J = calculateJacobian(buses, lines);

        // Solve the linear system J * delta = -mismatches
        // Placeholder: Implement a linear solver (e.g., Gaussian elimination) to solve for delta

        // Update bus voltages using Newton-Raphson iteration formula
        for (size_t i = 0; i < buses.size(); ++i) {
            if (!buses[i].isSlack) {
                // Update voltage magnitude and angle based on calculated delta
                double deltaVMagnitude = 0.0; // Placeholder for deltaV calculation
                double deltaVAngle = 0.0;    // Placeholder for deltaTheta calculation

                buses[i].setVoltageMagnitude(buses[i].getVoltageMagnitude() + deltaVMagnitude);
                buses[i].setVoltageAngle(buses[i].getVoltageAngle() + deltaVAngle);
            }
        }

        // Check for convergence
        double maxMismatch = 0.0;
        for (const auto& mismatch : mismatches) {
            double mismatchMagnitude = std::sqrt(mismatch.P * mismatch.P + mismatch.Q * mismatch.Q);
            if (mismatchMagnitude > maxMismatch) {
                maxMismatch = mismatchMagnitude;
            }
        }

        if (maxMismatch < tolerance) {
            converged = true;
        }

        iteration++;
    }

    // Output results
    if (converged) {
        std::cout << "Power flow converged after " << iteration << " iterations.\n";
        for (const auto& bus : buses) {
            std::cout << "Bus " << bus.getId() << ": V = " << bus.getVoltageMagnitude() << ", Theta = " << bus.getVoltageAngle() << "\n";
        }
    } else {
        std::cout << "Power flow did not converge within " << maxIterations << " iterations.\n";
    }
}
