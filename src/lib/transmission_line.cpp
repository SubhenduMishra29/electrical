#include "lib/transmission_line.h"


// Constructor
TransmissionLine::TransmissionLine(const std::string& id, double length, double impedance, Bus* bus1, Bus* bus2)
    : id(id), length(length), impedance(impedance), bus1(bus1), bus2(bus2) {}

// Destructor
TransmissionLine::~TransmissionLine() {}

// Get the ID of the transmission line
std::string TransmissionLine::getId() const {
    return id;
}

// Get the length of the transmission line
double TransmissionLine::getLength() const {
    return length;
}

// Get the impedance of the transmission line
double TransmissionLine::getImpedance() const {
    return impedance;
}

