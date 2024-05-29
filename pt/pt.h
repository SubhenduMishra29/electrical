// PotentialTransformer.h

#ifndef POTENTIAL_TRANSFORMER_H
#define POTENTIAL_TRANSFORMER_H

#include <stdexcept>
#include <cmath>

enum class CoreMaterial {
    IRON,
    FERRITE,
    AIR
};

class PotentialTransformer {
private:
    double primaryVoltage;
    double secondaryVoltage;
    double turnsRatio;
    CoreMaterial coreMaterial;
    double permeability;
    double saturationFluxDensity;
    double hysteresisLossCoefficient;
    double temperature; // Temperature in Celsius
    double load; // Load in percentage (0 to 100)
    double efficiency;
    double windingResistance;
    double coreLoss;
    double strayLoss;
    double burden; // Load connected to the secondary side

public:
    PotentialTransformer(double primaryV, double turns, CoreMaterial material, double permeability, double saturationDensity, double hysteresisLossCoeff);
    double getPrimaryVoltage();
    double getSecondaryVoltage();
    double getImpedance();
    double getEfficiency();
    void setTemperature(double temp);
    void setLoad(double loadPercentage);
    double calculateTemperatureRise();
    void setWindingResistance(double resistance);
    double calculateCoreLoss();
    double calculateStrayLoss();
    double calculateTotalLoss();
    double calculateOutputVoltage();
    double calculateOutputCurrent();
    void setBurden(double burdenValue);
};

#endif
