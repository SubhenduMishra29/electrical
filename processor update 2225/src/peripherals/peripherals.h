#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "ADC.h"
#include "USART.h"
#include "port.h"
#include "JTAG.h"
#include "Timer.h" // Add this include for Timer
#include "SPI.h"   // Add this include for SPI
#include "PWMChannel.h" // Add this include for PWMChannel
#include <array>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

// Add this forward declaration
class PWMChannel;

class Peripherals {
public:
    enum class IOLineMode {
        Input,
        Output
    };

private:
    static const size_t IO_REGISTER_COUNT = 64; // Number of I/O registers
    std::array<uint8_t, IO_REGISTER_COUNT> ioRegisters; // I/O register storage
    std::array<std::function<void(uint8_t)>, IO_REGISTER_COUNT> peripheralCallbacks; // Peripheral callbacks

    ADC adc;     // Analog-to-Digital Converter
    USART usart; // Universal Synchronous/Asynchronous Receiver-Transmitter
    std::vector<Port> ports; // Container for ports
    /**
     * @brief JTAG interface for debugging and programming.
     */
    JTAG jtag;   // JTAG interface
    std::vector<Timer> timers; // Container for timers
    std::vector<PWMChannel> pwmChannels; // Container for PWM channels
    SPI spi; // SPI interface

public:
    // Constructor
    Peripherals(size_t portCount);

    // Read from an I/O register
    uint8_t readIORegister(uint8_t address) const;

    // Write to an I/O register
    void writeIORegister(uint8_t address, uint8_t value);

    // Attach a peripheral callback to a specific I/O register
    void attachPeripheral(uint8_t address, const std::function<void(uint8_t)>& callback);

    // Trigger a peripheral by invoking its callback
    void triggerPeripheral(uint8_t address, uint8_t value);

    // Access the ADC module
    ADC& getADC();

    // Access the USART module
    USART& getUSART();

    // Access a specific port by index
    Port& getPort(size_t index);

    // Access the JTAG interface
    JTAG& getJTAG();

    // Reset all peripherals
    void reset();

    // Access Port A
    Port& getPortA();

    // Access Timer
    Timer& getTimer(size_t index);

    // Access PWM Channel
    PWMChannel& getPWMChannel(size_t index);

    // Access SPI
    SPI& getSPI();

    // Configure I/O line mode
    void configureIOLine(size_t index, IOLineMode mode);
    size_t getPortCount() const; // Declare the function here
};

#endif // PERIPHERALS_H
