#ifndef MCU_H
#define MCU_H

#include "../memory/memory.h"
#include "../peripherals/peripherals.h"
#include "../cpu/cpu.h"
#include "../twi/TWI.h" // Include TWI/I2C header
#include "../watchdogtimer/WatchdogTimer.h" // Include Watchdog Timer header
#include "../communication/SerialCommunication.h" // Include Serial Communication header
#include <vector>
#include <string>

// Enum to define AVR core types
enum class AVRCoreType {
    ATmega16,
    ATmega32,
    ATtiny85,
    ATtiny45
    // Add more cores as needed
};
/*  the core is declared but the menory type is still staic which will cause problems wihile loading the MCU
    this section has to be rechecked and updated. 
*/
struct MCUConfig {
    AVRCoreType coreType;
    uint32_t clockFrequency;
    size_t ramSize;    // RAM size
    size_t flashSize;  // Flash size
    size_t eepromSize; // EEPROM size
    size_t portCount;
    size_t ioLineCount;
    bool hasADC;
    bool hasUSART;
    bool hasSPI;
    bool hasTWI;
    bool hasWatchdogTimer;
    bool hasGeneralPurposeRegisters;

    // Factory method for presets
    static MCUConfig createPreset(AVRCoreType coreType);
};


class MCU {
private:
    Memory memory;         // Memory module
    Peripherals peripherals; // Peripherals module
    CPU cpu;               // CPU module
    TWI twi;               // TWI/I2C module
    WatchdogTimer wdt;     // Watchdog Timer module
    SerialCommunication serialComm; // Serial Communication module
    MCUConfig config;      // MCU configuration

public:
    // Constructor
    MCU(const MCUConfig& config);

    // Load a program into the MCU's memory
    void loadProgram(const std::vector<uint16_t>& program);

    // Configure peripherals for the MCU
    void configurePeripherals();

    // Run the MCU simulation
    void run();

    // Reset the MCU
    void reset();

    void configurePowerOnReset();
    void configureBrownOutDetection();
    void configureInternalRC();
    void configureInterruptSources();
    void configureSleepModes();
    void configureIOLines();
    void configurePackageType(const std::string& packageType);

    // Provide input to pins
    void provideInputToPins();

    // Access a specific port by index
    Port& getPort(size_t index);

    // Configure Port A for I/O
    void configurePortA();

    // Configure a specific port for I/O
    void configurePort(size_t portIndex, Peripherals::IOLineMode mode);

    void configurePorts(); // Ensure this method is declared
};

#endif // MCU_H
