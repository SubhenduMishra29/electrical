#ifndef USART_H
#define USART_H

#include <queue>
#include <cstdint>

class USART {
private:
    uint32_t baudRate;             // Baud rate for communication
    bool enabled;                  // Flag to check if USART is enabled
    std::queue<uint8_t> txBuffer;  // Transmission buffer
    std::queue<uint8_t> rxBuffer;  // Reception buffer

public:
    // Constructor
    USART();

    // Initialize the USART with a specific baud rate
    void initialize(uint32_t baud);

    // Send a byte of data
    void send(uint8_t data);

    // Receive a byte of data
    uint8_t receive();

    // Simulate incoming data for testing purposes
    void simulateIncomingData(uint8_t data);

    // Disable the USART module
    void disable();

    // Check if USART is enabled
    bool isEnabled() const;

    // Reset the USART module
    void reset();
};

#endif // USART_H
