#ifndef SLD_H
#define SLD_H

#include "bus.h"
#include "transformer.h"
#include "generator.h"
#include "load.h"
#include "transmission_line.h"
#include "circuit_breaker.h"
#include "relay.h"
#include "capacitor.h"
#include "reactor.h"
#include "grid.h"
#include "CT.h"
#include "PT.h"
#include "line.h"
#include <vector>
#include "PowerSystemError.h"

// Class to represent the Single Line Diagram (SLD)
class SLD {
public:
    // Constructor
    SLD();

    // Function to assemble the SLD
    void assemble();

    // Getters for all components
    std::vector<Bus>& getBuses();
    const std::vector<Bus>& getBuses() const;
    std::vector<Transformer>& getTransformers();
    const std::vector<Transformer>& getTransformers() const;
    std::vector<Generator>& getGenerators();
    const std::vector<Generator>& getGenerators() const;
    std::vector<Load>& getLoads();
    const std::vector<Load>& getLoads() const;
    std::vector<TransmissionLine>& getTransmissionLines();
    const std::vector<TransmissionLine>& getTransmissionLines() const;
    std::vector<CircuitBreaker>& getCircuitBreakers();
    const std::vector<CircuitBreaker>& getCircuitBreakers() const;
    std::vector<Relay>& getRelays();
    const std::vector<Relay>& getRelays() const;
    std::vector<Capacitor>& getCapacitors();
    const std::vector<Capacitor>& getCapacitors() const;
    std::vector<Reactor>& getReactors();
    const std::vector<Reactor>& getReactors() const;
    std::vector<Grid>& getGrids();
    const std::vector<Grid>& getGrids() const;
    std::vector<CT>& getCTs();
    const std::vector<CT>& getCTs() const;
    std::vector<PT>& getPTs();
    const std::vector<PT>& getPTs() const;
    std::vector<Line>& getLines();
    const std::vector<Line>& getLines() const;

private:
    std::vector<Bus> buses;                     // List of buses in the SLD
    std::vector<Transformer> transformers;      // List of transformers in the SLD
    std::vector<Generator> generators;          // List of generators in the SLD
    std::vector<Load> loads;                    // List of loads in the SLD
    std::vector<TransmissionLine> transmissionLines;  // List of transmission lines in the SLD
    std::vector<CircuitBreaker> circuitBreakers;// List of circuit breakers in the SLD
    std::vector<Relay> relays;                  // List of relays in the SLD
    std::vector<Capacitor> capacitors;          // List of capacitors in the SLD
    std::vector<Reactor> reactors;              // List of reactors in the SLD
    std::vector<Grid> grids;                    // List of grids in the SLD
    std::vector<CT> cts;                        // List of current transformers in the SLD
    std::vector<PT> pts;                        // List of potential transformers in the SLD
    std::vector<Line> lines;                    // List of lines in the SLD
};

#endif // SLD_H
