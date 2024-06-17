#include "jacobian.h"
#include <cmath>

Jacobian calculateJacobian(const std::vector<Bus>& buses, const std::vector<Line>& lines) {
    size_t n = buses.size();
    Jacobian J;
    J.J11.resize(n, std::vector<double>(n, 0.0));
    J.J12.resize(n, std::vector<double>(n, 0.0));
    J.J21.resize(n, std::vector<double>(n, 0.0));
    J.J22.resize(n, std::vector<double>(n, 0.0));

    // Populate the Jacobian matrix
    for (const auto& line : lines) {
        int from = line.fromBus;
        int to = line.toBus;
        double Vfrom = buses[from].voltageMagnitude;
        double Vto = buses[to].voltageMagnitude;
        double thetaFrom = buses[from].voltageAngle * M_PI / 180.0;
        double thetaTo = buses[to].voltageAngle * M_PI / 180.0;
        double X = line.impedance;

        double dP_dThetaFrom = (Vfrom * Vto / X) * cos(thetaFrom - thetaTo);
        double dP_dThetaTo = -dP_dThetaFrom;
        double dQ_dThetaFrom = -(Vfrom * Vto / X) * sin(thetaFrom - thetaTo);
        double dQ_dThetaTo = -dQ_dThetaFrom;

        J.J11[from][from] += dP_dThetaFrom;
        J.J11[from][to] += dP_dThetaTo;
        J.J11[to][from] += dP_dThetaTo;
        J.J11[to][to] += dP_dThetaFrom;

        J.J21[from][from] += dQ_dThetaFrom;
        J.J21[from][to] += dQ_dThetaTo;
        J.J21[to][from] += dQ_dThetaTo;
        J.J21[to][to] += dQ_dThetaFrom;
    }

    return J;
}
