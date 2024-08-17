#include "lib/grid.h"


// Constructor
Grid::Grid(double voltage, double availablePower, double frequency, int numberOfPhases,
           double voltageRegulation, double powerFactor,
           double harmonicDistortion, double transientResponse)
    : voltage(voltage), availablePower(availablePower), frequency(frequency),
      numberOfPhases(numberOfPhases), voltageRegulation(voltageRegulation),
      powerFactor(powerFactor), harmonicDistortion(harmonicDistortion),
      transientResponse(transientResponse),
      threePhaseMVAsc(0.0), onePhaseMVAsc(0.0),
      xRRatioPositive(0.0), xRRatioZero(0.0),
      threePhaseSymmetricalKAsc(0.0), onePhaseSymmetricalKAsc(0.0) {
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

// Setters for voltage and available power (other attributes can have setters as needed)
void Grid::setVoltage(double voltage) {
    this->voltage = voltage;
}

void Grid::setAvailablePower(double availablePower) {
    this->availablePower = availablePower;
}

// Methods for short circuit and X/R ratios
void Grid::setThreePhaseMVAsc(double mvAsc) {
    this->threePhaseMVAsc = mvAsc;
}

void Grid::setOnePhaseMVAsc(double mvAsc) {
    this->onePhaseMVAsc = mvAsc;
}

void Grid::setXRRatioPositive(double xRRatio) {
    this->xRRatioPositive = xRRatio;
}

void Grid::setXRRatioZero(double xRRatio) {
    this->xRRatioZero = xRRatio;
}

void Grid::setThreePhaseSymmetricalKAsc(double kAsc) {
    this->threePhaseSymmetricalKAsc = kAsc;
}

void Grid::setOnePhaseSymmetricalKAsc(double kAsc) {
    this->onePhaseSymmetricalKAsc = kAsc;
}

double Grid::getThreePhaseMVAsc() const {
    return threePhaseMVAsc;
}

double Grid::getOnePhaseMVAsc() const {
    return onePhaseMVAsc;
}

double Grid::getXRRatioPositive() const {
    return xRRatioPositive;
}

double Grid::getXRRatioZero() const {
    return xRRatioZero;
}

double Grid::getThreePhaseSymmetricalKAsc() const {
    return threePhaseSymmetricalKAsc;
}

double Grid::getOnePhaseSymmetricalKAsc() const {
    return onePhaseSymmetricalKAsc;
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
