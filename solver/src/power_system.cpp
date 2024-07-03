/**
 * @file power_system.cpp
 * @brief This file contains the implementation of the PowerSystem class methods.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#include "power_system.h"

PowerSystem::PowerSystem() : sld(nullptr) {
    // Constructor implementation
}

void PowerSystem::loadSLD(const SLD& sld) {
    this->sld = &sld; // Store reference to the SLD object
}

void PowerSystem::runSimulation() {
    try {
        powerFlow.performLoadFlow(*sld);
        powerFlow.calculateVoltageDrop(*sld);
        powerFlow.performShortCircuitAnalysis(*sld);
        powerFlow.performDCShortCircuitAnalysis(*sld);
        powerFlow.performDCLoadFlow(*sld);
        // Other simulation steps...

    } catch (const PowerSystemError& e) {
        std::cerr << "Power System Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
}

std::vector<Bus*> PowerSystem::getBuses() const {
    return sld->getBuses();
}

std::vector<Transformer*> PowerSystem::getTransformers() const {
    return sld->getTransformers();
}

std::vector<Generator*> PowerSystem::getGenerators() const {
    return sld->getGenerators();
}

std::vector<Load*> PowerSystem::getLoads() const {
    return sld->getLoads();
}

std::vector<TransmissionLine*> PowerSystem::getTransmissionLines() const {
    return sld->getTransmissionLines();
}

std::vector<CircuitBreaker*> PowerSystem::getCircuitBreakers() const {
    return sld->getCircuitBreakers();
}

std::vector<Relay*> PowerSystem::getRelays() const {
    return sld->getRelays();
}

std::vector<Capacitor*> PowerSystem::getCapacitors() const {
    return sld->getCapacitors();
}

std::vector<Reactor*> PowerSystem::getReactors() const {
    return sld->getReactors();
}

Grid* PowerSystem::getGrid() const {
    return sld->getGrid();
}
