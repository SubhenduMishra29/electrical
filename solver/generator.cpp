#include "generator.h"

// Constructor
Generator::Generator(const std::string& id, double powerOutput)
    : id(id), powerOutput(powerOutput) {}

// Destructor
Generator::~Generator() {}

// Get the ID of the generator
std::string Generator::getId() const {
    return id;
}

// Get the power output of the generator
double Generator::getPowerOutput() const {
    return powerOutput;
}
