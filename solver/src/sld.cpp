#include "sld.h"

// Constructor
SLD::SLD() {
    // Initialize or assemble the SLD in the constructor
    assemble();
}

// Function to assemble the SLD
void SLD::assemble() {
    // Clear existing data (if any)
    buses.clear();
    lines.clear();

    // Define buses
    Bus bus1(1, "Bus 1", BusType::SLACK);
    Bus bus2(2, "Bus 2", BusType::PQ);
    Bus bus3(3, "Bus 3", BusType::PQ);
    Bus bus4(4, "Bus 4", BusType::PV);

    // Add generators to buses
    Generator gen1{1.0, 0.0, 2.0, -2.0}; // active power, reactive power, max reactive power, min reactive power
    bus4.addGenerator(gen1);

    // Add loads to buses
    MotorLoad motor1{1.0, 0.85, 0.8}; // rated power, power factor, utilization factor
    StaticLoad static1{0.5, 0.2, 0.1}; // constant power, constant impedance, constant current
    bus2.addMotorLoad(motor1);
    bus2.addStaticLoad(static1);

    // Add buses to the vector
    buses.push_back(bus1);
    buses.push_back(bus2);
    buses.push_back(bus3);
    buses.push_back(bus4);

    // Define lines (connections between buses)
    Line line1{1, 2, 0.1}; // from bus, to bus, impedance
    Line line2{1, 3, 0.05}; // from bus, to bus, impedance
    Line line3{2, 4, 0.15}; // from bus, to bus, impedance
    Line line4{3, 4, 0.08}; // from bus, to bus, impedance

    // Add lines to the vector
    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);
}

// Getters
std::vector<Bus>& SLD::getBuses() {
    return buses;
}

const std::vector<Bus>& SLD::getBuses() const {
    return buses;
}

std::vector<Line>& SLD::getLines() {
    return lines;
}

const std::vector<Line>& SLD::getLines() const {
    return lines;
}
