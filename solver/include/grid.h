#ifndef GRID_H
#define GRID_H
#include "PowerSystemError.h"
class Grid {
private:
    double voltage;  // Voltage of the external grid source
    double availablePower; // Total available power from the grid source

public:
    Grid(double voltage, double availablePower);
    double getVoltage() const;
    void setVoltage(double voltage);
    double getAvailablePower() const;
    void setAvailablePower(double availablePower);
};

#endif // GRID_H
