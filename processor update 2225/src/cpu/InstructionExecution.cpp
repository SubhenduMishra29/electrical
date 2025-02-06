#include "CPU.h"
#include <iostream>

// Extract opcode properly for different instruction formats
uint16_t CPU::extractOpcode(uint16_t instruction) {
    if ((instruction & 0xF000) == 0x9000) {
        return instruction & 0xFE0F; // Special handling for LDS, STS, etc.
    } else if ((instruction & 0xFC00) == 0xC000) {
        return 0xC000; // RJMP
    } else if ((instruction & 0xFC00) == 0xD000) {
        return 0xD000; // RCALL
    }
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
        case 0xB: if (registers[Rd] == 0) sreg |= (1 << 1); break; // TST
        case 0xC: registers[Rd] = 0; break; // CLR
        case 0xD: registers[Rd] = 0xFF; break; // SER
        case 0xE: registers[Rd] = ~registers[Rd]; break; // COM
        case 0x19: registers[Rd] *= registers[Rr]; break; // MULS
        case 0x1A: registers[Rd] *= registers[Rr]; break; // MULSU
        case 0x1B: registers[Rd] *= registers[Rr]; break; // FMUL
        case 0x1C: registers[Rd] *= registers[Rr]; break; // FMULS
        case 0x1D: registers[Rd] *= registers[Rr]; break; // FMULSU
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
        case 0x2D: registers[Rd] = memory.readSRAM(addr); break; // LDS
        case 0x80: memory.writeSRAM(addr, registers[Rr]); break; // STS
        case 0x90: registers[Rd] = memory.readIO(addr); break; // IN
        case 0x91: memory.writeIO(addr, registers[Rr]); break; // OUT
        case 0x92: stackPointer -= 1; memory.writeSRAM(stackPointer, registers[Rd]); break; // PUSH
        case 0x93: registers[Rd] = memory.readSRAM(stackPointer); stackPointer += 1; break; // POP
        case 0x94: registers[Rd] = memory.readFlash(addr); break; // LPM
        case 0x95: memory.writeFlash(addr, registers[Rr]); break; // SPM
        default: std::cout << "Unhandled Memory operation\n";
    }
}

// Modular function for branching operations
void CPU::executeBranchOperation(uint16_t opcode, int16_t k) {
    switch (opcode) {
        case 0xC000: programCounter += k; break; // RJMP
        case 0xD000: stackPointer -= 2; memory.writeSRAM(stackPointer, programCounter & 0xFF); memory.writeSRAM(stackPointer + 1, (programCounter >> 8) & 0xFF); programCounter += k; break; // RCALL
        case 0xE006: if (sreg & (1 << 3)) programCounter += k; break; // BRMI
        case 0xE007: if (!(sreg & (1 << 3))) programCounter += k; break; // BRPL
        case 0xE008: if (!(sreg & (1 << 4))) programCounter += k; break; // BRVC
        case 0xE009: if (sreg & (1 << 4)) programCounter += k; break; // BRVS
        default: std::cout << "Unhandled Branch operation\n";
    }
}

void CPU::executeInstruction(uint16_t instruction) {
    uint16_t opcode = extractOpcode(instruction);
    uint8_t Rd = (instruction >> 8) & 0xF;
    uint8_t Rr = (instruction >> 4) & 0xF;
    int16_t k = instruction & 0xFFF;
    uint16_t addr = (registers[30] << 8) | registers[31];
    
    if (opcode < 0x20) {
        executeALUOperation(opcode, Rd, Rr, k);
    } else if (opcode >= 0x80 && opcode <= 0x98) {
        executeMemoryOperation(opcode, Rd, Rr, addr);
    } else if (opcode >= 0xC000) {
        executeBranchOperation(opcode, k);
    } else {
        std::cout << "Unknown instruction: " << std::hex << instruction << "\n";
    }
}
