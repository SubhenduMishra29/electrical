#include "circuit_breaker.h"

// Constructor
CircuitBreaker::CircuitBreaker(const std::string& id, bool isClosed)
    : id(id), isClosed(isClosed) {}

// Destructor
CircuitBreaker::~CircuitBreaker() {}

// Get the ID of the circuit breaker
std::string CircuitBreaker::getId() const {
    return id;
}

// Get the status of the circuit breaker
bool CircuitBreaker::getStatus() const {
    return isClosed;
}

// Set the status of the circuit breaker
void CircuitBreaker::setStatus(bool status) {
    isClosed = status;
}
