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
    // Implement simulation logic for the entire power system
    // Include transformer effects in the power flow analysis
}
