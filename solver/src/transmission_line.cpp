#include "transmission_line.h"

// Constructor
TransmissionLine::TransmissionLine(const std::string& id, double length, double impedance)
    : id(id), length(length), impedance(impedance) {}

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
