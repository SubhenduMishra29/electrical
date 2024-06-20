#ifndef GRID_H
#define GRID_H

#include "PowerSystemError.h"

class Grid {
private:
    double voltage;             // Voltage of the external grid source
    double availablePower;      // Total available power from the grid source
    double frequency;           // Frequency of the grid (e.g., 50 Hz or 60 Hz)
    int numberOfPhases;         // Number of phases in the grid (1 for single-phase, 3 for three-phase)
    double voltageRegulation;   // Percentage regulation of voltage
    double powerFactor;         // Power factor of the grid
    double harmonicDistortion;  // Harmonic distortion percentage
    double transientResponse;   // Response time to transients

public:
    Grid(double voltage, double availablePower, double frequency, int numberOfPhases,
         double voltageRegulation, double powerFactor,
         double harmonicDistortion, double transientResponse);

    // Getters for all attributes
    double getVoltage() const;
    double getAvailablePower() const;
    double getFrequency() const;
    int getNumberOfPhases() const;
    double getVoltageRegulation() const;
    double getPowerFactor() const;
    double getHarmonicDistortion() const;
    double getTransientResponse() const;

    // Setters for voltage and available power (other attributes can have setters as needed)
    void setVoltage(double voltage);
    void setAvailablePower(double availablePower);

    // Methods for simulating faults and protection responses (can be expanded)
    void simulateFault();
    void handleProtection();
};
#endif // GRID_H
