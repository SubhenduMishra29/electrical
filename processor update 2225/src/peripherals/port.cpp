#include "port.h"
#include <iostream>

Port::Port() {
    pins.fill(false); // Initialize all pins to low state
    pullups.fill(false); // Initialize all pull-up resistors to disabled
}

void Port::setPin(uint8_t pin, bool state) {
    if (pin < PIN_COUNT) {
        pins[pin] = state;
        std::cout << "Port: Pin " << (int)pin << " set to " << (state ? "high" : "low") << "\n";
        // Handle internal pull-up resistor behavior
        if (state && pullups[pin]) {
            std::cout << "Port: Pin " << (int)pin << " sourcing current due to pull-up resistor\n";
        }
    } else {
        std::cerr << "Error: Invalid pin number: " << (int)pin << "\n";
    }
}

bool Port::getPin(uint8_t pin) const {
    if (pin < PIN_COUNT) {
        return pins[pin];
    } else {
        std::cerr << "Error: Invalid pin number: " << (int)pin << "\n";
        return false;
    }
}

void Port::reset() {
    pins.fill(false);
    pullups.fill(false); // Disable all pull-up resistors
    std::cout << "Port reset. All pins tri-stated.\n";
}

// Enable or disable pull-up resistor for a specific pin
void Port::setPullup(uint8_t pin, bool enable) {
    if (pin < PIN_COUNT) {
        pullups[pin] = enable;
        std::cout << "Port: Pull-up resistor for pin " << (int)pin << (enable ? " enabled" : " disabled") << "\n";
        // Handle internal pull-up resistor behavior
        if (enable && pins[pin]) {
            std::cout << "Port: Pin " << (int)pin << " sourcing current due to pull-up resistor\n";
        }
    } else {
        std::cerr << "Error: Invalid pin number: " << (int)pin << "\n";
    }
}

// Check if pull-up resistor is enabled for a specific pin
bool Port::isPullupEnabled(uint8_t pin) const {
    if (pin < PIN_COUNT) {
        return pullups[pin];
    } else {
        std::cerr << "Error: Invalid pin number: " << (int)pin << "\n";
        return false;
    }
}
