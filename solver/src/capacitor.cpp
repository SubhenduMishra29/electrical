#include "capacitor.h"

// Constructor
Capacitor::Capacitor(const std::string& id, double capacitance)
    : id(id), capacitance(capacitance) {}

// Destructor
Capacitor::~Capacitor() {}

// Get the ID of the capacitor
std::string Capacitor::getId() const {
    return id;
}

// Get the capacitance of the capacitor
double Capacitor::getCapacitance() const {
    return capacitance;
}
