#ifndef ADC_H
#define ADC_H

#include <cstdint>

class ADC {
private:
    uint16_t adcValue;       // Current ADC value
    float referenceVoltage;  // Reference voltage for ADC
    uint16_t resolution;     // Resolution of the ADC

    static const uint8_t ADC_CHANNEL_COUNT = 8; // Number of ADC channels

    // Simulate an analog input for a given channel
    uint16_t simulateAnalogInput(uint8_t channel) const;

public:
    bool enabled;            // Flag to indicate if ADC is enabled

    // Constructor
    ADC();

    // Initialize the ADC with reference voltage and resolution
    void initialize(float refVoltage, uint16_t res);

    // Start ADC conversion on a specific channel
    void startConversion(uint8_t channel);

    // Read the latest ADC value
    uint16_t readValue() const;

    // Get the corresponding voltage for the ADC value
    float getVoltage() const;

    // Disable the ADC
    void disable();

    // Reset the ADC
    void reset();

    // Check if ADC is enabled
    bool isEnabled() const {
        return enabled;
    }

    // Get the number of ADC channels
    uint8_t getChannelCount() const {
        return ADC_CHANNEL_COUNT;
    }

    // Configure Port C as an 8-bit bi-directional I/O port with internal pull-up resistors
    void configurePortC();
};

#endif // ADC_H
