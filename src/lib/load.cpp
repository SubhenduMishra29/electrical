#include "lib/load.h"

// Constructor
Load::Load(const std::string& id, double powerDemand)
    : id(id), powerDemand(powerDemand) {}

// Destructor
Load::~Load() {}

// Get the ID of the load
std::string Load::getId() const {
    return id;
}

// Get the power demand of the load
double Load::getPowerDemand() const {
    return powerDemand;
}
