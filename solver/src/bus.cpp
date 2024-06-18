#include "bus.h"

Bus::Bus(double voltage) {
    this->voltage = voltage;
}

void Bus::addGenerator(Generator* generator) {
    generators.push_back(generator);
}

void Bus::addLoad(Load* load) {
    loads.push_back(load);
}

void Bus::addTransmissionLine(TransmissionLine* line) {
    transmissionLines.push_back(line);
}

void Bus::addTransformer(Transformer* transformer) {
    transformers.push_back(transformer);
}

double Bus::getVoltage() {
    return voltage;
}

void Bus::setVoltage(double voltage) {
    this->voltage = voltage;
}

void Bus::calculatePowerFlow() {
    // Implement power flow calculations based on connected generators, loads, and transformers
    // Consider transformer effects on voltage and power flow
}
