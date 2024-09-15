#include "lib/reactor.h"

// Constructor
Reactor::Reactor(const std::string& id, double inductance)
    : id(id), inductance(inductance) {}

// Destructor
Reactor::~Reactor() {}

// Get the ID of the reactor
std::string Reactor::getId() const {
    return id;
}

// Get the inductance of the reactor
double Reactor::getInductance() const {
    return inductance;
}
