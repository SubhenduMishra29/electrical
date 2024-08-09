#include "lib/bus.h"

Bus::Bus(const std::string& name, double voltage, BusType type) {
    // Initialize other members if necessary
}

void Bus::addGenerator(Generator* generator) {
    generators.push_back(generator);
}
/// @brief 
/// @param load 
void Bus::addLoad(Load* load) {
    loads.push_back(load);
}

void Bus::addTransmissionLine(TransmissionLine* line) {
    transmissionLines.push_back(line);
}

void Bus::addTransformer(Transformer* transformer) {
    transformers.push_back(transformer);
}

double Bus::getVoltage() const {
    return voltage;
}

void Bus::setVoltage(double voltage) {
    this->voltage = voltage;
}

void Bus::calculatePowerFlow() {
    // Implement power flow calculation logic
}
