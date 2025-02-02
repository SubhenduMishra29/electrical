#include "ADC.h"
#include <iostream>

ADC::ADC() : adcValue(0), referenceVoltage(5.0), resolution(1024), enabled(false) {}

// ...existing code...

void ADC::initialize(float refVoltage, uint16_t res) {
    referenceVoltage = refVoltage;
    resolution = res;
    enabled = true;
    std::cout << "ADC initialized with reference voltage: " << referenceVoltage
              << "V and resolution: " << resolution << " steps.\n";
}

void ADC::startConversion(uint8_t channel) {
    if (!enabled) {
        std::cerr << "Error: ADC is not enabled.\n";
        return;
    }

    if (channel >= ADC_CHANNEL_COUNT) {
        std::cerr << "Error: Invalid ADC channel: " << (int)channel << "\n";
        return;
    }

    // Simulate an ADC conversion process
    std::cout << "Starting ADC conversion on channel: " << (int)channel << "\n";
    adcValue = simulateAnalogInput(channel);
}

// ...existing code...

uint16_t ADC::readValue() const {
    if (!enabled) {
        std::cerr << "Error: ADC is not enabled.\n";
        return 0;
    }

    return adcValue;
}

float ADC::getVoltage() const {
    if (!enabled) {
        std::cerr << "Error: ADC is not enabled.\n";
        return 0.0f;
    }

    return (adcValue * referenceVoltage) / (resolution - 1);
}

// ...existing code...

void ADC::disable() {
    enabled = false;
    std::cout << "ADC disabled.\n";
}

void ADC::reset() {
    adcValue = 0;
    enabled = false;
    std::cout << "ADC reset.\n";
}

uint16_t ADC::simulateAnalogInput(uint8_t channel) const {
    // Simulate analog input for the specified channel
    return (channel * 100) % resolution; // Example simulation logic
}
