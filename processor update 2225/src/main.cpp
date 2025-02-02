#include "../cpu/cpu.h"
#include "../memory/memory.h"
#include "../peripherals/peripherals.h"
#include "../mcu/mcu.h"
#include <iostream>

void simulateMCU(const MCUConfig& config) {
    Memory memory;
    Peripherals peripherals(config.portCount);
    CPU cpu(memory, peripherals);
    MCU mcu(config);

    std::vector<uint16_t> program = {
        0x0000, // NOP
        0x1101, // ADD R1, R1
        0x1202, // ADC R2, R1
        0x0f03, // LDI R3, 0x0F
        0x1303, // SUB R3, R1
        0x1404, // LOAD R4 from SRAM[4]
        0x1505, // STORE R5 to SRAM[5]
        0x1606, // MOV R6, R0
        0x8000  // HALT (Terminate simulation)
    };

    mcu.loadProgram(program);
    mcu.configurePeripherals();

    // Ensure portCount is valid
    if (config.portCount > 0) {
        mcu.configurePorts(); // Use the new method
    } else {
        std::cerr << "Invalid port count: " << config.portCount << std::endl;
    }

    // Provide input to pins before running the simulation
    mcu.provideInputToPins();

    // Run the MCU simulation with cycle count limitation
    const int maxCycles = 1000000; // Set a limit for the number of cycles
    mcu.run();
    cpu.displayState(); // Ensure this is called after running the simulation
    mcu.reset();
}

int main() {
    // Simulate MCU for ATmega16
    MCUConfig atmega16Config = MCUConfig::createPreset(AVRCoreType::ATmega16);
    std::cout<<"--------------------------"<<"\n";
    //std::cout << "Microprocessor Type: " << atmega16Config.coreType << "\n";
    std::cout<<"--------------------------"<<"\n";
    simulateMCU(atmega16Config);

    // Simulate MCU for ATtiny85
    //MCUConfig attinyConfig = MCUConfig::createPreset(AVRCoreType::ATtiny85);
    //simulateMCU(attinyConfig);

    return 0;
}
