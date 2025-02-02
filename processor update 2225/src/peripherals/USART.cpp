#include "USART.h"
#include <iostream>

USART::USART() : baudRate(9600), enabled(false) {}

void USART::initialize(uint32_t baud) {
    baudRate = baud;
    enabled = true;
    std::cout << "USART initialized with baud rate: " << baudRate << " bps.\n";
}

void USART::send(uint8_t data) {
    if (!enabled) {
        std::cerr << "Error: USART is not enabled.\n";
        return;
    }

    txBuffer.push(data);
    std::cout << "USART: Sent data -> " << (int)data << "\n";
}

uint8_t USART::receive() {
    if (!enabled) {
        std::cerr << "Error: USART is not enabled.\n";
        return 0;
    }

    if (!rxBuffer.empty()) {
        uint8_t data = rxBuffer.front();
        rxBuffer.pop();
        std::cout << "USART: Received data <- " << (int)data << "\n";
        return data;
    } else {
        std::cerr << "Error: No data available to receive.\n";
        return 0;
    }
}

void USART::simulateIncomingData(uint8_t data) {
    if (enabled) {
        rxBuffer.push(data);
        std::cout << "USART: Simulated incoming data -> " << (int)data << "\n";
    } else {
        std::cerr << "Error: USART is not enabled, cannot simulate incoming data.\n";
    }
}

void USART::disable() {
    enabled = false;
    std::cout << "USART disabled.\n";
}

bool USART::isEnabled() const {
    return enabled;
}

void USART::reset() {
    baudRate = 9600;
    enabled = false;
    std::queue<uint8_t> empty;
    std::swap(txBuffer, empty);
    std::swap(rxBuffer, empty);
    std::cout << "USART reset.\n";
}
