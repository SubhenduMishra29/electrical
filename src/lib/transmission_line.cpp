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

// Get the voltage of the bus connected by this transmission line
Voltage TransmissionLine::getConnectedBusVoltage(const Bus* bus) const {
    if (bus == bus1) {
        return bus2->getVoltage();
    } else if (bus == bus2) {
        return bus1->getVoltage();
    } else {
        // Handle error: Bus is not connected by this line
        throw PowerSystemError("The provided bus is not connected by this transmission line.");
    }
}
