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
