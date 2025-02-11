#include "CPU.h"
#include <iostream>

// Extract opcode properly for different instruction formats
uint16_t CPU::extractOpcode(uint16_t instruction) {
    if ((instruction & 0xF000) == 0x9000) return instruction & 0xFE0F; // Special handling for LDS, STS, etc.
    if ((instruction & 0xFC00) == 0xC000) return 0xC000; // RJMP
    if ((instruction & 0xFC00) == 0xD000) return 0xD000; // RCALL
    return instruction >> 12;
}

// Modular function for arithmetic and logic operations
void CPU::executeALUOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, int8_t k) {
    switch (opcode) {
        case 0x1: registers[Rd] += registers[Rr]; break; // ADD
        case 0x2: registers[Rd] -= registers[Rr]; break; // SUB
        case 0x3: registers[Rd] *= registers[Rr]; break; // MUL
        case 0x4: registers[Rd] &= registers[Rr]; break; // AND
        case 0x5: registers[Rd] |= registers[Rr]; break; // OR
        case 0x6: registers[Rd] ^= registers[Rr]; break; // XOR
        case 0x7: registers[Rd] = ((registers[Rd] & 0x0F) << 4) | ((registers[Rd] & 0xF0) >> 4); break; // SWAP
        case 0x8: registers[Rd] = -registers[Rd]; break; // NEG
        case 0x9: registers[Rd]++; break; // INC
        case 0xA: registers[Rd]--; break; // DEC
        case 0xB: sreg |= (registers[Rd] == 0) << 1; break; // TST
        case 0xC: registers[Rd] = 0; break; // CLR
        case 0xD: registers[Rd] = 0xFF; break; // SER
        case 0xE: registers[Rd] = ~registers[Rd]; break; // COM
        case 0xF: registers[Rd] -= registers[Rr] - (sreg & 1); break; // SBC
        case 0x10: registers[Rd] -= k - (sreg & 1); break; // SBCI
        case 0x11: registers[Rd] -= k; break; // SUBI
        case 0x12: sreg |= (registers[Rd] == k) << 1; break; // CPI
        case 0x1E: registers[Rd] <<= 1; break; // LSL
        case 0x1F: registers[Rd] >>= 1; break; // LSR
        case 0x20: registers[Rd] = (registers[Rd] >> 1) | (registers[Rd] & 0x80); break; // ASR
        case 0x21: registers[Rd] = (registers[Rd] << 1) | (sreg & 1); break; // ROL
        case 0x22: registers[Rd] = (registers[Rd] >> 1) | ((sreg & 1) << 7); break; // ROR
        default: std::cout << "Unhandled ALU operation\n";
    }
}

// Modular function for memory operations
void CPU::executeMemoryOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, uint16_t addr) {
    switch (opcode) {
        case 0x2D: registers[Rd] = memory.readSRAM(addr); break; // LDS (Load Direct from SRAM)
        case 0x80: memory.writeSRAM(addr, registers[Rr]); break; // STS (Store Direct to SRAM)
        case 0x90: registers[Rd] = memory.readEEPROM(addr); break; // IN (Now mapped to EEPROM read)
        case 0x91: memory.writeEEPROM(addr, registers[Rr]); break; // OUT (Now mapped to EEPROM write)
        case 0x92: memory.writeSRAM(--stackPointer, registers[Rd]); break; // PUSH
        case 0x93: registers[Rd] = memory.readSRAM(stackPointer++); break; // POP
        case 0x94: registers[Rd] = memory.readFlash(addr); break; // LPM (Load from Flash)
        case 0x95: memory.writeFlash(addr, registers[Rr] & 0xFF); break; // SPM (Store to Flash)
        case 0x96: registers[Rd] = memory.readFlash(addr + 1); break; // ELPM
        default: std::cout << "Unhandled Memory operation\n";
    }
}

// Modular function for branching operations
void CPU::executeBranchOperation(uint16_t opcode, int16_t k) {
    switch (opcode) {
        case 0xC000: programCounter += k; break; // RJMP
        case 0xD000: memory.writeSRAM(--stackPointer, programCounter & 0xFF); memory.writeSRAM(--stackPointer, (programCounter >> 8) & 0xFF); programCounter += k; break; // RCALL
        case 0xE006: if (sreg & (1 << 3)) programCounter += k; break; // BRMI
        case 0xE007: if (!(sreg & (1 << 3))) programCounter += k; break; // BRPL
        case 0xE008: if (!(sreg & (1 << 4))) programCounter += k; break; // BRVC
        case 0xE009: if (sreg & (1 << 4)) programCounter += k; break; // BRVS
        case 0xE00A: if (!(sreg & (1 << 1))) programCounter += k; break; // BRNE
        case 0xE00B: if (sreg & (1 << 1)) programCounter += k; break; // BREQ
        case 0xE00C: if (!(sreg & (1 << 0))) programCounter += k; break; // BRSH
        case 0xE00D: if (sreg & (1 << 0)) programCounter += k; break; // BRLO
        default: std::cout << "Unhandled Branch operation\n";
    }
}

void CPU::executeInstruction(uint16_t instruction) {
     if (instruction == 0xFFFF) {
        std::cout << "HALT encountered. Stopping execution.\n";
        halted = true; // Add a flag to stop further execution
        return;
    }
    uint16_t opcode = extractOpcode(instruction);
    uint8_t Rd = (instruction >> 8) & 0xF;
    uint8_t Rr = (instruction >> 4) & 0xF;
    int16_t k = instruction & 0xFFF;
    uint16_t addr = (registers[30] << 8) | registers[31];
    
    if (opcode < 0x20) executeALUOperation(opcode, Rd, Rr, k);
    else if (opcode >= 0x80 && opcode <= 0x98) executeMemoryOperation(opcode, Rd, Rr, addr);
    else if (opcode >= 0xC000) executeBranchOperation(opcode, k);
    else std::cout << "Unknown instruction: " << std::hex << instruction << "\n";
}
