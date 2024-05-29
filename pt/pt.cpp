// PotentialTransformer.cpp

#include "PotentialTransformer.h"

const double IRON_PERMEABILITY = 5000;
const double IRON_SATURATION_DENSITY = 1.6;
const double IRON_HYSTERESIS_LOSS_COEFF = 0.01; // Example hysteresis loss coefficient for iron core

PotentialTransformer::PotentialTransformer(double primaryV, double turns, CoreMaterial material, double permeability, double saturationDensity, double hysteresisLossCoeff) {
    if (turns <= 0) {
        throw std::invalid_argument("Turns ratio must be greater than zero");
    }
    
    primaryVoltage = primaryV;
    turnsRatio = turns;
    secondaryVoltage = primaryVoltage / turnsRatio;
    coreMaterial = material;
    
    switch (coreMaterial) {
        case CoreMaterial::IRON:
            this->permeability = permeability > 0 ? permeability : IRON_PERMEABILITY;
            this->saturationFluxDensity = saturationDensity > 0 ? saturationDensity : IRON_SATURATION_DENSITY;
            this->hysteresisLossCoefficient = hysteresisLossCoeff > 0 ? hysteresisLossCoeff : IRON_HYSTERESIS_LOSS_COEFF;
            break;
        case CoreMaterial::FERRITE:
            // Add values for ferrite core if needed
            break;
        case CoreMaterial::AIR:
            this->permeability = 1;
            this->saturationFluxDensity = 0;
            this->hysteresisLossCoefficient = 0;
            break;
        default:
            throw std::invalid_argument("Invalid core material");
    }
    
    temperature = 25; // Default temperature
    load = 100; // Default load (full load)
    efficiency = 0; // Initialize efficiency
    windingResistance = 0; // Default winding resistance
    coreLoss = 0;
    strayLoss = 0;
    burden = 0; // Default burden
}

double PotentialTransformer::getPrimaryVoltage() {
    return primaryVoltage;
}

double PotentialTransformer::getSecondaryVoltage() {
    return secondaryVoltage;
}

double PotentialTransformer::getImpedance() {
    // Impedance calculation based on transformer parameters
    // For simplicity, let's assume a simple impedance model
    double impedance = 2 * M_PI * 60 * secondaryVoltage / primaryVoltage; // Assuming 60 Hz frequency
    return impedance;
}

double PotentialTransformer::getEfficiency() {
    // Calculate efficiency based on temperature and load
    // For simplicity, let's assume a linear model
    efficiency = (100 - load) / 100 * (1 - std::abs(temperature - 25) / 100);
    return efficiency;
}

void PotentialTransformer::setTemperature(double temp) {
    temperature = temp;
}

void PotentialTransformer::setLoad(double loadPercentage) {
    if (loadPercentage < 0 || loadPercentage > 100) {
        throw std::invalid_argument("Load percentage must be between 0 and 100");
    }
    load = loadPercentage;
}

double PotentialTransformer::calculateTemperatureRise() {
    // Calculate temperature rise based on load and losses
    // For simplicity, let's assume a linear relationship between load and temperature rise
    double temperatureRise = load / 100 * (coreLoss + strayLoss);
    return temperatureRise;
}

void PotentialTransformer::setWindingResistance(double resistance) {
    windingResistance = resistance;
}

double PotentialTransformer::calculateCoreLoss() {
    // Calculate core loss based on current frequency, flux density, and core material
    // For simplicity, let's assume a simplified core loss model
    coreLoss = M_PI * pow(secondaryVoltage, 2) * frequency * hysteresisLossCoefficient;
    return coreLoss;
}

double PotentialTransformer::calculateStrayLoss() {
    // Calculate stray loss based on load and winding resistance
    // For simplicity, let's assume a simplified stray loss model
    strayLoss = pow(secondaryVoltage, 2) / (windingResistance * load / 100);
    return strayLoss;
}

double PotentialTransformer::calculateTotalLoss() {
    // Calculate total loss as the sum of core loss and stray loss
    double totalLoss = coreLoss + strayLoss;
    return totalLoss;
}

double PotentialTransformer::calculateOutputVoltage() {
    // Calculate output voltage based on load and losses
    // For simplicity, let's assume a linear relationship between load and output voltage
   
