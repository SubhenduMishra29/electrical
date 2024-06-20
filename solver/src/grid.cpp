#include "Grid.h"

// Constructor
Grid::Grid(double voltage, double availablePower, double frequency, int numberOfPhases,
           double voltageRegulation, double powerFactor,
           double harmonicDistortion, double transientResponse)
    : voltage(voltage), availablePower(availablePower), frequency(frequency),
      numberOfPhases(numberOfPhases), voltageRegulation(voltageRegulation),
      powerFactor(powerFactor), harmonicDistortion(harmonicDistortion),
      transientResponse(transientResponse) {
    // Initialize all attributes
}

// Getter methods
double Grid::getVoltage() const {
    return voltage;
}

double Grid::getAvailablePower() const {
    return availablePower;
}

double Grid::getFrequency() const {
    return frequency;
}

int Grid::getNumberOfPhases() const {
    return numberOfPhases;
}

double Grid::getVoltageRegulation() const {
    return voltageRegulation;
}

double Grid::getPowerFactor() const {
    return powerFactor;
}

double Grid::getHarmonicDistortion() const {
    return harmonicDistortion;
}

double Grid::getTransientResponse() const {
    return transientResponse;
}

// Setter methods
void Grid::setVoltage(double voltage) {
    this->voltage = voltage;
}

void Grid::setAvailablePower(double availablePower) {
    this->availablePower = availablePower;
}

// Placeholder methods for simulation
void Grid::simulateFault() {
    // Placeholder: Simulate a fault in the grid
    // Example: reduce available power or induce voltage drop
    availablePower *= 0.9;  // Simulate 10% reduction in available power
}

void Grid::handleProtection() {
    // Placeholder: Handle protection mechanisms in response to a fault
    // Example: trip circuit breakers, isolate faulty section
    // This method can be expanded based on specific protection logic
}
#include "grid.h"

Grid::Grid(double voltage, double availablePower)
    : voltage(voltage), availablePower(availablePower) {}

double Grid::getVoltage() const {
    return voltage;
}

void Grid::setVoltage(double voltage) {
    this->voltage = voltage;
}

double Grid::getAvailablePower() const {
    return availablePower;
}

void Grid::setAvailablePower(double availablePower) {
    this->availablePower = availablePower;
}
