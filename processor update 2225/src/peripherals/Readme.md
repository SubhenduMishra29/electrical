# Peripherals Class Documentation

## Overview
The `Peripherals` class manages various microcontroller peripherals such as ADC, USART, SPI, JTAG, Timers, and Watchdog Timer. It provides methods to interact with and configure these peripherals.

## Header File: `Peripherals.h`

### Includes
The following libraries are included to provide necessary functionality:
- `ADC.h`: Analog-to-Digital Converter
- `USART.h`: Universal Synchronous/Asynchronous Receiver-Transmitter
- `port.h`: Port management
- `JTAG.h`: JTAG debugging interface
- `Timer.h`: Timer module
- `SPI.h`: Serial Peripheral Interface
- `PWMChannel.h`: Pulse Width Modulation channels
- `WatchdogTimer.h`: Watchdog Timer

## Enumerations

### `IOLineMode`
Defines the mode of an I/O line:
- `Input`: Configures the pin as an input
- `Output`: Configures the pin as an output

### `InterruptTrigger`
Defines the types of triggers for external interrupts:
- `RISING_EDGE`
- `FALLING_EDGE`
- `CHANGE`

### `SleepMode`
Defines the available sleep modes for power saving:
- `IDLE`
- `ADC_NOISE_REDUCTION`
- `POWER_SAVE`
- `POWER_DOWN`
- `STANDBY`
- `EXTENDED_STANDBY`

## Class Members

### Private Attributes
- `ioRegisters`: Storage for I/O registers.
- `peripheralCallbacks`: Callback functions for peripherals.
- `adc`: ADC module instance.
- `usart`: USART module instance.
- `ports`: Container for available ports.
- `jtag`: JTAG debugging instance.
- `timers`: Container for available timers.
- `pwmChannels`: Container for available PWM channels.
- `spi`: SPI module instance.
- `wdt`: Watchdog Timer instance.

### Public Methods

#### `Peripherals(size_t portCount)`
Constructor to initialize peripherals with a specified number of ports.

#### `uint8_t readIORegister(uint8_t address) const`
Reads a value from the specified I/O register.

#### `void writeIORegister(uint8_t address, uint8_t value)`
Writes a value to the specified I/O register.

#### `void attachPeripheral(uint8_t address, const std::function<void(uint8_t)>& callback)`
Attaches a callback function to a peripheral at a given I/O register address.

#### `void triggerPeripheral(uint8_t address, uint8_t value)`
Triggers a peripheral by executing its callback function with the provided value.

#### `ADC& getADC()`
Returns a reference to the ADC module.

#### `USART& getUSART()`
Returns a reference to the USART module.

#### `Port& getPort(size_t index)`
Returns a reference to the specified port.

#### `JTAG& getJTAG()`
Returns a reference to the JTAG debugging module.

#### `void reset()`
Resets all peripherals.

#### `Port& getPortA()`
Returns a reference to Port A.

#### `Timer& getTimer(size_t index)`
Returns a reference to the specified Timer.

#### `PWMChannel& getPWMChannel(size_t index)`
Returns a reference to the specified PWM channel.

#### `SPI& getSPI()`
Returns a reference to the SPI module.

#### `WatchdogTimer& getWatchdogTimer()`
Returns a reference to the Watchdog Timer module.

#### `void configureIOLine(size_t index, IOLineMode mode)`
Configures an I/O line mode (input or output).

#### `size_t getPortCount() const`
Returns the total number of ports available.

#### `void enableExternalInterrupt(int interruptNumber, InterruptTrigger trigger)`
Enables an external interrupt with the specified trigger type.

#### `void enableSleepMode(SleepMode mode)`
Enables the specified sleep mode for power management.

## Conclusion
The `Peripherals` class provides an organized way to manage and configure microcontroller peripherals efficiently. This documentation serves as a guide to understanding its functionality and implementation.

