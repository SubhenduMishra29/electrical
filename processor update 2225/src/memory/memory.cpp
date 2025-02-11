#include "memory.h"
#include <iostream> // Add this include for std::cerr

// Define EEPROM control registers and bits for simulation
uint8_t EECR = 0;
size_t EEAR = 0;
uint8_t EEDR = 0;
const uint8_t EEWE = 1;
const uint8_t EERE = 2;
const uint8_t EEMWE = 3;

// Constructor to initialize memory
Memory::Memory() : flash(FLASH_SIZE, 0xFF), eeprom(EEPROM_SIZE, 0xFF), sram(SRAM_SIZE, 0x00) {
    // Initialize memory with default values
}

// Load a program into Flash memory
void Memory::loadProgram(const std::vector<uint16_t>& program) {
    if (program.size() * 2 > FLASH_SIZE) {
        std::cerr << "Error: Program size exceeds Flash memory limit.\n";
        return;
    }
    for (size_t i = 0; i < program.size(); ++i) {
        flash[i * 2] = program[i] & 0xFF; // Lower byte
        flash[i * 2 + 1] = (program[i] >> 8) & 0xFF; // Upper byte
    }
    std::cout << "Program loaded into Flash memory.\n";
}

// Read from Flash memory
uint8_t Memory::readFlash(size_t address) const {
    if (address < FLASH_SIZE) {
        return flash[address];
    } else {
        std::cerr << "Error: Invalid flash memory address: " << address << "\n";
        return 0;
    }
}

// Write to Flash memory (restricted at runtime)
void Memory::writeFlash(size_t address, uint8_t value) {
    std::cerr << "Error: Flash memory is read-only at runtime.\n";
}

// Read from EEPROM
uint8_t Memory::readEEPROM(size_t address) const {
    if (address < EEPROM_SIZE) {
        return eeprom[address];
    } else {
        std::cerr << "Error: Invalid EEPROM address: " << address << "\n";
        return 0;
    }
}

// Write to EEPROM
void Memory::writeEEPROM(size_t address, uint8_t value) {
    if (address < EEPROM_SIZE) {
        eeprom[address] = value;
    } else {
        std::cerr << "Error: Invalid EEPROM address: " << address << "\n";
    }
}

// Read from SRAM
uint8_t Memory::readSRAM(size_t address) const {
    if (address < SRAM_SIZE) {
        return sram[address];
    } else {
        std::cerr << "Error: Invalid SRAM memory address: " << address << "\n";
        return 0;
    }
}

// Write to SRAM
void Memory::writeSRAM(size_t address, uint8_t value) {
    if (address < SRAM_SIZE) {
        sram[address] = value;
    } else {
        std::cerr << "Error: Invalid SRAM memory address: " << address << "\n";
    }
}

// Reset the memory
void Memory::reset() {
    flash.assign(FLASH_SIZE, 0xFF); // Flash usually resets to 0xFF
    eeprom.assign(EEPROM_SIZE, 0xFF); // EEPROM resets to 0xFF
    sram.assign(SRAM_SIZE, 0x00); // SRAM resets to 0x00
    std::cout << "Memory reset to default values.\n";
}
