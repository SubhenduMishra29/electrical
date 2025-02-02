#ifndef PORT_H
#define PORT_H

#include <cstdint>
#include <array>

class Port {
public:
    static const size_t PIN_COUNT = 8; // Number of pins in a port

private:
    std::array<bool, PIN_COUNT> pins;  // State of each pin (true for high, false for low)
    std::array<bool, PIN_COUNT> pullups; // Declare pullups array

public:
    // Constructor
    Port();

    // Set the state of a specific pin
    void setPin(uint8_t pin, bool state);

    // Get the state of a specific pin
    bool getPin(uint8_t pin) const;

    // Set the pullup state of a specific pin
    void setPullup(uint8_t pin, bool enable);

    // Check if the pullup is enabled for a specific pin
    bool isPullupEnabled(uint8_t pin) const;

    // Reset the port
    void reset();
};

#endif // PORT_H
