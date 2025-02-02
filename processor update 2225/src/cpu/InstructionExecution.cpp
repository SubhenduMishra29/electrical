#include "CPU.h"
#include <iostream>

void CPU::executeInstruction(uint16_t instruction) {
    std::cout << "Fetched instruction: 0x" << std::hex << instruction << "\n"; // Print fetched instruction
    uint8_t opcode = (instruction >> 12); // Extract opcode (upper 4 bits)
    uint8_t Rd, Rr;
    int8_t k; // For relative jumps and immediate values
    uint16_t addr = 0; // Initialize addr variable
    uint8_t data; // Move initialization here
    std::cout << "Hexadecimal with 0x: 0x" << std::hex << opcode << std::endl;

    switch (opcode) {
        // NOP: No Operation
        case 0x00:
            std::cout << "Executing NOP\n";
            updateCycleCount(1);
            break;

        // Arithmetic and Logic Instructions
        case 0x1: // ADD
        case 0x2: // SUB
        case 0x3: // MUL
        case 0x4: // AND
        case 0x5: // OR
        case 0x6: // XOR
        case 0x7: // NOT
        //case 0x8: // NEG
        case 0x9: // INC
        case 0xA: // DEC
        case 0xB: // TST
        case 0xC: // CLR
        case 0xD: // SER
        case 0xE: // MULS
        case 0xF: // FMUL
        case 0x10: // FMULS
        case 0x11: // FMULSU
        case 0x12: // CP
        case 0x13: // CPC
        case 0x14: // SBC
        case 0x15: // SBCI
        case 0x16: // SBIW
        case 0x17: // SUBI
        case 0x18: // CPI
        case 0x19: // MOV
        case 0x1A: // MOVW
        case 0x1B: // LDI
        case 0x1C: // LDS
        case 0x1D: // LD
        case 0x1E: // LDD
        case 0x1F: // STD
        //case 0x20: // ST
        //case 0x21: // ST
        //case 0x22: // ST -X
       // case 0x23: // ST
        case 0x24: // ST Y+
        case 0x25: // ST -Y
        case 0x26: // ST
        case 0x27: // ST
        case 0x28: // S

            Rd = (instruction >> 8) & 0xF;
            Rr = (instruction >> 4) & 0xF;
            k = (instruction & 0xF) | ((instruction >> 4) & 0xF0); // Extract immediate value K correctly
            executeALUOperation(opcode, Rd, Rr, k);
            updateCycleCount(1);
            break;

        // Memory Instructions
        case 0x2D: // LDS Rd, Y/Z (Load Direct from SRAM)
            Rd = (instruction >> 8) & 0xF;
        case 0x3A: // S

            Rd = (instruction >> 8) & 0xF;
            Rr = (instruction >> 4) & 0xF;
            k = (instruction & 0xF) | ((instruction >> 4) & 0xF0); // Extract immediate value K correctly
            executeALUOperation(opcode, Rd, Rr, k);
            updateCycleCount(1);
            break;

        // Memory Instructions
        case 0x4D: // LDS Rd, Y/Z (Load Direct from SRAM)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[28] << 8) | registers[29]; // Y register
            registers[Rd] = memory.readSRAM(addr);
            std::cout << "Executing LDS R" << (int)Rd << ", Y\n";
            updateCycleCount(2);
            break;
        case 0x80: // STS Y/Z, Rr (Store Direct to SRAM)
            Rr = (instruction >> 4) & 0xF;
            addr = (registers[28] << 8) | registers[29]; // Y register
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing STS Y, R" << (int)Rr << "\n";
            updateCycleCount(2);
            break;
        case 0x81: // LDS Rd, X (Load Direct from SRAM)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[26] << 8) | registers[27]; // X register
            registers[Rd] = memory.readSRAM(addr);
            std::cout << "Executing LDS R" << (int)Rd << ", X\n";
            updateCycleCount(2);
            break;
        case 0x82: // STS X, Rr (Store Direct to SRAM)
            Rr = (instruction >> 4) & 0xF;
            addr = (registers[26] << 8) | registers[27]; // X register
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing STS X, R" << (int)Rr << "\n";
            updateCycleCount(2);
            break;
        case 0x83: // LDS Rd, Z (Load Direct from SRAM)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readSRAM(addr);
            std::cout << "Executing LDS R" << (int)Rd << ", Z\n";
            updateCycleCount(2);
            break;
        case 0x84: // STS Z, Rr (Store Direct to SRAM)
            Rr = (instruction >> 4) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing STS Z, R" << (int)Rr << "\n";
            updateCycleCount(2);
            break;
        case 0x85: // LDD Rd, Y+q (Load Indirect with Displacement)
            Rd = (instruction >> 8) & 0xF;
            {
                int8_t q = instruction & 0xFF;
                addr = (registers[28] << 8) | registers[29]; // Y register
                registers[Rd] = memory.readSRAM(addr + q);
                std::cout << "Executing LDD R" << (int)Rd << ", Y+" << (int)q << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x86: // STD Y+q, Rr (Store Indirect with Displacement)
            Rr = (instruction >> 4) & 0xF;
            {
                int8_t q = instruction & 0xFF;
                addr = (registers[28] << 8) | registers[29]; // Y register
                memory.writeSRAM(addr + q, registers[Rr]);
                std::cout << "Executing STD Y+" << (int)q << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x87: // LDD Rd, Z+q (Load Indirect with Displacement)
            Rd = (instruction >> 8) & 0xF;
            {
                int8_t q = instruction & 0xFF;
                addr = (registers[30] << 8) | registers[31]; // Z register
                registers[Rd] = memory.readSRAM(addr + q);
                std::cout << "Executing LDD R" << (int)Rd << ", Z+" << (int)q << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x88: // STD Z+q, Rr (Store Indirect with Displacement)
            Rr = (instruction >> 4) & 0xF;
            {
                int8_t q = instruction & 0xFF;
                addr = (registers[30] << 8) | registers[31]; // Z register
                memory.writeSRAM(addr + q, registers[Rr]);
                std::cout << "Executing STD Z+" << (int)q << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x89: // LPM Rd, Z (Load Program Memory)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readFlash(addr);
            std::cout << "Executing LPM R" << (int)Rd << ", Z\n";
            updateCycleCount(3);
            break;
        case 0x8A: // ELPM Rd, Z (Extended Load Program Memory)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readFlash(addr);
            registers[Rd + 1] = memory.readFlash(addr + 1);
            std::cout << "Executing ELPM R" << (int)Rd << ", Z\n";
            updateCycleCount(3);
            break;
        case 0x8B: // SPM (Store Program Memory)
            addr = (registers[30] << 8) | registers[31]; // Z register
            writeSPM(addr, registers[0]); // Store R0 in program memory
            updateCycleCount(4);
            break;
        case 0x8D: // LPM Rd, Z+ (Load Program Memory)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readFlash(addr++);
            registers[Rd + 1] = memory.readFlash(addr);
            std::cout << "Executing LPM R" << (int)Rd << ", Z+\n";
            updateCycleCount(3);
            break;
        case 0x8E: // ELPM Rd, Z+ (Extended Load Program Memory)
            Rd = (instruction >> 8) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readFlash(addr++);
            registers[Rd + 1] = memory.readFlash(addr);
            std::cout << "Executing ELPM R" << (int)Rd << ", Z+\n";
            updateCycleCount(3);
            break;
        case 0x8F: // SPM (Store Program Memory)
            addr = (registers[30] << 8) | registers[31]; // Z register
            memory.writeFlash(addr, registers[0]); // Store R0 in program memory
            std::cout << "Executing SPM\n";
            updateCycleCount(4);
            break;

        // Branch Instructions
        case 0x20: // RJMP k (Relative Jump)
            k = instruction & 0xFFF;
            if (k & 0x800) k |= 0xF000; // Sign extend
            programCounter += k;
            std::cout << "Executing RJMP to " << programCounter << "\n";
            updateCycleCount(2);
            break;
        case 0x21: // RCALL k (Relative Call)
            k = instruction & 0xFFF;
            if (k & 0x800) k |= 0xF000; // Sign extend
            stackPointer -= 2;
            memory.writeSRAM(stackPointer, programCounter & 0xFF);
            memory.writeSRAM(stackPointer + 1, (programCounter >> 8) & 0xFF);
            programCounter += k;
            std::cout << "Executing RCALL to " << programCounter << "\n";
            updateCycleCount(3);
            break;
        case 0x22: // RET (Return from Subroutine)
            programCounter = memory.readSRAM(stackPointer) | (memory.readSRAM(stackPointer + 1) << 8);
            stackPointer += 2;
            std::cout << "Executing RET\n";
            updateCycleCount(4);
            break;
        case 0x23: // RETI (Return from Interrupt)
            programCounter = memory.readSRAM(stackPointer) | (memory.readSRAM(stackPointer + 1) << 8);
            stackPointer += 2;
            sreg |= (1 << 7); // Enable global interrupts
            std::cout << "Executing RETI\n";
            updateCycleCount(4);
            break;
        case 0xF0: // BRBS s, k (Branch if Bit in SREG is Set)
        case 0xF4: // BRBS s, k (Branch if Bit in SREG is Set)
            {
                uint8_t s = (instruction >> 4) & 0x7;
                k = instruction & 0xF;
                if (sreg & (1 << s)) {
                    programCounter += k;
                }
                std::cout << "Executing BRBS " << (int)s << ", " << (int)k << "\n";
                updateCycleCount(2);
            }
            break;
        case 0xF1: // BRBC s, k (Branch if Bit in SREG is Cleared)
        case 0xF5: // BRBC s, k (Branch if Bit in SREG is Cleared)
            {
                uint8_t s = (instruction >> 4) & 0x7;
                k = instruction & 0xF;
                if (!(sreg & (1 << s))) {
                    programCounter += k;
                }
                std::cout << "Executing BRBC " << (int)s << ", " << (int)k << "\n";
                updateCycleCount(2);
            }
            break;

        // Bit Manipulation Instructions
        case 0xB0: // BSET s (Set Bit in SREG)
            {
                uint8_t s = instruction & 0x7;
                sreg |= (1 << s);
                std::cout << "Executing BSET " << (int)s << "\n";
                updateCycleCount(1);
            }
            break;
        case 0xB1: // BCLR s (Clear Bit in SREG)
            {
                uint8_t s = instruction & 0x7;
                sreg &= ~(1 << s);
                std::cout << "Executing BCLR " << (int)s << "\n";
                updateCycleCount(1);
            }
            break;
        case 0xB2: // BST Rd, b (Bit Store from Register to T)
            {
                Rd = (instruction >> 4) & 0xF;
                uint8_t b = instruction & 0x7;
                if (registers[Rd] & (1 << b)) {
                    sreg |= (1 << 6); // Set T flag
                } else {
                    sreg &= ~(1 << 6); // Clear T flag
                }
                std::cout << "Executing BST R" << (int)Rd << ", " << (int)b << "\n";
                updateCycleCount(1);
            }
            break;
        case 0xB3: // BLD Rd, b (Bit Load from T to Register)
            {
                Rd = (instruction >> 4) & 0xF;
                uint8_t b = instruction & 0x7;
                if (sreg & (1 << 6)) {
                    registers[Rd] |= (1 << b);
                } else {
                    registers[Rd] &= ~(1 << b);
                }
                std::cout << "Executing BLD R" << (int)Rd << ", " << (int)b << "\n";
                updateCycleCount(1);
            }
            break;

        // EEPROM Instructions
        case 0xC0: // EEWR (Write to EEPROM)
            addr = (instruction >> 4) & 0xFFF;
            data = registers[instruction & 0xF];
            memory.writeEEPROM(addr, data);
            updateCycleCount(4);
            break;
        case 0xC1: // EERD (Read from EEPROM)
            addr = (instruction >> 4) & 0xFFF;
            registers[instruction & 0xF] = memory.readEEPROM(addr);
            updateCycleCount(4);
            break;

        // Other Instructions
        case 0x8: // HALT (Terminate simulation)
            std::cout << "Executing HALT\n";
            halted = true;
            updateCycleCount(1);
            break;
        case 0x94: // SEZ (Set Zero Flag)
            if ((instruction & 0x0FFF) == 0x018) { // Check if the lower 12 bits match the SEZ opcode
                sreg |= (1 << 1); // Set the Zero (Z) flag
                std::cout << "Executing SEZ\n";
                updateCycleCount(1);
            } else {
                std::cout << "Unknown instruction: " << instruction << "\n";
            }
            break;
        case 0x95: // SLEEP: Enter Sleep Mode
            std::cout << "Executing SLEEP\n";
            // Simulate entering sleep mode (implementation depends on your system)
            updateCycleCount(1);
            break;
        case 0x96: // WDR: Watchdog Reset
            std::cout << "Executing WDR\n";
            // Simulate watchdog reset (implementation depends on your system)
            updateCycleCount(1);
            break;
        case 0x97: // BREAK: Breakpoint
            std::cout << "Executing BREAK\n";
            halted = true; // Simulate a breakpoint by halting the CPU
            updateCycleCount(1);
            break;
        case 0x98: // LPM: Load Program Memory
            Rd = (instruction >> 4) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readFlash(addr);
            std::cout << "Executing LPM R" << (int)Rd << ", Z\n";
            updateCycleCount(3);
            break;
        case 0x99: // ELPM: Extended Load Program Memory
            Rd = (instruction >> 4) & 0xF;
            addr = (registers[30] << 8) | registers[31]; // Z register
            registers[Rd] = memory.readFlash(addr);
            registers[Rd + 1] = memory.readFlash(addr);
            std::cout << "Executing ELPM R" << (int)Rd << ", Z\n";
            updateCycleCount(3);
            break;
        case 0x9A: // SPM: Store Program Memory
            addr = (registers[30] << 8) | registers[31]; // Z register
            memory.writeFlash(addr, registers[0]); // Store R0 in program memory
            std::cout << "Executing SPM\n";
            updateCycleCount(4);
            break;
        
        default:
            std::cout << "Unknown instruction: " << instruction << "\n";
            break;
    }
}