/**
 * @file powersystem.cpp
 * @brief This file contains the implementation of the PowerSystem class methods.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */
#include <iostream>
#include "power_system.h"
#include "lib/powerflow.h"
#include "lib/sld.h"
#include <fstream>
#include <iostream>

PowerSystem::PowerSystem() : sld(nullptr), converged(false) {
    // Constructor implementation
}
/// @brief 
/// @param filename
void PowerSystem::loadSLDFromFile(const std::string& filename) {
    sld = SLD::loadFromFile(filename); // Correctly use static method to assign SLD object
}
/// @brief 
/// @param cliInput 
void PowerSystem::loadSLDFromCLI(const std::string& cliInput) {
    // Example: Load SLD from CLI input and initialize `sld`
  //  sld = SLD::createFromCLI(cliInput);
}

void PowerSystem::runSimulation() {
    try {
        if (sld == nullptr) {
            throw PowerSystemError("No SLD loaded. Cannot run simulation.");
        }

        powerFlow.performLoadFlow(*this); // Pass `PowerSystem` itself
        powerFlow.calculateVoltageDrop(*this);
        powerFlow.performShortCircuitAnalysis(*this);
        powerFlow.performDCShortCircuitAnalysis(*this);
        powerFlow.performDCLoadFlow(*this);

        // Check for convergence (example criteria)
        converged = true; // Placeholder for actual convergence check
    } catch (const PowerSystemError& e) {
        std::cerr << "Power System Error: " << e.what() << std::endl;
        throw; // Propagate the error up
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        throw; // Propagate the error up
    }
}

bool PowerSystem::isConverged() const {
    return converged;
}

// Implement other getter methods for components as previously shown
