#include "lib/transformer.h"
#include <cmath>

// Basic constructor implementation
Transformer::Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio)
    : primaryBus(primaryBus), secondaryBus(secondaryBus), turnsRatio(turnsRatio), impedance(0), primaryVoltageRating(0), secondaryVoltageRating(0), powerRating(0), noLoadLosses(0), loadLosses(0), tapSetting(1.0), oilType("Mineral Oil"), coolingType("ONAN"), buchholzRelay(false), neutralPointConfiguration("Solid Grounded"), primaryWindingType("Delta"), secondaryWindingType("Wye"), xrRatio(0), primaryWindingResistance(0), secondaryWindingResistance(0), magnetizingCurrent(0), coreLoss(0), totalImpedance(0), efficiency(0) {
    calculateDerivedValues();
}

// Detailed constructor implementation
Transformer::Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double impedance, double primaryVoltageRating, double secondaryVoltageRating, double powerRating, double noLoadLosses, double loadLosses, double tapSetting, std::string oilType, std::string coolingType, bool buchholzRelay, std::string neutralPointConfiguration, std::string primaryWindingType, std::string secondaryWindingType, double xrRatio, double primaryWindingResistance, double secondaryWindingResistance, double magnetizingCurrent, double coreLoss)
    : primaryBus(primaryBus), secondaryBus(secondaryBus), turnsRatio(turnsRatio), impedance(impedance), primaryVoltageRating(primaryVoltageRating), secondaryVoltageRating(secondaryVoltageRating), powerRating(powerRating), noLoadLosses(noLoadLosses), loadLosses(loadLosses), tapSetting(tapSetting), oilType(oilType), coolingType(coolingType), buchholzRelay(buchholzRelay), neutralPointConfiguration(neutralPointConfiguration), primaryWindingType(primaryWindingType), secondaryWindingType(secondaryWindingType), xrRatio(xrRatio), primaryWindingResistance(primaryWindingResistance), secondaryWindingResistance(secondaryWindingResistance), magnetizingCurrent(magnetizingCurrent), coreLoss(coreLoss), totalImpedance(0), efficiency(0) {
    calculateDerivedValues();
}

// Getters and setters
Bus* Transformer::getPrimaryBus() const { return primaryBus; }
void Transformer::setPrimaryBus(Bus* bus) { primaryBus = bus; }

Bus* Transformer::getSecondaryBus() const { return secondaryBus; }
void Transformer::setSecondaryBus(Bus* bus) { secondaryBus = bus; }

double Transformer::getTurnsRatio() const { return turnsRatio; }
void Transformer::setTurnsRatio(double ratio) { turnsRatio = ratio; calculateDerivedValues(); }

double Transformer::getImpedance() const { return impedance; }
void Transformer::setImpedance(double imp) { impedance = imp; calculateDerivedValues(); }

double Transformer::getPrimaryVoltageRating() const { return primaryVoltageRating; }
void Transformer::setPrimaryVoltageRating(double voltage) { primaryVoltageRating = voltage; }

double Transformer::getSecondaryVoltageRating() const { return secondaryVoltageRating; }
void Transformer::setSecondaryVoltageRating(double voltage) { secondaryVoltageRating = voltage; }

double Transformer::getPowerRating() const { return powerRating; }
void Transformer::setPowerRating(double power) { powerRating = power; }

double Transformer::getNoLoadLosses() const { return noLoadLosses; }
void Transformer::setNoLoadLosses(double losses) { noLoadLosses = losses; calculateDerivedValues(); }

double Transformer::getLoadLosses() const { return loadLosses; }
void Transformer::setLoadLosses(double losses) { loadLosses = losses; calculateDerivedValues(); }

double Transformer::getTapSetting() const { return tapSetting; }
void Transformer::setTapSetting(double tap) { tapSetting = tap; }

std::string Transformer::getOilType() const { return oilType; }
void Transformer::setOilType(const std::string& oil) { oilType = oil; }

std::string Transformer::getCoolingType() const { return coolingType; }
void Transformer::setCoolingType(const std::string& cooling) { coolingType = cooling; }

bool Transformer::hasBuchholzRelay() const { return buchholzRelay; }
void Transformer::setBuchholzRelay(bool relay) { buchholzRelay = relay; }

std::string Transformer::getNeutralPointConfiguration() const { return neutralPointConfiguration; }
void Transformer::setNeutralPointConfiguration(const std::string& configuration) { neutralPointConfiguration = configuration; }

std::string Transformer::getPrimaryWindingType() const { return primaryWindingType; }
void Transformer::setPrimaryWindingType(const std::string& type) { primaryWindingType = type; }

std::string Transformer::getSecondaryWindingType() const { return secondaryWindingType; }
void Transformer::setSecondaryWindingType(const std::string& type) { secondaryWindingType = type; }

double Transformer::getXrRatio() const { return xrRatio; }
void Transformer::setXrRatio(double ratio) { xrRatio = ratio; calculateDerivedValues(); }

double Transformer::getPrimaryWindingResistance() const { return primaryWindingResistance; }
void Transformer::setPrimaryWindingResistance(double resistance) { primaryWindingResistance = resistance; calculateDerivedValues(); }

double Transformer::getSecondaryWindingResistance() const { return secondaryWindingResistance; }
void Transformer::setSecondaryWindingResistance(double resistance) { secondaryWindingResistance = resistance; calculateDerivedValues(); }

double Transformer::getMagnetizingCurrent() const { return magnetizingCurrent; }
void Transformer::setMagnetizingCurrent(double current) { magnetizingCurrent = current; calculateDerivedValues(); }

double Transformer::getCoreLoss() const { return coreLoss; }
void Transformer::setCoreLoss(double loss) { coreLoss = loss; }

double Transformer::getTotalImpedance() const { return totalImpedance; }
double Transformer::getEfficiency() const { return efficiency; }

// Other methods
void Transformer::applyTurnsRatio() const {
    // Implement logic to apply turns ratio
}

void Transformer::adjustTap(double newTapSetting) {
    // Implement logic to adjust tap setting
    tapSetting = newTapSetting;
}

void Transformer::calculateDerivedValues() {
    // Calculate total impedance based on X/R ratio and winding resistances
    double xOverR = xrRatio > 0 ? xrRatio : 1.0; // Default to 1 if xrRatio is not provided
    totalImpedance = sqrt(pow(primaryWindingResistance + secondaryWindingResistance * turnsRatio, 2) + pow(primaryWindingResistance * turnsRatio + secondaryWindingResistance, 2)) * xOverR;

    // Calculate efficiency based on losses
    if (powerRating > 0) {
        efficiency = (powerRating - (noLoadLosses + loadLosses)) / powerRating;
    } else {
        efficiency = 0.0;
    }
}

void Transformer::calculateEfficiency() {
    // Calculate efficiency based on current losses
    if (powerRating > 0) {
        efficiency = (powerRating - (noLoadLosses + loadLosses)) / powerRating;
    } else {
        efficiency = 0.0;
    }
}
