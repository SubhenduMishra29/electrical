#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <iostream>
#include <cstdint>  // For uint8_t
#include <array>    // Ensure std::array is properly included

/*  The memory here is fixed, but we are designing for various types of microprocessors.
    It should be dynamically declared in MCU.h in config if needed.
*/
class Memory {
private:
    static const size_t FLASH_SIZE = 16384; // 16 KB Flash
    static const size_t EEPROM_SIZE = 512;  // 512 Bytes EEPROM
    static const size_t SRAM_SIZE = 1024;   // 1 KB SRAM
    static const size_t IO_SIZE = 256;      // 256 Bytes I/O Memory

    std::vector<uint8_t> flash;  // Flash memory
    std::vector<uint8_t> eeprom; // EEPROM memory
    std::vector<uint8_t> sram;   // SRAM memory
    std::array<uint8_t, IO_SIZE> ioMemory; // Fixed-size I/O memory

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

    // Read/Write from I/O Memory
    void writeIO(uint8_t address, uint8_t value);
    uint8_t readIO(uint8_t address);
    // Reset the memory
    void reset();
};

#endif // MEMORY_H
