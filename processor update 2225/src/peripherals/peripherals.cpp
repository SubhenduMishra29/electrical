#include "Peripherals.h"
#include <iostream>
#include "ADC.h"
#include "Timer.h"
#include "USART.h"
#include "SPI.h"
#include "JTAG.h" // Add this include for JTAG

Peripherals::Peripherals(size_t portCount) {
    ioRegisters.fill(0); // Initialize all I/O registers to 0
    peripheralCallbacks.fill(nullptr); // Initialize all peripheral callbacks to null
    ports.resize(portCount); // Initialize ports based on the specified count
    timers.resize(2); // Initialize two timers
    pwmChannels.resize(2); // Initialize two PWM channels
}

uint8_t Peripherals::readIORegister(uint8_t address) const {
    if (address < IO_REGISTER_COUNT) {
        return ioRegisters[address];
    } else {
        std::cerr << "Error: Invalid I/O register address: " << (int)address << "\n";
        return 0;
    }
}

void Peripherals::writeIORegister(uint8_t address, uint8_t value) {
    if (address < IO_REGISTER_COUNT) {
        ioRegisters[address] = value;
        std::cout << "I/O Register [" << (int)address << "] updated to " << (int)value << "\n";

        // Trigger any attached peripheral callback
        if (peripheralCallbacks[address]) {
            peripheralCallbacks[address](value);
        }
    } else {
        std::cerr << "Error: Invalid I/O register address: " << (int)address << "\n";
    }
}

void Peripherals::attachPeripheral(uint8_t address, const std::function<void(uint8_t)>& callback) {
    if (address < IO_REGISTER_COUNT) {
        peripheralCallbacks[address] = callback;
        std::cout << "Peripheral callback attached to I/O Register [" << (int)address << "]\n";
    } else {
        std::cerr << "Error: Invalid I/O register address for peripheral: " << (int)address << "\n";
    }
}

void Peripherals::triggerPeripheral(uint8_t address, uint8_t value) {
    if (address < IO_REGISTER_COUNT && peripheralCallbacks[address]) {
        peripheralCallbacks[address](value);
        std::cout << "Peripheral triggered at I/O Register [" << (int)address << "] with value " << (int)value << "\n";
    } else {
        std::cerr << "Error: No peripheral attached or invalid address: " << (int)address << "\n";
    }
}

Port& Peripherals::getPort(size_t index) {
    if (index < ports.size()) {
        return ports[index];
    } else {
        throw std::out_of_range("Invalid port index");
    }
}

size_t Peripherals::getPortCount() const {
    return ports.size();
}

ADC& Peripherals::getADC() {
    return adc;
}

USART& Peripherals::getUSART() {
    return usart;
}

JTAG& Peripherals::getJTAG() {
    return jtag;
}

Timer& Peripherals::getTimer(size_t index) {
    return timers.at(index);
}

PWMChannel& Peripherals::getPWMChannel(size_t index) {
    return pwmChannels.at(index);
}

SPI& Peripherals::getSPI() {
    return spi;
}

Port& Peripherals::getPortA() {
    return ports[0]; // Assuming Port A is the first port in the vector
}

void Peripherals::reset() {
    ioRegisters.fill(0);
    peripheralCallbacks.fill(nullptr);
    adc.reset();
    usart.reset();
    for (auto& port : ports) {
        port.reset();
    }
    jtag.reset();
    for (auto& timer : timers) {
        timer.reset();
    }
    for (auto& pwmChannel : pwmChannels) {
        pwmChannel.reset();
    }
    spi.reset();
    std::cout << "Peripherals reset.\n";
}

void Peripherals::configureIOLine(size_t index, IOLineMode mode) {
    if (index < ports.size()) {
        if (mode == IOLineMode::Input) {
            ports[index].setPin(index, false); // Set pin to low for input mode
        } else {
            ports[index].setPin(index, true); // Set pin to high for output mode
        }
        std::cout << "I/O Line " << index << " configured to " << (mode == IOLineMode::Input ? "Input" : "Output") << " mode.\n";
    } else {
        std::cerr << "Error: Invalid I/O line index: " << index << "\n";
    }
}
// In Peripherals.cpp
