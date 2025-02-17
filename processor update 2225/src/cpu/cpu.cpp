#include "CPU.h"
#include "Memory.h" // Include the memory interface
#include "../peripherals/Peripherals.h" // Include peripherals interface
#include <bitset> // Include bitset for displaying status register


#define EEPROM_SIZE 512
#define EEPROM_ADDR_REG 0x3C // Example address for EEPROM Address Register
#define EEPROM_DATA_REG 0x3D // Example address for EEPROM Data Register
#define EEPROM_CTRL_REG 0x3E // Example address for EEPROM Control Register


// Define WDTCR as a pointer to a volatile uint8_t (assuming it's a memory-mapped register)
volatile uint8_t* WDTCR_ptr = reinterpret_cast<volatile uint8_t*>(0x60); // Example address for WDTCR

CPU::CPU(Memory& memory, Peripherals& peripherals)
    : programCounter(0), stackPointer(0x08FF), registers({0}), sreg(0), halted(false), memory(memory), peripherals(peripherals), nestedInterruptLevel(0), cycleCount(0) {
    interrupts.fill(nullptr); // Initialize interrupts to null
}

uint16_t CPU::fetchInstruction() {
    uint16_t instruction = memory.readFlash(programCounter) | (memory.readFlash(programCounter + 1) << 8);
    programCounter += 2; // Increment program counter by 2 bytes (16 bits)
    updateCycleCount(1); // Fetching an instruction takes 1 cycle
    return instruction;
}

void CPU::writeSPM(uint16_t addr, uint8_t data) {
    // Ensure this method is called from the Boot Program section
    if (programCounter >= BOOT_SECTION_START && programCounter < BOOT_SECTION_END) {
        memory.writeFlash(addr, data);
        updateCycleCount(4); // Writing to flash takes 4 cycles
        std::cout << "Executing SPM at Boot Program section\n";
    } else {
        std::cout << "Error: SPM instruction must reside in the Boot Program section\n";
    }
}

void CPU::updateFlags(uint16_t result, uint8_t op1, uint8_t op2) {
    sreg = 0; // Reset all flags
    if ((result & 0xFF) == 0) sreg |= (1 << 1); // Set Zero (Z) flag if result is 0
    if (result & 0x80) sreg |= (1 << 2); // Set Negative (N) flag if MSB is 1
    if (result > 0xFF) sreg |= (1 << 0); // Set Carry (C) flag if carry out
    if (((op1 & 0xF) + (op2 & 0xF)) > 0xF) sreg |= (1 << 3); // Set Half Carry (H) flag
    if (((op1 ^ op2 ^ result) & 0x80) && ((op1 ^ result) & 0x80)) sreg |= (1 << 3); // Set Overflow (V) flag
}

void CPU::reset() {
    programCounter = 0;
    stackPointer = 0x08FF;
    registers.fill(0);
    sreg = 0;
    halted = false;
    std::cout << "CPU Reset Completed\n";
    executeInstruction(0x940C); // Execute JMP instruction at Reset Vector
}

void CPU::powerOnReset() {
    // Implementation for Power-on Reset
    std::cout << "Power-on Reset triggered\n";
    reset();
}

void CPU::externalReset() {
    // Implementation for External Reset
    std::cout << "External Reset triggered\n";
    reset();
}

void CPU::watchdogReset() {
    // Implementation for Watchdog Reset
    std::cout << "Watchdog Reset triggered\n";
    reset();
}

void CPU::brownOutReset() {
    // Implementation for Brown-out Reset
    std::cout << "Brown-out Reset triggered\n";
    reset();
}

void CPU::jtagAVRReset() {
    // Implementation for JTAG AVR Reset
    std::cout << "JTAG AVR Reset triggered\n";
    reset();
}

void CPU::setInterrupt(uint8_t vector, std::function<void()> isr) {
    if (vector < interrupts.size()) {
        interrupts[vector] = isr;
    }
}

void CPU::triggerInterrupt(uint8_t vector) {
    if (vector < interrupts.size() && interrupts[vector]) {
        interrupts[vector]();
    }
}

bool CPU::isHalted() const {
    // Implement the logic to determine if the CPU is halted
    // For example, check a halted flag or a specific register value
    return halted; // Assuming `halted` is a boolean member variable
}

void CPU::runCycle() {
    if (!halted) {
        // Fetch the next instruction
        uint16_t instruction = fetchInstruction();
        std::cout << "Fetched instruction: 0x" << std::hex << instruction << std::dec << "\n";
        
        // Execute the fetched instruction
        executeInstruction(instruction);
        
        // Display the state after each cycle for debugging
        if (debugMode) {
            displayState();
        }
    }
}

void CPU::displayState() const {
    std::cout << "CPU State:\n";
    std::cout << "Program Counter: 0x" << std::hex << programCounter << std::dec << "\n";
    std::cout << "Stack Pointer: 0x" << std::hex << stackPointer << std::dec << "\n";
    std::cout << "Registers: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << "R" << i << "=0x" << std::hex << (int)registers[i] << std::dec << " ";
    }
    std::cout << "\nStatus Register: " << std::bitset<8>(static_cast<unsigned long>(sreg)) << "\n";
}

void CPU::setGlobalInterruptEnable() {
    sreg |= (1 << 7); // Set the I-bit
    std::cout << "Global Interrupt Enable set\n";
}

void CPU::clearGlobalInterruptEnable() {
    sreg &= ~(1 << 7); // Clear the I-bit
    std::cout << "Global Interrupt Enable cleared\n";
}

uint16_t CPU::getXRegister() const {
    return (registers[27] << 8) | registers[26];
}

void CPU::setXRegister(uint16_t value) {
    registers[26] = value & 0xFF;
    registers[27] = (value >> 8) & 0xFF;
}

uint16_t CPU::getYRegister() const {
    return (registers[29] << 8) | registers[28];
}

void CPU::setYRegister(uint16_t value) {
    registers[28] = value & 0xFF;
    registers[29] = (value >> 8) & 0xFF;
}

uint16_t CPU::getZRegister() const {
    return (registers[31] << 8) | registers[30];
}

void CPU::setZRegister(uint16_t value) {
    registers[30] = value & 0xFF;
    registers[31] = (value >> 8) & 0xFF;
}

uint16_t CPU::getXRegisterPostIncrement() {
    uint16_t value = getXRegister();
    setXRegister(value + 1);
    return value;
}

uint16_t CPU::getXRegisterPreDecrement() {
    uint16_t value = getXRegister() - 1;
    setXRegister(value);
    return value;
}

uint16_t CPU::getYRegisterPostIncrement() {
    uint16_t value = getYRegister();
    setYRegister(value + 1);
    return value;
}

uint16_t CPU::getYRegisterPreDecrement() {
    uint16_t value = getYRegister() - 1;
    setYRegister(value);
    return value;
}

uint16_t CPU::getZRegisterPostIncrement() {
    uint16_t value = getZRegister();
    setZRegister(value + 1);
    return value;
}

uint16_t CPU::getZRegisterPreDecrement() {
    uint16_t value = getZRegister() - 1;
    setZRegister(value);
    return value;
}

void CPU::push(uint8_t value) {
    memory.writeSRAM(stackPointer--, value);
    updateCycleCount(2); // Pushing to stack takes 2 cycles
    std::cout << "Pushed value: " << (int)value << " to stack\n";
}

uint8_t CPU::pop() {
    uint8_t value = memory.readSRAM(++stackPointer);
    updateCycleCount(2); // Popping from stack takes 2 cycles
    std::cout << "Popped value: " << (int)value << " from stack\n";
    return value;
}

void CPU::call(uint16_t address) {
    stackPointer -= 2;
    memory.writeSRAM(stackPointer, programCounter & 0xFF);
    memory.writeSRAM(stackPointer + 1, (programCounter >> 8) & 0xFF);
    programCounter = address;
    std::cout << "Called subroutine at address: " << address << "\n";
}

void CPU::ret() {
    programCounter = memory.readSRAM(stackPointer) | (memory.readSRAM(stackPointer + 1) << 8);
    stackPointer += 2;
    std::cout << "Returned from subroutine to address: " << programCounter << "\n";
}

void CPU::enableInterrupt(uint8_t vector) {
    if (vector < interrupts.size()) {
        sreg |= (1 << 7); // Set the I-bit to enable global interrupts
        std::cout << "Interrupt " << (int)vector << " enabled\n";
    } else {
        std::cerr << "Error: Invalid interrupt vector: " << (int)vector << "\n";
    }
}

void CPU::disableInterrupt(uint8_t vector) {
    if (vector < interrupts.size()) {
        sreg &= ~(1 << 7); // Clear the I-bit to disable global interrupts
        std::cout << "Interrupt " << (int)vector << " disabled\n";
    } else {
        std::cerr << "Error: Invalid interrupt vector: " << (int)vector << "\n";
    }
}

void CPU::handleIVSEL() {
    if (sreg & (1 << IVSEL)) {
        // Interrupt vectors are moved to the start of the Boot Flash section
        interruptVectorBase = BOOT_SECTION_START;
    } else {
        // Interrupt vectors are at the start of the Application section
        interruptVectorBase = 0;
    }
}

void CPU::pushState() {
    push(programCounter & 0xFF);
    push((programCounter >> 8) & 0xFF);
    push(sreg);
}

void CPU::popState() {
    sreg = pop();
    programCounter = pop() | (pop() << 8);
}

void CPU::handleInterrupt(uint8_t vector) {
    handleIVSEL(); // Adjust interrupt vector base address based on IVSEL
    if (vector < interrupts.size() && interrupts[vector]) {
        // Save the current state
        pushState();
        nestedInterruptLevel++;

        // Set the program counter to the interrupt vector address
        programCounter = interruptVectorBase + vector * 2;

        // Execute the interrupt service routine
        interrupts[vector]();

        // Restore the saved state
        nestedInterruptLevel--;
        popState();

        // Set the I-bit to re-enable global interrupts if no nested interrupts are pending
        if (nestedInterruptLevel == 0) {
            sreg |= (1 << 7);
        }
    } else {
        std::cerr << "Error: No interrupt service routine attached or invalid vector: " << (int)vector << "\n";
    }
}

// Set the CPU clock frequency
void CPU::setCPUClockFrequency(uint32_t frequency) {
    cpuClockFrequency = frequency;
}

// Get the CPU clock frequency
uint32_t CPU::getCPUClockFrequency() const {
    return cpuClockFrequency;
}

// Set the I/O clock frequency
void CPU::setIOClockFrequency(uint32_t frequency) {
    ioClockFrequency = frequency;
}

// Get the I/O clock frequency
uint32_t CPU::getIOClockFrequency() const {
    return ioClockFrequency;
}

// Set the Flash clock frequency
void CPU::setFlashClockFrequency(uint32_t frequency) {
    flashClockFrequency = frequency;
}

// Get the Flash clock frequency
uint32_t CPU::getFlashClockFrequency() const {
    return flashClockFrequency;
}

// Set the Asynchronous Timer clock frequency
void CPU::setAsyncTimerClockFrequency(uint32_t frequency) {
    asyncTimerClockFrequency = frequency;
}

// Get the Asynchronous Timer clock frequency
uint32_t CPU::getAsyncTimerClockFrequency() const {
    return asyncTimerClockFrequency;
}

// Set the ADC clock frequency
void CPU::setADCClockFrequency(uint32_t frequency) {
    adcClockFrequency = frequency;
}

// Get the ADC clock frequency
uint32_t CPU::getADCClockFrequency() const {
    return adcClockFrequency;
}

// Enable sleep mode
void CPU::enableSleepMode() {
    sleepModeEnabled = true;
}

// Disable sleep mode
void CPU::disableSleepMode() {
    sleepModeEnabled = false;
}

// Check if sleep mode is enabled
bool CPU::isSleepModeEnabled() const {
    return sleepModeEnabled;
}

void CPU::disableADC() {
    // Implementation to disable ADC
    std::cout << "ADC disabled\n";
}

void CPU::enableADC() {
    // Implementation to enable ADC
    std::cout << "ADC enabled\n";
}

void CPU::disableAnalogComparator() {
    // Implementation to disable Analog Comparator
    std::cout << "Analog Comparator disabled\n";
}

void CPU::enableAnalogComparator() {
    // Implementation to enable Analog Comparator
    std::cout << "Analog Comparator enabled\n";
}

void CPU::disableBrownOutDetector() {
    // Implementation to disable Brown-out Detector
    std::cout << "Brown-out Detector disabled\n";
}

void CPU::enableBrownOutDetector() {
    // Implementation to enable Brown-out Detector
    std::cout << "Brown-out Detector enabled\n";
}

void CPU::disableInternalVoltageReference() {
    // Implementation to disable Internal Voltage Reference
    std::cout << "Internal Voltage Reference disabled\n";
}

void CPU::enableInternalVoltageReference() {
    // Implementation to enable Internal Voltage Reference
    std::cout << "Internal Voltage Reference enabled\n";
}

void CPU::disableWatchdogTimer() {
    std::cout << "Watchdog Timer disabled\n";
    // Implementation to disable the Watchdog Timer
    // Write logical one to WDTOE and WDE
    *WDTCR_ptr |= (1 << WDTOE) | (1 << WDE);
    // Within the next four clock cycles, write a logic 0 to WDE
    *WDTCR_ptr &= ~(1 << WDE);
}

void CPU::enableWatchdogTimer() {
    std::cout << "Watchdog Timer enabled\n";
    // Implementation to enable the Watchdog Timer
}

void CPU::resetWatchdogTimer() {
    std::cout << "Watchdog Timer reset\n";
    // Implementation to reset the Watchdog Timer
}

void CPU::configurePortPinsForMinimumPower() {
    // Implementation to configure port pins for minimum power
    std::cout << "Port pins configured for minimum power\n";
}

void CPU::disableOCDENFuse() {
    // Implementation to disable OCDEN Fuse
    std::cout << "OCDEN Fuse disabled\n";
}

void CPU::disableJTAGENFuse() {
    // Implementation to disable JTAGEN Fuse
    std::cout << "JTAGEN Fuse disabled\n";
}

void CPU::writeJTDToMCUCSR() {
    // Implementation to write one to the JTD bit in MCUCSR
    std::cout << "JTD bit in MCUCSR set to 1\n";
}

void CPU::setClockSource(ClockSource source) {
    switch (source) {
        case ClockSource::INTERNAL_RC:
            // Implementation to switch to internal RC oscillator
            std::cout << "Switched to Internal RC Oscillator\n";
            break;
        case ClockSource::EXTERNAL_OSCILLATOR:
            // Implementation to switch to external oscillator
            std::cout << "Switched to External Oscillator\n";
            break;
    }
}

ClockSource CPU::getClockSource() const {
    // Implementation to get the current clock source
    // For demonstration, returning INTERNAL_RC
    return ClockSource::INTERNAL_RC;
}

void CPU::setTimerPrescaler(uint8_t timer, uint8_t prescaler) {
    // Implementation to set the prescaler for a specific timer
    std::cout << "Timer " << (int)timer << " prescaler set to " << (int)prescaler << "\n";
}

void CPU::setPeripheralPrescaler(uint8_t peripheral, uint8_t prescaler) {
    // Implementation to set the prescaler for a specific peripheral
    std::cout << "Peripheral " << (int)peripheral << " prescaler set to " << (int)prescaler << "\n";
}

void CPU::setSystemClockPrescaler(uint8_t prescaler) {
    // Implementation to set the prescaler for the system clock
    std::cout << "System clock prescaler set to " << (int)prescaler << "\n";
}

void CPU::updateCycleCount(uint8_t cycles) {
    cycleCount += cycles;
}

uint64_t CPU::getCycleCount() const {
    return cycleCount;
}

