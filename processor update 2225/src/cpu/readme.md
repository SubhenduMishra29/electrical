# CPU Class Documentation

## Overview
The `CPU` class represents the core processing unit of a microcontroller, managing execution cycles, memory, and peripherals.

## Header File: `CPU.h`

### Includes
- `Memory.h`: Handles Flash, EEPROM, and SRAM memory operations.
- `Peripherals.h`: Manages connected peripherals.
- `bitset`: Provides bit manipulation for the status register.

## Memory-Mapped Registers
- `EEPROM_SIZE`: Defines the EEPROM memory size.
- `EEPROM_ADDR_REG`, `EEPROM_DATA_REG`, `EEPROM_CTRL_REG`: Example addresses for EEPROM registers.
- `WDTCR_ptr`: Pointer to the Watchdog Timer Control Register (WDTCR).

## Class Members

### Private Attributes
- `programCounter`: Stores the current execution address.
- `stackPointer`: Points to the current stack position.
- `registers`: General-purpose registers (32 registers).
- `sreg`: Status register.
- `halted`: Boolean flag indicating if the CPU is halted.
- `memory`: Reference to memory handling unit.
- `peripherals`: Reference to peripheral management unit.
- `nestedInterruptLevel`: Tracks nested interrupts.
- `cycleCount`: Stores total execution cycles.
- `interrupts`: Stores interrupt vectors.

### Public Methods

#### `CPU(Memory& memory, Peripherals& peripherals)`
Constructor initializes CPU state, memory, and peripherals.

#### `uint16_t fetchInstruction()`
Fetches the next instruction from Flash memory and updates the program counter.

#### `void writeSPM(uint16_t addr, uint8_t data)`
Writes to Flash memory but only within the Boot Program section.

#### `void updateFlags(uint16_t result, uint8_t op1, uint8_t op2)`
Updates the status register (SREG) based on the operation result.

#### `void reset()`
Resets the CPU state, registers, and stack pointer.

#### `void powerOnReset()`, `void externalReset()`, `void watchdogReset()`, `void brownOutReset()`, `void jtagAVRReset()`
Trigger different types of CPU resets.

#### `void setInterrupt(uint8_t vector, std::function<void()> isr)`
Assigns an interrupt service routine (ISR) to a specific vector.

#### `void triggerInterrupt(uint8_t vector)`
Triggers an ISR if it is set.

#### `bool isHalted() const`
Checks if the CPU is halted.

#### `void runCycle()`
Executes a single instruction cycle, fetching and executing the next instruction.

#### `void displayState() const`
Prints the current CPU state, including registers and status flags.

#### `void setGlobalInterruptEnable()`, `void clearGlobalInterruptEnable()`
Enables or disables global interrupts.

#### Register Handling Methods
- `getXRegister()`, `setXRegister(uint16_t value)`
- `getYRegister()`, `setYRegister(uint16_t value)`
- `getZRegister()`, `setZRegister(uint16_t value)`
- `getXRegisterPostIncrement()`, `getXRegisterPreDecrement()`
- `getYRegisterPostIncrement()`, `getYRegisterPreDecrement()`
- `getZRegisterPostIncrement()`, `getZRegisterPreDecrement()`

#### Stack Operations
- `void push(uint8_t value)`, `uint8_t pop()`

#### Subroutine Handling
- `void call(uint16_t address)`, `void ret()`

#### Interrupt Handling
- `void enableInterrupt(uint8_t vector)`, `void disableInterrupt(uint8_t vector)`
- `void handleIVSEL()`, `void pushState()`, `void popState()`
- `void handleInterrupt(uint8_t vector)`

#### Clock Management
- `setCPUClockFrequency(uint32_t frequency)`, `getCPUClockFrequency() const`
- `setIOClockFrequency(uint32_t frequency)`, `getIOClockFrequency() const`
- `setFlashClockFrequency(uint32_t frequency)`, `getFlashClockFrequency() const`
- `setAsyncTimerClockFrequency(uint32_t frequency)`, `getAsyncTimerClockFrequency() const`
- `setADCClockFrequency(uint32_t frequency)`, `getADCClockFrequency() const`

#### Sleep Mode
- `enableSleepMode()`, `disableSleepMode()`, `isSleepModeEnabled() const`

#### Power Management
- `disableADC()`, `enableADC()`
- `disableAnalogComparator()`, `enableAnalogComparator()`
- `disableBrownOutDetector()`, `enableBrownOutDetector()`
- `disableInternalVoltageReference()`, `enableInternalVoltageReference()`
- `disableWatchdogTimer()`, `enableWatchdogTimer()`, `resetWatchdogTimer()`
- `configurePortPinsForMinimumPower()`
- `disableOCDENFuse()`, `disableJTAGENFuse()`
- `writeJTDToMCUCSR()`

#### Clock Source and Prescaler
- `setClockSource(ClockSource source)`, `ClockSource getClockSource() const`
- `setTimerPrescaler(uint8_t timer, uint8_t prescaler)`
- `setPeripheralPrescaler(uint8_t peripheral, uint8_t prescaler)`
- `setSystemClockPrescaler(uint8_t prescaler)`

#### Execution Cycle Tracking
- `updateCycleCount(uint8_t cycles)`, `uint64_t getCycleCount() const`

## Conclusion
The `CPU` class models an AVR microcontroller's core operations, including memory interaction, instruction execution, interrupts, and power management.
# CPU Instruction Execution Documentation

## Overview
The `CPU` class processes and executes instructions using arithmetic, memory, and branching operations. This documentation provides details on how these operations are handled.

## Header File: `CPU.h`

### Includes
- `iostream`: Provides logging and debugging output.

## Instruction Processing

### `extractOpcode(uint16_t instruction)`
Extracts the opcode from the instruction.
- Handles special cases like `LDS`, `STS`, and `RJMP`.
- Returns the appropriate opcode for execution.

### Arithmetic and Logic Operations

#### `executeALUOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, int8_t k)`
Handles arithmetic and logic operations based on the opcode:
- **Addition (`ADD`)**
- **Subtraction (`SUB`, `SBC`, `SBCI`, `SUBI`)**
- **Multiplication (`MUL`)**
- **Bitwise (`AND`, `OR`, `XOR`, `COM`)**
- **Shifting (`LSL`, `LSR`, `ASR`, `ROL`, `ROR`)**
- **Increment/Decrement (`INC`, `DEC`)**
- **Comparison (`CPI`, `TST`)**

### Memory Operations

#### `executeMemoryOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, uint16_t addr)`
Handles memory read and write operations:
- **Load (`LDS`, `IN`, `LPM`, `ELPM`)**
- **Store (`STS`, `OUT`, `SPM`)**
- **Stack Operations (`PUSH`, `POP`)**

### Branching Operations

#### `executeBranchOperation(uint16_t opcode, int16_t k)`
Handles control flow based on status register flags:
- **Unconditional Jump (`RJMP`)**
- **Call/Return (`RCALL`)**
- **Branching on Status (`BRMI`, `BRPL`, `BRVC`, `BRVS`, `BRNE`, `BREQ`, `BRSH`, `BRLO`)**

### `executeInstruction(uint16_t instruction)`
Decodes and executes an instruction by calling the appropriate execution function based on the opcode:
1. Extracts the opcode.
2. Decodes register operands and immediate values.
3. Determines execution category:
   - ALU operations
   - Memory operations
   - Branching operations
   - Halt (`0xFFFF` stops execution)

## Conclusion
This document provides an in-depth overview of how the `CPU` class processes and executes different instructions using modular execution functions. The class ensures structured and efficient execution of AVR-like instruction sets.


