#include "bus.h"

// Constructor
Bus::Bus(int id, const std::string& name, BusType type)
    : id(id), name(name), type(type), voltageMagnitude(1.0), voltageAngle(0.0),
      realPowerInjection(0.0), reactivePowerInjection(0.0), isSlack(false) {}

// Getters
int Bus::getId() const {
    return id;
}

std::string Bus::getName() const {
    return name;
}

BusType Bus::getType() const {
    return type;
}

double Bus::getVoltageMagnitude() const {
    return voltageMagnitude;
}

double Bus::getVoltageAngle() const {
    return voltageAngle;
}

double Bus::getRealPowerInjection() const {
    return realPowerInjection;
}

double Bus::getReactivePowerInjection() const {
    return reactivePowerInjection;
}

std::vector<int> Bus::getConnectedBuses() const {
    return connectedBuses;
}

std::vector<Generator> Bus::getGenerators() const {
    return generators;
}

std::vector<Load> Bus::getLoads() const {
    return loads;
}

// Setters
void Bus::setVoltageMagnitude(double voltageMagnitude) {
    this->voltageMagnitude = voltageMagnitude;
}

void Bus::setVoltageAngle(double voltageAngle) {
    this->voltageAngle = voltageAngle;
}

void Bus::setRealPowerInjection(double realPowerInjection) {
    this->realPowerInjection = realPowerInjection;
}

void Bus::setReactivePowerInjection(double reactivePowerInjection) {
    this->reactivePowerInjection = reactivePowerInjection;
}

void Bus::addConnectedBus(int busId) {
    connectedBuses.push_back(busId);
}

void Bus::addGenerator(const Generator& generator) {
    generators.push_back(generator);
}

void Bus::addLoad(const Load& load) {
    loads.push_back(load);
}

// Function to calculate total load
std::pair<double, double> Bus::calculateTotalLoad() const {
    double totalActivePower = 0.0;
    double totalReactivePower = 0.0;
    for (const auto& load : loads) {
        totalActivePower += load.activePowerDemand;
        totalReactivePower += load.reactivePowerDemand;
    }
    return {totalActivePower, totalReactivePower};
}

// Function to calculate total generation
std::pair<double, double> Bus::calculateTotalGeneration() const {
    double totalActivePower = 0.0;
    double totalReactivePower = 0.0;
    for (const auto& gen : generators) {
        totalActivePower += gen.activePower;
        totalReactivePower += gen.reactivePower;
    }
    return {totalActivePower, totalReactivePower};
}
