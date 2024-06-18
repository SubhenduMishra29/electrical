#include "relay.h"

// Constructor
Relay::Relay(const std::string& id, double setting)
    : id(id), setting(setting) {}

// Destructor
Relay::~Relay() {}

// Get the ID of the relay
std::string Relay::getId() const {
    return id;
}

// Get the setting of the relay
double Relay::getSetting() const {
    return setting;
}
