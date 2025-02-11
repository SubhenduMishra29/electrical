#include "memory.h"
#include <iostream> // For std::cerr

// Define EEPROM control registers and bits for simulation
uint8_t EECR = 0;
size_t EEAR = 0;
uint8_t EEDR = 0;
const uint8_t EEWE = 1;
const uint8_t EERE = 2;
const uint8_t EEMWE = 3;

// Constructor to initialize memory
Memory::Memory() 
    : flash(FLASH_SIZE, 0xFF), 
      eeprom(EEPROM_SIZE, 0xFF), 
      sram(SRAM_SIZE, 0x00),
      ioMemory{} // Ensure I/O memory is zero-initialized
{
}

// Load a program into Flash memory
void Memory::loadProgram(const std::vector<uint16_t>& program) {
    if (program.size() * 2 > FLASH_SIZE) {
        std::cerr << "Error: Program size exceeds Flash memory limit.\n";
        return;
    }
    for (size_t i = 0; i < program.size(); ++i) {
        flash[i * 2] = program[i] & 0xFF;           // Lower byte
        flash[i * 2 + 1] = (program[i] >> 8) & 0xFF; // Upper byte
    }
    std::cout << "Program loaded into Flash memory.\n";
}

// Read from Flash memory
uint8_t Memory::readFlash(size_t address) const {
    if (address < FLASH_SIZE) {
        return flash[address];
    }
    std::cerr << "Error: Invalid flash memory address: " << address << "\n";
    return 0;
}

// Write to Flash memory (restricted at runtime unless special condition is met)
void Memory::writeFlash(size_t address, uint8_t value) {
    static bool flashWritable = false; // Simulated flag to allow self-programming

    if (flashWritable && address < FLASH_SIZE) {
        flash[address] = value;
    } else {
        std::cerr << "Error: Flash memory is read-only at runtime.\n";
    }
}

// Read from EEPROM
uint8_t Memory::readEEPROM(size_t address) const {
    if (address < EEPROM_SIZE) {
        return eeprom[address];
    }
    std::cerr << "Error: Invalid EEPROM address: " << address << "\n";
    return 0;
}

// Write to EEPROM (Simulated EEPROM write delay)
void Memory::writeEEPROM(size_t address, uint8_t value) {
    if (address < EEPROM_SIZE) {
        waitForEEPROMWriteCompletion();
        eeprom[address] = value;
    } else {
        std::cerr << "Error: Invalid EEPROM address: " << address << "\n";
    }
}

// Simulate EEPROM write delay
void Memory::waitForEEPROMWriteCompletion() const {
    // Simulate EEPROM write delay (as EEPROM writes take several clock cycles)
    for (volatile int i = 0; i < 1000; ++i) {} 
}

// Read from SRAM
uint8_t Memory::readSRAM(size_t address) const {
    if (address < SRAM_SIZE) {
        return sram[address];
    }
    std::cerr << "Error: Invalid SRAM memory address: " << address << "\n";
    return 0;
}

// Write to SRAM
void Memory::writeSRAM(size_t address, uint8_t value) {
    if (address < SRAM_SIZE) {
        sram[address] = value;
    } else {
        std::cerr << "Error: Invalid SRAM memory address: " << address << "\n";
    }
}

// Read from I/O memory with bounds check
uint8_t Memory::readIO(uint8_t address) {
    if (address < ioMemory.size()) {
        return ioMemory[address];
    }
    std::cerr << "Error: Invalid I/O memory address: " << static_cast<int>(address) << "\n";
    return 0;
}

// Write to I/O memory with bounds check
void Memory::writeIO(uint8_t address, uint8_t value) {
    if (address < ioMemory.size()) {
        ioMemory[address] = value;
    } else {
        std::cerr << "Error: Invalid I/O memory address: " << static_cast<int>(address) << "\n";
    }
}

// Reset the memory
void Memory::reset() {
    flash.assign(FLASH_SIZE, 0xFF); // Flash resets to 0xFF
    eeprom.assign(EEPROM_SIZE, 0xFF); // EEPROM resets to 0xFF
    sram.assign(SRAM_SIZE, 0x00); // SRAM resets to 0x00
    ioMemory.fill(0); // Reset I/O memory to 0
    std::cout << "Memory reset to default values.\n";
}
