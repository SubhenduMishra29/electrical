# MCU Class Documentation

## Overview
The `MCU` class represents a microcontroller unit, managing its core operations, peripherals, and memory.

## Header File: `mcu.h`

### Includes
- `iostream`: Used for logging and error messages.
- `ADC.h`: Analog-to-Digital Converter module.
- `Timer.h`: Timer module for scheduling operations.
- `PWMChannel.h`: Pulse Width Modulation channel management.
- `USART.h`: Serial communication interface.
- `SPI.h`: Serial Peripheral Interface communication.
- `twi.h`: Two-Wire Interface (TWI/I2C) communication.
- `watchdogtimer.h`: Watchdog Timer module for system stability.
- `stdexcept`: Exception handling for errors.

## Class Members

### Private Attributes
- `memory`: Handles Flash, EEPROM, and SRAM memory operations.
- `peripherals`: Manages attached peripherals like ADC, USART, SPI, and timers.
- `cpu`: Represents the core processor of the MCU.
- `config`: Holds the MCU configuration settings.

### Public Methods

#### `MCU(const MCUConfig& config)`
Constructor initializes the MCU with specified configuration.

#### `void loadProgram(const std::vector<uint16_t>& program)`
Loads a program into Flash memory, checking for overflow.

#### `void configurePowerOnReset()`
Configures the power-on reset settings.

#### `void configureBrownOutDetection()`
Configures brown-out detection to prevent low-voltage operation issues.

#### `void configureInternalRC()`
Configures the internal RC oscillator for clock management.

#### `void configureInterruptSources()`
Sets up external and internal interrupt sources:
- External interrupts for event-driven processing.
- Timer interrupts for scheduling tasks.
- ADC, USART, and SPI interrupts if supported.

#### `void configureSleepModes()`
Configures sleep modes for power efficiency, including:
- Idle
- ADC Noise Reduction
- Power Save
- Power Down
- Standby
- Extended Standby

#### `void configureIOLines()`
Configures I/O lines based on port and pin configurations.
- Analog input for ADC-enabled lines.
- Bi-directional I/O for general-purpose pins.

#### `void configurePackageType(const std::string& packageType)`
Sets the MCU package type (e.g., DIP, QFP, BGA).

#### `void configurePeripherals()`
Initializes and configures attached peripherals:
- ADC (if available)
- USART (for serial communication)
- SPI (for high-speed communication)
- TWI/I2C (for device interfacing)
- Watchdog Timer (for stability monitoring)

#### `void reset()`
Resets the CPU and peripherals.

#### `void run()`
Runs the MCU simulation in a loop until halted.
- Includes a cycle counter to prevent infinite loops.

#### `Port& getPort(size_t index)`
Returns a reference to a port by index, ensuring validity.

#### `void configurePortA()`
Configures Port A pins for output mode.

#### `void configurePort(size_t portIndex, Peripherals::IOLineMode mode)`
Configures a specific port with the desired I/O mode.

#### `void provideInputToPins()`
Simulates input by setting specific pin states.

#### `void configurePorts()`
Configures all ports based on the MCU configuration.

## MCU Configuration Presets
The `MCUConfig::createPreset()` function initializes different MCU models with appropriate settings:

| MCU Model  | Clock Frequency | Ports | I/O Lines | ADC | USART | SPI | TWI | Watchdog Timer |
|------------|----------------|-------|-----------|-----|-------|-----|-----|---------------|
| ATmega16   | 16 MHz         | 4     | 32        | Yes | Yes   | Yes | Yes | Yes           |
| ATmega32   | 16 MHz         | 4     | 32        | Yes | Yes   | Yes | Yes | Yes           |
| ATtiny85   | 8 MHz          | 1     | 6         | Yes | No    | Yes | Yes | Yes           |
| ATtiny45   | 8 MHz          | 1     | 6         | Yes | No    | Yes | Yes | Yes           |

## Conclusion
The `MCU` class efficiently models a microcontroller by integrating memory, peripherals, and CPU execution cycles. This documentation provides a structured overview of its functionality and implementation.

