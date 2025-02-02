#ifndef JTAG_H
#define JTAG_H

#include <iostream>

class JTAG {
public:
    // Constructor
    JTAG();

    // Reset the JTAG interface
    void reset();

    // Simulate a JTAG operation
    void simulateOperation();

    // Enable the JTAG interface
    void enable();

    // Disable the JTAG interface
    void disable();

    // Check if JTAG is enabled
    bool isEnabled() const;

private:
    bool enabled; // Flag to check if JTAG is enabled
};

#endif // JTAG_H
