#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>
#include <iostream>

class Memory {
private:
    static const size_t FLASH_SIZE = 16384; // 16 KB Flash
    static const size_t EEPROM_SIZE = 512;  // 512 Bytes EEPROM
    static const size_t SRAM_SIZE = 1024;   // 1 KB SRAM

    std::vector<uint8_t> flash;  // Flash memory
    std::vector<uint8_t> eeprom; // EEPROM memory
    std::vector<uint8_t> sram;   // SRAM memory

    void waitForEEPROMWriteCompletion() const;

public:
    // Constructor
    Memory();

    // Load a program into Flash memory
    void loadProgram(const std::vector<uint16_t>& program);

    // Read from Flash memory
    uint8_t readFlash(size_t address) const;

    // Write to Flash memory
    void writeFlash(size_t address, uint8_t value);

    // Read from EEPROM
    uint8_t readEEPROM(size_t address) const;

    // Write to EEPROM
    void writeEEPROM(size_t address, uint8_t value);

    // Read from SRAM
    uint8_t readSRAM(size_t address) const;

    // Write to SRAM
    void writeSRAM(size_t address, uint8_t value);

    // Reset the memory
    void reset();
};

#endif // MEMORY_H
