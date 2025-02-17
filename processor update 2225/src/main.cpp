#include "../mcu/mcu.h"
#include <iostream>
#include "../gui/src/gui.h"

void simulateMCU(const MCUConfig& config) {
    MCU mcu(config);

    std::vector<uint16_t> program = {
        0x0000, // NOP
        0x1101, // ADD R1, R1
        0x1202, // ADC R2, R1
        0x0F03, // LDI R3, 0x0F
        0x1303, // SUB R3, R1
        0x1404, // LOAD R4 from SRAM[4]
        0x1505, // STORE R5 to SRAM[5]
        0x1606, // MOV R6, R0
        0xFFFF  // HALT (Terminate simulation)
    };

    mcu.loadProgram(program);
    mcu.configurePeripherals();

    if (config.portCount > 0) {
        mcu.configurePorts();
    } else {
        std::cerr << "[ERROR] Invalid port count: " << config.portCount << std::endl;
        return;
    }

    mcu.provideInputToPins();

    // Run the MCU simulation with cycle limit
    const int maxCycles = 1000000; 
    mcu.run();

    mcu.reset();
}

int main(int argc, char *argv[]) {
    // gui initialisation here 
    init_gui(&argc, &argv);
    run_gui();

    std::cout << "--------------------------\n";
    std::cout << "Simulating ATmega16\n";
    std::cout << "--------------------------\n";

    MCUConfig atmega16Config = MCUConfig::createPreset(AVRCoreType::ATmega16);
    simulateMCU(atmega16Config);

    return 0;
}
