#include "power_system.h"

PowerSystem::PowerSystem() {
    // Initialize any necessary components or configurations
}

void PowerSystem::addBus(Bus* bus) {
    buses.push_back(bus);
}

void PowerSystem::addTransformer(Transformer* transformer) {
    transformers.push_back(transformer);
}

void PowerSystem::runSimulation() {
    // Iterate through each bus in the power system
    for (auto bus : buses) {
        // Calculate power flow for the current bus
        bus->calculatePowerFlow();
    }

    // Additional logic for updating system state, outputting results, etc.
    // This could include updating GUI, logging data, generating reports, etc.
}
