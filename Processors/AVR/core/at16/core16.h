#ifndef CORE16_H
#define CORE16_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

constexpr uint8_t NUM_REGISTERS = 32;
constexpr uint16_t SRAM_SIZE = 1024;
constexpr uint16_t EEPROM_SIZE = 512;
constexpr uint16_t FLASH_SIZE = 4096; // Simulated flash memory size
constexpr uint8_t INVALID_OPCODE = 0xFF; // Invalid opcode for error handling
constexpr uint16_t USART_BUFFER_SIZE = 256; // Simulated USART buffer size
constexpr uint8_t PIN_LOAD_START = 0x01;  // Example pin to signal load start
constexpr uint8_t PIN_LOAD_DATA = 0x02;   // Example pin for loading data

// Define the ATmega16 core structure
class ATmega16_Core {
public:
    ATmega16_Core();

    // Core initialization
    void init();

    // USART-based bootloader to load program into Flash memory
    void load_program_via_usart();

    // Pin-based bootloader to load program into Flash memory
    void load_program_via_pins();

    // Simulate USART receiving data byte-by-byte
    void usart_receive(uint8_t data);

    // Simulate receiving data through pins
    void pin_receive(uint8_t data);

    // Run the simulation for a specified number of cycles
    void run(uint32_t cycles);

    // Execute a single instruction
    void execute_instruction();

    // Register-level functions
    void mov(uint8_t dest, uint8_t src);
    void add(uint8_t dest, uint8_t src);
    void sub(uint8_t dest, uint8_t src);
    void jmp(uint16_t address);
    void bit_set(uint8_t reg, uint8_t bit);
    void bit_clear(uint8_t reg, uint8_t bit);

    // Memory read/write functions
    uint8_t read_memory(uint16_t address);
    void write_memory(uint16_t address, uint8_t data);

    // EEPROM functions
    void write_eeprom(uint16_t address, uint8_t data);
    uint8_t read_eeprom(uint16_t address);

    // ADC-related functions
    void init_adc();
    uint16_t read_adc(uint8_t channel);

    // Timer and peripheral initialization
    void init_timer16();
    void start_timer16();
    void init_usart();
    void usart_send(uint8_t data);
    // Getter function to access a register value
    uint8_t getRegister(uint8_t index) const {
        if (index < NUM_REGISTERS) {
            return registers[index];
        }
        return 0; // Return 0 if out of bounds
    }

    // Setter function to modify a register value
    void setRegister(uint8_t index, uint8_t value) {
        if (index < NUM_REGISTERS) {
            registers[index] = value;
        }
    }

    // Debugging/Status functions
    void print_registers() const;

private:
    uint8_t fetch_opcode();
    uint8_t fetch_operand();

    // General-purpose registers, status, memory, and peripherals
    uint8_t registers[NUM_REGISTERS];
    uint16_t PC;                      // Program Counter
    uint8_t SRAM[SRAM_SIZE];          // Simulated SRAM
    uint8_t EEPROM[EEPROM_SIZE];      // Simulated EEPROM
    uint8_t Flash[FLASH_SIZE];        // Simulated Flash memory for program instructions
    uint8_t USART_Buffer[USART_BUFFER_SIZE]; // Simulated USART buffer for incoming data
    uint16_t USART_Buffer_Index;      // Index for incoming USART data

    // Instruction-related helpers
    bool is_running;

    // Helper functions to handle invalid memory access or instructions
    void handle_invalid_memory_access(const char* message);
    void handle_invalid_instruction(uint8_t opcode);

    // Helper function to write to flash from USART buffer
    void write_flash_from_usart_buffer();
    // Helper function to write to flash from pin input
    void write_flash_from_pin_data(uint8_t data);
};

#endif // CORE16_H
