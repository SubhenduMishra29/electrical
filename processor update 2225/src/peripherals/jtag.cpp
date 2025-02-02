#include "jtag.h"

JTAG::JTAG() : enabled(false) {}

void JTAG::reset() {
    enabled = false;
    std::cout << "JTAG reset.\n";
}

void JTAG::simulateOperation() {
    if (enabled) {
        std::cout << "Simulating JTAG operation.\n";
    } else {
        std::cerr << "Error: JTAG is not enabled.\n";
    }
}

void JTAG::enable() {
    enabled = true;
    std::cout << "JTAG enabled.\n";
}

void JTAG::disable() {
    enabled = false;
    std::cout << "JTAG disabled.\n";
}

bool JTAG::isEnabled() const {
    return enabled;
}
