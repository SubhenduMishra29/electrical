#include "PowerSystem.h"

int main() {
    PowerSystem ps;
    ps.loadSLD("sld_file.txt");

    // List all buses
    std::vector<Bus*> buses = ps.getBuses();
    for (const auto& bus : buses) {
        // Print or process each bus information
    }

    // List all transformers
    std::vector<Transformer*> transformers = ps.getTransformers();
    for (const auto& transformer : transformers) {
        // Print or process each transformer information
    }

    // List all generators
    std::vector<Generator*> generators = ps.getGenerators();
    for (const auto& generator : generators) {
        // Print or process each generator information
    }

    // List all loads
    std::vector<Load*> loads = ps.getLoads();
    for (const auto& load : loads) {
        // Print or process each load information
    }

    // List all transmission lines
    std::vector<TransmissionLine*> transmissionLines = ps.getTransmissionLines();
    for (const auto& transmissionLine : transmissionLines) {
        // Print or process each transmission line information
    }

    // List all circuit breakers
    std::vector<CircuitBreaker*> circuitBreakers = ps.getCircuitBreakers();
    for (const auto& circuitBreaker : circuitBreakers) {
        // Print or process each circuit breaker information
    }

    // List all relays
    std::vector<Relay*> relays = ps.getRelays();
    for (const auto& relay : relays) {
        // Print or process each relay information
    }

    // List all capacitors
    std::vector<Capacitor*> capacitors = ps.getCapacitors();
    for (const auto& capacitor : capacitors) {
        // Print or process each capacitor information
    }

    // List all reactors
    std::vector<Reactor*> reactors = ps.getReactors();
    for (const auto& reactor : reactors) {
        // Print or process each reactor information
    }

    // Get grid information
    Grid* grid = ps.getGrid();
    // Print or process grid information

    return 0;
}
