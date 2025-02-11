# Memory Class Documentation

## Overview
The `Memory` class handles Flash, EEPROM, and SRAM memory management for a microcontroller. It provides functions to read, write, and reset these memory types.

## Header File: `memory.h`

### Includes
- `iostream`: For error logging and debugging output.
- `vector`: Used for memory storage.

## Memory Components
- **Flash Memory**: Stores program code, read-only at runtime.
- **EEPROM**: Stores non-volatile data, readable and writable.
- **SRAM**: Stores runtime data, readable and writable.

## Registers and Constants
- `EECR`: EEPROM Control Register.
- `EEAR`: EEPROM Address Register.
- `EEDR`: EEPROM Data Register.
- `EEWE`: EEPROM Write Enable bit.
- `EERE`: EEPROM Read Enable bit.
- `EEMWE`: EEPROM Master Write Enable bit.

## Class Members

### Private Attributes
- `flash`: Stores Flash memory data.
- `eeprom`: Stores EEPROM memory data.
- `sram`: Stores SRAM memory data.

### Public Methods

#### `Memory()`
Constructor initializes memory with default values.

#### `void loadProgram(const std::vector<uint16_t>& program)`
Loads a program into Flash memory.
- Checks for memory overflow before writing.
- Stores the lower and upper bytes separately.

#### `uint8_t readFlash(size_t address) const`
Reads a byte from Flash memory.
- Returns an error if the address is out of bounds.

#### `void writeFlash(size_t address, uint8_t value)`
Writes to Flash memory (restricted at runtime).
- Displays an error message since Flash is read-only.

#### `uint8_t readEEPROM(size_t address) const`
Reads a byte from EEPROM.
- Returns an error if the address is invalid.

#### `void writeEEPROM(size_t address, uint8_t value)`
Writes a byte to EEPROM.
- Checks for valid address before writing.

#### `uint8_t readSRAM(size_t address) const`
Reads a byte from SRAM.
- Returns an error if the address is invalid.

#### `void writeSRAM(size_t address, uint8_t value)`
Writes a byte to SRAM.
- Checks for valid address before writing.

#### `void reset()`
Resets memory to default values.
- Flash and EEPROM reset to `0xFF`.
- SRAM resets to `0x00`.

## Conclusion
The `Memory` class provides structured access to microcontroller memory, ensuring safe read/write operations while handling errors appropriately.

