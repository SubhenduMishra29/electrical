#include "lib/transformer.h"
#include <iostream>

// Basic constructor
Transformer::Transformer(const std::string& id, double turnsRatio)
    : id(id), turnsRatio(turnsRatio), impedance(0.0), primaryVoltageRating(0.0), secondaryVoltageRating(0.0),
      powerRating(0.0), noLoadLosses(0.0), loadLosses(0.0), tapSetting(0.0), buchholzRelay(false),
      xrRatio(0.0), primaryWindingResistance(0.0), secondaryWindingResistance(0.0),
      magnetizingCurrent(0.0), coreLoss(0.0), totalImpedance(0.0), efficiency(0.0) {
    updateCurrents(); // Initialize currents
    calculateTotalImpedance(); // Calculate initial impedance
    calculateEfficiency(); // Calculate initial efficiency
}

// Detailed constructor
Transformer::Transformer(const std::string& id, double turnsRatio, double impedance, double primaryVoltageRating, double secondaryVoltageRating,
                         double powerRating, double noLoadLosses, double loadLosses, double tapSetting,
                         const std::string& oilType, const std::string& coolingType, bool buchholzRelay,
                         const std::string& neutralPointConfiguration, const std::string& primaryWindingType,
                         const std::string& secondaryWindingType, double xrRatio, double primaryWindingResistance,
                         double secondaryWindingResistance, double magnetizingCurrent, double coreLoss)
    : id(id), turnsRatio(turnsRatio), impedance(impedance), primaryVoltageRating(primaryVoltageRating),
      secondaryVoltageRating(secondaryVoltageRating), powerRating(powerRating), noLoadLosses(noLoadLosses),
      loadLosses(loadLosses), tapSetting(tapSetting), oilType(oilType), coolingType(coolingType),
      buchholzRelay(buchholzRelay), neutralPointConfiguration(neutralPointConfiguration),
      primaryWindingType(primaryWindingType), secondaryWindingType(secondaryWindingType), xrRatio(xrRatio),
      primaryWindingResistance(primaryWindingResistance), secondaryWindingResistance(secondaryWindingResistance),
      magnetizingCurrent(magnetizingCurrent), coreLoss(coreLoss), totalImpedance(0.0), efficiency(0.0) {
    updateCurrents(); // Initialize currents
    calculateTotalImpedance(); // Calculate initial impedance
    calculateEfficiency(); // Calculate initial efficiency
}

std::string Transformer::getId() const {
    return id;
}

void Transformer::setId(const std::string& id) {
    this->id = id;
}

double Transformer::getTurnsRatio() const {
    return turnsRatio;
}

void Transformer::setTurnsRatio(double ratio) {
    turnsRatio = ratio;
    applyTurnsRatio(); // Apply turns ratio changes
    updateCurrents(); // Update currents based on new turns ratio
    calculateTotalImpedance(); // Recalculate impedance if needed
    calculateEfficiency(); // Recalculate efficiency if needed
}

double Transformer::getImpedance() const {
    return impedance;
}

void Transformer::setImpedance(double impedance) {
    this->impedance = impedance;
    calculateTotalImpedance(); // Recalculate impedance
}

double Transformer::getPrimaryVoltageRating() const {
    return primaryVoltageRating;
}

void Transformer::setPrimaryVoltageRating(double voltage) {
    primaryVoltageRating = voltage;
    updateCurrents(); // Update currents based on new voltage rating
    calculateEfficiency(); // Recalculate efficiency if needed
}

double Transformer::getSecondaryVoltageRating() const {
    return secondaryVoltageRating;
}

void Transformer::setSecondaryVoltageRating(double voltage) {
    secondaryVoltageRating = voltage;
    updateCurrents(); // Update currents based on new voltage rating
    calculateEfficiency(); // Recalculate efficiency if needed
}

double Transformer::getPowerRating() const {
    return powerRating;
}

void Transformer::setPowerRating(double power) {
    powerRating = power;
    updateCurrents(); // Update currents based on new power rating
    calculateEfficiency(); // Recalculate efficiency if needed
}

double Transformer::getNoLoadLosses() const {
    return noLoadLosses;
}

void Transformer::setNoLoadLosses(double losses) {
    noLoadLosses = losses;
    calculateEfficiency(); // Recalculate efficiency if needed
}

double Transformer::getLoadLosses() const {
    return loadLosses;
}

void Transformer::setLoadLosses(double losses) {
    loadLosses = losses;
    calculateEfficiency(); // Recalculate efficiency if needed
}

double Transformer::getTapSetting() const {
    return tapSetting;
}

void Transformer::setTapSetting(double tap) {
    tapSetting = tap;
    // Handle any specific logic related to tap setting if needed
}

std::string Transformer::getOilType() const {
    return oilType;
}

void Transformer::setOilType(const std::string& oil) {
    oilType = oil;
    // Handle any specific logic related to oil type if needed
}

std::string Transformer::getCoolingType() const {
    return coolingType;
}

void Transformer::setCoolingType(const std::string& cooling) {
    coolingType = cooling;
    // Handle any specific logic related to cooling type if needed
}

bool Transformer::hasBuchholzRelay() const {
    return buchholzRelay;
}

void Transformer::setBuchholzRelay(bool relay) {
    buchholzRelay = relay;
    // Handle any specific logic related to Buchholz relay if needed
}

std::string Transformer::getNeutralPointConfiguration() const {
    return neutralPointConfiguration;
}

void Transformer::setNeutralPointConfiguration(const std::string& configuration) {
    neutralPointConfiguration = configuration;
    // Handle any specific logic related to neutral point configuration if needed
}

std::string Transformer::getPrimaryWindingType() const {
    return primaryWindingType;
}

void Transformer::setPrimaryWindingType(const std::string& type) {
    primaryWindingType = type;
    // Handle any specific logic related to primary winding type if needed
}

std::string Transformer::getSecondaryWindingType() const {
    return secondaryWindingType;
}

void Transformer::setSecondaryWindingType(const std::string& type) {
    secondaryWindingType = type;
    // Handle any specific logic related to secondary winding type if needed
}

double Transformer::getXrRatio() const {
    return xrRatio;
}

void Transformer::setXrRatio(double ratio) {
    xrRatio = ratio;
    updateImpedanceRelatedValues(); // Update impedance-related values
}

double Transformer::getPrimaryWindingResistance() const {
    return primaryWindingResistance;
}

void Transformer::setPrimaryWindingResistance(double resistance) {
    primaryWindingResistance = resistance;
    updateImpedanceRelatedValues(); // Update impedance-related values
}

double Transformer::getSecondaryWindingResistance() const {
    return secondaryWindingResistance;
}

void Transformer::setSecondaryWindingResistance(double resistance) {
    secondaryWindingResistance = resistance;
    updateImpedanceRelatedValues(); // Update impedance-related values
}

double Transformer::getMagnetizingCurrent() const {
    return magnetizingCurrent;
}

void Transformer::setMagnetizingCurrent(double current) {
    magnetizingCurrent = current;
    // Handle any specific logic related to magnetizing current if needed
}

double Transformer::getCoreLoss() const {
    return coreLoss;
}

void Transformer::setCoreLoss(double loss) {
    coreLoss = loss;
    // Handle any specific logic related to core loss if needed
}

double Transformer::getTotalImpedance() const {
    return totalImpedance;
}

double Transformer::getEfficiency() const {
    return efficiency;
}

Voltage Transformer::getPrimaryVoltage() const {
    return primaryVoltage;
}

void Transformer::setPrimaryVoltage(const Voltage& voltage) {
    primaryVoltage = voltage;
    updateCurrents(); // Update currents based on new voltage
}

Voltage Transformer::getSecondaryVoltage() const {
    return secondaryVoltage;
}

void Transformer::setSecondaryVoltage(const Voltage& voltage) {
    secondaryVoltage = voltage;
    updateCurrents(); // Update currents based on new voltage
}

Current Transformer::getPrimaryCurrent() const {
    return primaryCurrent;
}

void Transformer::setPrimaryCurrent(const Current& current) {
    primaryCurrent = current;
    // Handle any specific logic related to primary current if needed
}

Current Transformer::getSecondaryCurrent() const {
    return secondaryCurrent;
}

void Transformer::setSecondaryCurrent(const Current& current) {
    secondaryCurrent = current;
    // Handle any specific logic related to secondary current if needed
}

void Transformer::addLine(const std::shared_ptr<Line>& line, bool isPrimary) {
    if (isPrimary) {
        primaryLine = line;
    } else {
        secondaryLine = line;
    }
}

void Transformer::removeLine(bool isPrimary) {
    if (isPrimary) {
        primaryLine.reset();
    } else {
        secondaryLine.reset();
    }
}

void Transformer::applyTurnsRatio() const {
    // Logic to apply turns ratio to related values, if needed
}

void Transformer::adjustTap(double newTapSetting) {
    tapSetting = newTapSetting;
    // Handle any specific logic related to tap setting adjustment
}

void Transformer::displayInfo() const {
    std::cout << "Transformer ID: " << id << "\n";
    std::cout << "Turns Ratio: " << turnsRatio << "\n";
    std::cout << "Impedance: " << impedance << "\n";
    std::cout << "Primary Voltage Rating: " << primaryVoltageRating << "\n";
    std::cout << "Secondary Voltage Rating: " << secondaryVoltageRating << "\n";
    std::cout << "Power Rating: " << powerRating << "\n";
    std::cout << "No Load Losses: " << noLoadLosses << "\n";
    std::cout << "Load Losses: " << loadLosses << "\n";
    std::cout << "Tap Setting: " << tapSetting << "\n";
    std::cout << "Oil Type: " << oilType << "\n";
    std::cout << "Cooling Type: " << coolingType << "\n";
    std::cout << "Buchholz Relay: " << (buchholzRelay ? "Yes" : "No") << "\n";
    std::cout << "Neutral Point Configuration: " << neutralPointConfiguration << "\n";
    std::cout << "Primary Winding Type: " << primaryWindingType << "\n";
    std::cout << "Secondary Winding Type: " << secondaryWindingType << "\n";
    std::cout << "X/R Ratio: " << xrRatio << "\n";
    std::cout << "Primary Winding Resistance: " << primaryWindingResistance << "\n";
    std::cout << "Secondary Winding Resistance: " << secondaryWindingResistance << "\n";
    std::cout << "Magnetizing Current: " << magnetizingCurrent << "\n";
    std::cout << "Core Loss: " << coreLoss << "\n";
    std::cout << "Total Impedance: " << totalImpedance << "\n";
    std::cout << "Efficiency: " << efficiency << "\n";
   // std::cout << "Primary Voltage: " << primaryVoltage.getValue() << " " << primaryVoltage.getUnit() << "\n";
  //  std::cout << "Secondary Voltage: " << secondaryVoltage.getValue() << " " << secondaryVoltage.getUnit() << "\n";
  //  std::cout << "Primary Current: " << primaryCurrent.getValue() << " " << primaryCurrent.getUnit() << "\n";
  //  std::cout << "Secondary Current: " << secondaryCurrent.getValue() << " " << secondaryCurrent.getUnit() << "\n";
}

void Transformer::calculateTotalImpedance() {
    // Example calculation; adjust based on actual formula
    // For a simple transformer, the impedance might be calculated as:
    totalImpedance = impedance + (primaryWindingResistance + secondaryWindingResistance) / turnsRatio;
}

void Transformer::calculateEfficiency() {
    if (powerRating > 0) {
        efficiency = (powerRating - (noLoadLosses + loadLosses)) / powerRating * 100;
    } else {
        efficiency = 0.0;
    }
}

void Transformer::updateCurrents() {
    // Update primary current if primary voltage rating is greater than zero
    if (primaryVoltageRating > 0) {
        // Calculate primary current based on power rating and primary voltage
        primaryCurrent = Current(powerRating / primaryVoltageRating);
    } else {
        // Handle cases where primary voltage is not set or invalid
        primaryCurrent = Current(0.0); // Or handle error as appropriate
    }

    // Update secondary current if secondary voltage rating is greater than zero
    if (secondaryVoltageRating > 0) {
        // Calculate secondary current based on power rating and secondary voltage
        secondaryCurrent = Current(powerRating / secondaryVoltageRating);
    } else {
        // Handle cases where secondary voltage is not set or invalid
        secondaryCurrent = Current(0.0); // Or handle error as appropriate
    }
}

void Transformer::updateImpedanceRelatedValues() {
    // Implement detailed impedance-related calculations if needed
}
