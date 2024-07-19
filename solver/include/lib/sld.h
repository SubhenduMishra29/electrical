#ifndef SLD_H
#define SLD_H

/*
 * File: SLD.h
 * Author: Subhendu Mishra
 * Description: Header file for the SLD (Single Line Diagram) class, which represents a single line diagram of a power system. 
 *              Includes declarations for various components such as buses, transformers, generators, loads, transmission lines,
 *              circuit breakers, relays, capacitors, reactors, grids, current transformers (CTs), potential transformers (PTs),
 *              and lines. Provides methods to assemble the SLD and access components.
 * License: GPL
 */

#include <vector>
#include <string>

// Forward declarations to reduce unnecessary header inclusions
class Bus;
class Transformer;
class Generator;
class Load;
class TransmissionLine;
class CircuitBreaker;
class Relay;
class Capacitor;
class Reactor;
class Grid;
//class CT;
//class PT;
class Line;
class InputParser;

// Class to represent the Single Line Diagram (SLD)
class SLD {
public:
    // Constructor and Destructor
    SLD(); // Constructor to initialize an SLD object
    ~SLD(); // Destructor to clean up resources

    // Function to assemble the SLD from a file
    void assemble(const std::string& filename); // Assembles the components of the SLD from a given file

    // Function to assemble the SLD from CLI input
    void assembleFromCLI(const std::string& cliInput); // Assembles the components of the SLD from CLI input

    // Getters for all components
    std::vector<Bus>& getBuses(); // Returns a reference to the list of buses
    const std::vector<Bus>& getBuses() const; // Returns a const reference to the list of buses
    std::vector<Transformer>& getTransformers(); // Returns a reference to the list of transformers
    const std::vector<Transformer>& getTransformers() const; // Returns a const reference to the list of transformers
    std::vector<Generator>& getGenerators(); // Returns a reference to the list of generators
    const std::vector<Generator>& getGenerators() const; // Returns a const reference to the list of generators
    std::vector<Load>& getLoads(); // Returns a reference to the list of loads
    const std::vector<Load>& getLoads() const; // Returns a const reference to the list of loads
    std::vector<TransmissionLine>& getTransmissionLines(); // Returns a reference to the list of transmission lines
    const std::vector<TransmissionLine>& getTransmissionLines() const; // Returns a const reference to the list of transmission lines
    std::vector<CircuitBreaker>& getCircuitBreakers(); // Returns a reference to the list of circuit breakers
    const std::vector<CircuitBreaker>& getCircuitBreakers() const; // Returns a const reference to the list of circuit breakers
    std::vector<Relay>& getRelays(); // Returns a reference to the list of relays
    const std::vector<Relay>& getRelays() const; // Returns a const reference to the list of relays
    std::vector<Capacitor>& getCapacitors(); // Returns a reference to the list of capacitors
    const std::vector<Capacitor>& getCapacitors() const; // Returns a const reference to the list of capacitors
    std::vector<Reactor>& getReactors(); // Returns a reference to the list of reactors
    const std::vector<Reactor>& getReactors() const; // Returns a const reference to the list of reactors
    std::vector<Grid>& getGrids(); // Returns a reference to the list of grids
    const std::vector<Grid>& getGrids() const; // Returns a const reference to the list of grids
   // std::vector<CT>& getCTs(); // Returns a reference to the list of current transformers (CTs)
   // const std::vector<CT>& getCTs() const; // Returns a const reference to the list of current transformers (CTs)
   // std::vector<PT>& getPTs(); // Returns a reference to the list of potential transformers (PTs)
   // const std::vector<PT>& getPTs() const; // Returns a const reference to the list of potential transformers (PTs)
    std::vector<Line>& getLines(); // Returns a reference to the list of lines
    const std::vector<Line>& getLines() const; // Returns a const reference to the list of lines

private:
    std::vector<Bus> buses; // List of buses in the SLD
    std::vector<Transformer> transformers; // List of transformers in the SLD
    std::vector<Generator> generators; // List of generators in the SLD
    std::vector<Load> loads; // List of loads in the SLD
    std::vector<TransmissionLine> transmissionLines; // List of transmission lines in the SLD
    std::vector<CircuitBreaker> circuitBreakers; // List of circuit breakers in the SLD
    std::vector<Relay> relays; // List of relays in the SLD
    std::vector<Capacitor> capacitors; // List of capacitors in the SLD
    std::vector<Reactor> reactors; // List of reactors in the SLD
    std::vector<Grid> grids; // List of grids in the SLD
   // std::vector<CT> cts; // List of current transformers (CTs) in the SLD
   // std::vector<PT> pts; // List of potential transformers (PTs) in the SLD
    std::vector<Line> lines; // List of lines in the SLD
};

#endif // SLD_H
