#ifndef CPU_H
#define CPU_H

#include "../memory/memory.h"
#include "../peripherals/Peripherals.h"
#include <array>
#include <cstdint>
#include <functional>
#include <iostream>

// Define WDTCR, WDTOE, and WDE constants
#define WDTCR 0x60 // Example address for Watchdog Timer Control Register
#define WDTOE 4    // Example bit position for Watchdog Timer Turn-off Enable
#define WDE 3      // Example bit position for Watchdog Enable

// Define IVSEL constant
#define IVSEL 1 // Example bit position for Interrupt Vector Select

// Adjusted start address for boot section
#define BOOT_SECTION_START 0xF000 // Updated to fit within uint16_t range
#define BOOT_SECTION_END 0x1FFFF // Example end address for boot section

enum class ClockSource {
    INTERNAL_RC,
    EXTERNAL_OSCILLATOR
};

class CPU {
private:
    uint16_t programCounter; // 16-bit program counter
    uint16_t stackPointer;   // 16-bit stack pointer
    std::array<uint8_t, 32> registers; // 32 general-purpose registers (R0-R31)
    uint8_t sreg;            // Status register (Z, N, C, V, etc.)
    bool halted;             // HALT flag

    Memory& memory;          // Reference to memory module
    Peripherals& peripherals; // Reference to peripherals module

    std::array<std::function<void()>, 8> interrupts; // Interrupt vector

    bool debugMode = true;   // Debug mode for verbose output

    uint16_t eear; // EEPROM Address Register
    uint8_t eedr;  // EEPROM Data Register
    uint8_t eecr;  // EEPROM Control Register

    // Clock management
    uint32_t cpuClockFrequency; // CPU clock frequency in Hz
    uint32_t ioClockFrequency;  // I/O clock frequency in Hz
    uint32_t flashClockFrequency; // Flash clock frequency in Hz
    uint32_t asyncTimerClockFrequency; // Asynchronous Timer clock frequency in Hz
    uint32_t adcClockFrequency; // ADC clock frequency in Hz

    // Sleep mode management
    bool sleepModeEnabled;

    uint8_t nestedInterruptLevel; // Track the level of nested interrupts

    uint64_t cycleCount; // Track the number of cycles

    // Update CPU status flags
    void updateFlags(uint16_t result, uint8_t op1, uint8_t op2);

    void waitForEEPROMWriteCompletion();

    void handleIVSEL(); // Adjust interrupt vector base address based on IVSEL
    uint16_t interruptVectorBase; // Base address for interrupt vectors
    void pushState(); // Save the current state
    void popState(); // Restore the saved state

    void updateCycleCount(uint8_t cycles); // Update cycle count

public:
    // Constructor
    CPU(Memory& memory, Peripherals& peripherals);

    // Fetch the next instruction
    uint16_t fetchInstruction(); // Ensure this method is declared

    // Execute the fetched instruction
    void executeInstruction(uint16_t instruction); // Ensure this method is declared

    // Reset the CPU
    void reset();

    // Set an interrupt service routine (ISR)
    void setInterrupt(uint8_t vector, std::function<void()> isr);

    // Trigger an interrupt
    void triggerInterrupt(uint8_t vector);

    // Check if the CPU is halted
    bool isHalted() const; // Ensure this method is declared

    // Simulate a single clock cycle
    void runCycle();
    void displayState() const;
    void writeSPM(uint16_t addr, uint8_t data);
   // void executeALUOperation(uint8_t opcode, uint8_t Rd, uint8_t Rr, int8_t k);
    void setGlobalInterruptEnable();
    void clearGlobalInterruptEnable();

    void enableInterrupt(uint8_t vector);
    void disableInterrupt(uint8_t vector);
    void handleInterrupt(uint8_t vector);

    uint16_t getXRegister() const;
    void setXRegister(uint16_t value);
    uint16_t getYRegister() const;
    void setYRegister(uint16_t value);
    uint16_t getZRegister() const;
    void setZRegister(uint16_t value);

    uint16_t getXRegisterPostIncrement();
    uint16_t getXRegisterPreDecrement();
    uint16_t getYRegisterPostIncrement();
    uint16_t getYRegisterPreDecrement();
    uint16_t getZRegisterPostIncrement();
    uint16_t getZRegisterPreDecrement();

    void push(uint8_t value);
    uint8_t pop();
    void call(uint16_t address);
    void ret();

    // IN instruction: Read from I/O space
    uint8_t readIO(uint8_t address);

    // OUT instruction: Write to I/O space
    void writeIO(uint8_t address, uint8_t value);

    // SBI instruction: Set bit in I/O register
    void setBitIO(uint8_t address, uint8_t bit);

    // CBI instruction: Clear bit in I/O register
    void clearBitIO(uint8_t address, uint8_t bit);

    // SBIS instruction: Skip if bit in I/O register is set
    bool skipIfBitSetIO(uint8_t address, uint8_t bit);

    // SBIC instruction: Skip if bit in I/O register is clear
    bool skipIfBitClearIO(uint8_t address, uint8_t bit);

    // Set the CPU clock frequency
    void setCPUClockFrequency(uint32_t frequency);

    // Get the CPU clock frequency
    uint32_t getCPUClockFrequency() const;

    // Set the I/O clock frequency
    void setIOClockFrequency(uint32_t frequency);

    // Get the I/O clock frequency
    uint32_t getIOClockFrequency() const;

    // Set the Flash clock frequency
    void setFlashClockFrequency(uint32_t frequency);

    // Get the Flash clock frequency
    uint32_t getFlashClockFrequency() const;

    // Set the Asynchronous Timer clock frequency
    void setAsyncTimerClockFrequency(uint32_t frequency);

    // Get the Asynchronous Timer clock frequency
    uint32_t getAsyncTimerClockFrequency() const;

    // Set the ADC clock frequency
    void setADCClockFrequency(uint32_t frequency);

    // Get the ADC clock frequency
    uint32_t getADCClockFrequency() const;

    // Enable sleep mode
    void enableSleepMode();

    // Disable sleep mode
    void disableSleepMode();

    // Check if sleep mode is enabled
    bool isSleepModeEnabled() const;

    // Power management methods
    void disableADC();
    void enableADC();
    void disableAnalogComparator();
    void enableAnalogComparator();
    void disableBrownOutDetector();
    void enableBrownOutDetector();
    void disableInternalVoltageReference();
    void enableInternalVoltageReference();
    void disableWatchdogTimer();
    void enableWatchdogTimer();
    void resetWatchdogTimer();
    void configurePortPinsForMinimumPower();

    // Reset methods
    void powerOnReset();
    void externalReset();
    void watchdogReset();
    void brownOutReset();
    void jtagAVRReset();

    // Fuse methods
    void disableOCDENFuse();
    void disableJTAGENFuse();
    void writeJTDToMCUCSR();

    void setClockSource(ClockSource source);
    ClockSource getClockSource() const;

    void setTimerPrescaler(uint8_t timer, uint8_t prescaler);
    void setPeripheralPrescaler(uint8_t peripheral, uint8_t prescaler);
    void setSystemClockPrescaler(uint8_t prescaler);

    uint64_t getCycleCount() const; // Get the current cycle count

    uint16_t extractOpcode(uint16_t instruction);
    void executeMemoryOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, uint16_t addr);
    void executeBranchOperation(uint16_t opcode, int16_t k);
    void executeALUOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, int8_t k);

};

#endif // CPU_H
