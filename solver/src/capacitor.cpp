#include "Capacitor.h"

// Constructor
Capacitor::Capacitor(const std::string& id, double capacitance, double voltageRating, double lossFactor,
                     bool hasSurgeProtection, const std::string& insulationLevel, const std::string& location,
                     const std::string& protectionDevices)
    : id(id), capacitance(capacitance), voltageRating(voltageRating), lossFactor(lossFactor),
      hasSurgeProtection(hasSurgeProtection), insulationLevel(insulationLevel), location(location),
      protectionDevices(protectionDevices) {
    // Initialize any additional attributes or setup
}

// Destructor
Capacitor::~Capacitor() {
    // Perform cleanup if necessary
}

// Getters for Capacitor attributes
std::string Capacitor::getId() const {
    return id;
}

double Capacitor::getCapacitance() const {
    return capacitance;
}

double Capacitor::getVoltageRating() const {
    return voltageRating;
}

double Capacitor::getLossFactor() const {
    return lossFactor;
}

bool Capacitor::hasSurgeProtectionDevice() const {
    return hasSurgeProtection;
}

std::string Capacitor::getInsulationLevel() const {
    return insulationLevel;
}

std::string Capacitor::getLocation() const {
    return location;
}

std::string Capacitor::getProtectionDevices() const {
    return protectionDevices;
}
