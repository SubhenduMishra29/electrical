#include "powerflow.h"
#include "jacobian.h"
#include <iostream>
#include <cmath>
#include <vector>

struct Mismatch {
    double P;
    double Q;
};

// Function to calculate power mismatches
std::vector<Mismatch> calculateMismatches(const std::vector<Bus>& buses, const std::vector<Line>& lines) {
    std::vector<Mismatch> mismatches(buses.size());

    for (const auto& line : lines) {
        int from = line.fromBus;
        int to = line.toBus;

        // Calculate power flow based on current bus voltages
        double Vfrom = buses[from].voltageMagnitude;
        double Vto = buses[to].voltageMagnitude;
        double thetaFrom = buses[from].voltageAngle * M_PI / 180.0;
        double thetaTo = buses[to].voltageAngle * M_PI / 180.0;
        
        // For simplicity, assume line impedance is purely reactive (X only)
        double X = line.impedance;

        double PfromTo = (Vfrom * Vto / X) * sin(thetaFrom - thetaTo);
        double QfromTo = (Vfrom * Vto / X) * cos(thetaFrom - thetaTo);

        mismatches[from].P -= PfromTo;
        mismatches[to].P += PfromTo;
        mismatches[from].Q -= QfromTo;
        mismatches[to].Q += QfromTo;
    }

    for (size_t i = 0; i < buses.size(); ++i) {
        double totalGenP = 0.0;
        double totalGenQ = 0.0;
        for (const auto& gen : buses[i].generators) {
            totalGenP += gen.activePower;
            totalGenQ += gen.reactivePower;
        }

        mismatches[i].P += totalGenP;
        mismatches[i].Q += totalGenQ;
    }

    return mismatches;
}

void solvePowerFlow(std::vector<Bus>& buses, const std::vector<Line>& lines) {
    const double tolerance = 1e-6;
    const int maxIterations = 50;
    int iteration = 0;
    bool converged = false;

    while (!converged && iteration < maxIterations) {
        std::vector<Mismatch> mismatches = calculateMismatches(buses, lines);
        Jacobian J = calculateJacobian(buses, lines);

        // Placeholder: Solve linear system J * delta = -mismatches
        // Implement this part using a linear solver (e.g., Gaussian elimination)

        // Update bus voltages using Newton-Raphson iteration formula
        for (size_t i = 0; i < buses.size(); ++i) {
            if (!buses[i].isSlack) {
                // Update voltage magnitude and angle based on calculated delta
                double deltaVMagnitude = 0.0; // Solve for deltaV based on mismatches and Jacobian
                double deltaVAngle = 0.0;    // Solve for deltaTheta based on mismatches and Jacobian
                buses[i].voltageMagnitude += deltaVMagnitude;
                buses[i].voltageAngle += deltaVAngle;
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

    if (converged) {
        std::cout << "Power flow converged after " << iteration << " iterations.\n";
        for (const auto& bus : buses) {
            std::cout << "Bus " << bus.id << ": V = " << bus.voltageMagnitude << ", Theta = " << bus.voltageAngle << "\n";
        }
    } else {
        std::cout << "Power flow did not converge within " << maxIterations << " iterations.\n";
    }
}
