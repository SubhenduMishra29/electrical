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
    double totalGeneration = 0.0;
    double totalConsumption = 0.0;

    // Calculate total power generation from connected generators
    for (auto generator : generators) {
        totalGeneration += generator->getCurrentOutput();
    }

    // Calculate total power consumption from connected loads
    for (auto load : loads) {
        totalConsumption += load->getPowerConsumption();
    }

    // Adjust voltage for each transformer connected to this bus
    for (auto transformer : transformers) {
        transformer->applyTurnsRatio();
    }

    // Implement power flow equations (simplified for illustration)
    // For steady-state analysis, totalGeneration should equal totalConsumption
    // Adjust voltage and power flow based on system specifics

    // Update bus voltage (simplified example)
    // Example: average voltage of all connected transformers
    double totalVoltage = 0.0;
    for (auto transformer : transformers) {
        totalVoltage += transformer->getSecondaryBus()->getVoltage(); // Assuming getSecondaryBus() method exists in Transformer class
    }
    if (!transformers.empty()) {
        voltage = totalVoltage / transformers.size();
    }
}

