#include "lib/voltage.h"

Voltage::Voltage(std::complex<double> voltage, double activePower, double reactivePower)
    : voltage(voltage), activePower(activePower), reactivePower(reactivePower) {}

std::complex<double> Voltage::getVoltage() const {
    return voltage;
}

void Voltage::setVoltage(std::complex<double> voltage) {
    this->voltage = voltage;
}

double Voltage::getActivePower() const {
    return activePower;
}

void Voltage::setActivePower(double activePower) {
    this->activePower = activePower;
}

double Voltage::getReactivePower() const {
    return reactivePower;
}

void Voltage::setReactivePower(double reactivePower) {
    this->reactivePower = reactivePower;
}
