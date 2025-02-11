#include "mcu.h"
#include <iostream>
#include "ADC.h"
#include "Timer.h"
#include "../peripherals/PWMChannel.h" // Update this include directive
#include "USART.h"
#include "SPI.h"
#include "../twi/twi.h" // Include TWI/I2C header
#include "../watchdogtimer/watchdogtimer.h" // Include Watchdog Timer header
#include <stdexcept>

std::ostream& operator<<(std::ostream& os, const AVRCoreType& coreType) {
    switch (coreType) {
        case AVRCoreType::ATmega16: os << "ATmega16"; break;
        case AVRCoreType::ATtiny85: os << "ATtiny85"; break;
        case AVRCoreType::ATmega32: os << "ATmega32"; break;
        default: os << "Unknown"; break;
    }
    return os;
}

#define MICROPROCESSOR_TYPE "AVR"
#define CLOCK_FREQUENCY 16000000 // 16 MHz

template<typename T>
using has_reset_t = decltype(std::declval<T>().reset());

template<typename T, typename = void>
struct has_reset : std::false_type {};

template<typename T>
struct has_reset<T, std::void_t<has_reset_t<T>>> : std::true_type {};

template<typename T>
using has_init_t = decltype(std::declval<T>().init());

template<typename T, typename = void>
struct has_init : std::false_type {};

template<typename T>
struct has_init<T, std::void_t<has_init_t<T>>> : std::true_type {};

MCU::MCU(const MCUConfig& config) : memory(), peripherals(config.portCount), cpu(memory, peripherals), config(config) {
    std::cout << "Microprocessor Type: " << config.coreType << "\n";
    std::cout << "Clock Frequency: " << config.clockFrequency << " Hz\n";
}

void MCU::loadProgram(const std::vector<uint16_t>& program) {
    memory.loadProgram(program);
    std::cout << "Program loaded into memory.\n";
}

void MCU::configurePowerOnReset() {
    std::cout << "Power-on Reset configured.\n";
}

void MCU::configureBrownOutDetection() {
    std::cout << "Brown-out Detection configured.\n";
}

void MCU::configureInternalRC() {
    std::cout << "Internal Calibrated RC Oscillator configured.\n";
}

void MCU::configureInterruptSources() {
    std::cout << "Configuring External and Internal Interrupt Sources...\n";
    
    // Enable External Interrupts
    peripherals.enableExternalInterrupt(0, Peripherals::InterruptTrigger::RISING_EDGE);
    peripherals.enableExternalInterrupt(1, Peripherals::InterruptTrigger::FALLING_EDGE);
    
    // Enable Timer Interrupts
    peripherals.getTimer(0).enableInterrupt();
    peripherals.getTimer(1).enableInterrupt();
    
    // Enable ADC Interrupt (if ADC is available)
    if (config.hasADC) {
        peripherals.getADC().enableInterrupt();
    }
    
    // Enable USART Interrupt (if USART is available)
    if (config.hasUSART) {
        peripherals.getUSART().enableInterrupt();
    }
    
    // Enable SPI Interrupt (if SPI is available)
    if (config.hasSPI) {
        peripherals.getSPI().enableInterrupt();
    }
    
    std::cout << "External and Internal Interrupt Sources successfully configured.\n";
}

void MCU::configureSleepModes() {
    std::cout << "Configuring Sleep Modes...\n";
    
    // Enable different sleep modes based on MCU capabilities
    peripherals.enableSleepMode(Peripherals::SleepMode::IDLE);
    peripherals.enableSleepMode(Peripherals::SleepMode::ADC_NOISE_REDUCTION);
    peripherals.enableSleepMode(Peripherals::SleepMode::POWER_SAVE);
    peripherals.enableSleepMode(Peripherals::SleepMode::POWER_DOWN);
    peripherals.enableSleepMode(Peripherals::SleepMode::STANDBY);
    peripherals.enableSleepMode(Peripherals::SleepMode::EXTENDED_STANDBY);
    
    std::cout << "Sleep Modes successfully configured.\n";
}

void MCU::configureIOLines() {
    for (size_t i = 0; i < config.ioLineCount; ++i) { // Use config.ioLineCount
        size_t portIndex = i / Port::PIN_COUNT;
        size_t pinIndex = i % Port::PIN_COUNT;
        if (portIndex < peripherals.getPortCount()) {
            if (pinIndex < 8) {
                if (peripherals.getADC().isEnabled()) {
                    peripherals.configureIOLine(i, Peripherals::IOLineMode::Input); // Configure as analog inputs
                } else {
                    peripherals.configureIOLine(i, Peripherals::IOLineMode::Output); // Configure as bi-directional I/O
                }
            } else {
                peripherals.configureIOLine(i, Peripherals::IOLineMode::Input); // Configure as input for other ports
            }
        } else {
            std::cerr << "Error: Invalid port index: " << portIndex << "\n";
        }
    }
    std::cout << config.ioLineCount << " Programmable I/O Lines configured.\n";
}

void MCU::configurePackageType(const std::string& packageType) {
    std::cout << "Package type configured: " << packageType << ".\n";
}

void MCU::configurePeripherals() {
    std::cout << "--- Periferals  Configuration started---"<< "\n";
    peripherals.attachPeripheral(10, [](uint8_t value) {
        std::cout << "Peripheral at I/O Register 10 triggered with value: " << (int)value << "\n";
    });

    if (config.hasADC && has_init<ADC>::value) {
        peripherals.getADC().initialize(5.0, 1024);
    } else {
        std::cerr << "Error: ADC not available or does not have an initialize method.\n";
    }

    Timer timer1, timer2;
    timer1.configure(1, true);
    timer2.configure(2, false);

    PWMChannel pwm1, pwm2;
    pwm1.setDutyCycle(50);
    pwm2.setDutyCycle(75);

    if (config.hasUSART) {
        peripherals.getUSART().initialize(9600);
    } else {
        std::cerr << "Error: USART not available or not configured.\n";
    }

    if (config.hasSPI) {
        SPI spi;
        spi.configure(SPI::Mode::Master, SPI::ClockPolarity::High, SPI::ClockPhase::FirstEdge);
    } else {
        std::cerr << "Error: SPI not available or not configured.\n";
    }

    if (config.hasTWI) {
        TWI twi;
        twi.initialize(100000);
    } else {
        std::cerr << "Error: TWI not available or not configured.\n";
    }

    if (config.hasWatchdogTimer) {
        WatchdogTimer wdt;
        wdt.enable(WatchdogTimer::Timeout::Timeout_2s);
    } else {
        std::cerr << "Error: Watchdog Timer not available or not configured.\n";
    }

    configurePowerOnReset();
    configureBrownOutDetection();
    configureInternalRC();
    configureInterruptSources();
    configureSleepModes();
    configureIOLines();
    configurePackageType("40-pin PDIP");

    std::cout << "---Peripherals configured.---\n";
}

void MCU::reset() {
    cpu.reset();
    peripherals.reset();
    std::cout << "MCU reset.\n";
}

void MCU::run() {
    std::cout << "Starting MCU simulation.\n";
    size_t cycleCount = 0; // Add a cycle counter to prevent infinite loops
    while (!cpu.isHalted()) {
        cpu.runCycle();
        cycleCount++;
        if (cycleCount > 1000000) { // Arbitrary large number to prevent infinite loop
            std::cerr << "Error: Infinite loop detected in MCU simulation.\n";
            break;
        }
    }
    std::cout << "MCU simulation halted.\n";
}

Port& MCU::getPort(size_t index) {
    if (index >= peripherals.getPortCount()) {
        throw std::out_of_range("Invalid port index");
    }
    return peripherals.getPort(index);
}

void MCU::configurePortA() {
    std::cout << "---Port A Configuration started---"<< "\n";
    for (size_t i = 0; i < Port::PIN_COUNT; ++i) {
        if (i < Port::PIN_COUNT) {
            peripherals.configureIOLine(i, Peripherals::IOLineMode::Output);
            std::cout << "I/O Line " << i << " configured to Output mode.\n";
        } else {
            std::cerr << "Error: Invalid I/O line index: " << i << "\n";
        }
    }
}

void MCU::configurePort(size_t portIndex, Peripherals::IOLineMode mode) {
    if (portIndex < peripherals.getPortCount()) {
        for (size_t i = 0; i < Port::PIN_COUNT; ++i) {
            peripherals.configureIOLine(portIndex * Port::PIN_COUNT + i, mode);
        }
    } else {
        std::cerr << "Error: Invalid port index: " << portIndex << "\n";
    }
}

void MCU::provideInputToPins() {
    // Example configuration: Set specific pins to high or low based on simulation needs
    getPort(0).setPin(1, true);  // Set pin 1 of port 0 to high
    getPort(1).setPin(2, false); // Set pin 2 of port 1 to low
    // Add more pin configurations as needed for your simulation
    std::cout << "Input provided to pins.\n";
}

void MCU::configurePorts() {
    constexpr size_t PIN_COUNT = 8;  // Explicitly define pin count per port
    std::cout << "--- Port Configuration Started ---" << "\n";
    std::cout << "--- Total Ports: " << config.portCount << " ---" << "\n";

    for (size_t portIndex = 0; portIndex < config.portCount; ++portIndex) {
        Peripherals::IOLineMode mode = (portIndex == 0) ? Peripherals::IOLineMode::Output : Peripherals::IOLineMode::Input;
        configurePort(portIndex, mode);

        for (size_t pinIndex = 0; pinIndex < PIN_COUNT; ++pinIndex) {
            size_t ioLineIndex = portIndex * PIN_COUNT + pinIndex;

            if (ioLineIndex < config.ioLineCount) {
                getPort(portIndex).setPin(pinIndex, true);
                bool pinState = getPort(portIndex).getPin(pinIndex);
                std::cout << "Port " << portIndex << ", Pin " << pinIndex << " state: " << pinState << std::endl;
            } else {
                std::cerr << "Warning: Out-of-range I/O line index: " << ioLineIndex
                          << " (Port " << portIndex << ", Pin " << pinIndex << ")\n";
            }
        }
    }

    std::cout << "--- Port Configuration Completed ---" << "\n";
}


// In mcu.cpp
MCUConfig MCUConfig::createPreset(AVRCoreType coreType) {
    MCUConfig config;
    config.coreType = coreType;
    switch (coreType) {
        case AVRCoreType::ATmega16:
            config.clockFrequency = 16000000;
            config.portCount = 4; // Example port count for ATmega16
            config.ioLineCount = 32; // Example I/O line count for ATmega16
            config.hasADC = true;
            config.hasUSART = true;
            config.hasSPI = true;
            config.hasTWI = true;
            config.hasWatchdogTimer = true;
            config.hasGeneralPurposeRegisters = true;
            break;
        case AVRCoreType::ATmega32:
            config.clockFrequency = 16000000;
            config.portCount = 4; // Corrected port count for ATmega32
            config.ioLineCount = 32; // Corrected I/O line count for ATmega32
            config.hasADC = true;
            config.hasUSART = true;
            config.hasSPI = true;
            config.hasTWI = true;
            config.hasWatchdogTimer = true;
            config.hasGeneralPurposeRegisters = true;
            break;
        case AVRCoreType::ATtiny85:
            config.clockFrequency = 8000000;
            config.portCount = 1; // Corrected port count for ATtiny85
            config.ioLineCount = 6; // Corrected I/O line count for ATtiny85
            config.hasADC = true;
            config.hasUSART = false;
            config.hasSPI = true;
            config.hasTWI = true;
            config.hasWatchdogTimer = true;
            config.hasGeneralPurposeRegisters = true;
            break;
        case AVRCoreType::ATtiny45:
            config.clockFrequency = 8000000;
            config.portCount = 1; // Corrected port count for ATtiny45
            config.ioLineCount = 6; // Corrected I/O line count for ATtiny45
            config.hasADC = true;
            config.hasUSART = false;
            config.hasSPI = true;
            config.hasTWI = true;
            config.hasWatchdogTimer = true;
            config.hasGeneralPurposeRegisters = true;
            break;
        default:
            config.clockFrequency = 0;
            config.portCount = 0;
            config.ioLineCount = 0;
            config.hasADC = false;
            config.hasUSART = false;
            config.hasSPI = false;
            config.hasTWI = false;
            config.hasWatchdogTimer = false;
            config.hasGeneralPurposeRegisters = false;
            break;
    }
    return config;
}
