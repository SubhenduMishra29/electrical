#include "CapacitorBank.h"

// Constructor
CapacitorBank::CapacitorBank(const std::string& id, double capacitance, double voltageRating, double frequency,
                             double temperatureRating, double powerRating, int numUnits, const std::string& configuration,
                             const std::string& placement, bool hasProtection)
    : id(id), capacitance(capacitance), voltageRating(voltageRating), frequency(frequency),
      temperatureRating(temperatureRating), powerRating(powerRating), numUnits(numUnits), configuration(configuration),
      placement(placement), hasProtection(hasProtection) {
    // Initialize any additional attributes or setup
}

// Destructor
CapacitorBank::~CapacitorBank() {
    // Perform cleanup if necessary
}

// Method to add a capacitor to the bank
void CapacitorBank::addCapacitor(const Capacitor& capacitor) {
    capacitors.push_back(capacitor);
}

// Getter for the vector of capacitors
std::vector<Capacitor> CapacitorBank::getCapacitors() const {
    return capacitors;
}

// Getters for CapacitorBank attributes
std::string CapacitorBank::getId() const {
    return id;
}

double CapacitorBank::getCapacitance() const {
    return capacitance;
}

double CapacitorBank::getVoltageRating() const {
    return voltageRating;
}

double CapacitorBank::getFrequency() const {
    return frequency;
}

double CapacitorBank::getTemperatureRating() const {
    return temperatureRating;
}

double CapacitorBank::getPowerRating() const {
    return powerRating;
}

int CapacitorBank::getNumUnits() const {
    return numUnits;
}

std::string CapacitorBank::getConfiguration() const {
    return configuration;
}

std::string CapacitorBank::getPlacement() const {
    return placement;
}

bool CapacitorBank::hasProtectionDevices() const {
    return hasProtection;
}
