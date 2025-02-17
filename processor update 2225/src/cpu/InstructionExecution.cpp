#include "CPU.h"
#include <iostream>
// Update SREG Flags
void CPU::updateFlags(uint8_t result, uint8_t Rd, uint8_t Rr, bool carry) {
    sreg = 0;
    if (result == 0) sreg |= (1 << 1); // Zero flag (Z)
    if (result & 0x80) sreg |= (1 << 2); // Negative flag (N)
    if (carry) sreg |= (1 << 0); // Carry flag (C)
    bool v = ((Rd & 0x80) == (Rr & 0x80)) && ((Rd & 0x80) != (result & 0x80));
    if (v) sreg |= (1 << 3); // Overflow flag (V)
}
// Extract opcode for instruction decoding
uint16_t CPU::extractOpcode(uint16_t instruction) {
    if ((instruction & 0xF000) == 0x9000) return instruction & 0xFE0F; // Special handling for LDS, STS
    if ((instruction & 0xFC00) == 0xC000) return 0xC000; // RJMP
    if ((instruction & 0xFC00) == 0xD000) return 0xD000; // RCALL
    return instruction >> 12;
}

// Execute ALU Operations
void CPU::executeALUOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, int8_t k) {
    uint8_t result = 0;
    switch (opcode) {
        case 0x1: result = registers[Rd] += registers[Rr]; updateFlags(result, registers[Rd], registers[Rr], result < registers[Rd]); registers[Rd] = result; break; // ADD
        case 0x2: result = registers[Rd] -= registers[Rr];  updateFlags(result, registers[Rd], registers[Rr], registers[Rd] < registers[Rr]); registers[Rd] = result; break; // SUB
        case 0x3: registers[Rd] *= registers[Rr]; break; // MUL
        case 0x4: registers[Rd] &= registers[Rr]; updateFlags(registers[Rd], 0, 0, false); break; // AND
        case 0x5: registers[Rd] |= registers[Rr]; updateFlags(registers[Rd], 0, 0, false); break; // OR
        case 0x6: registers[Rd] ^= registers[Rr]; updateFlags(registers[Rd], 0, 0, false); break; // XOR
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
        case 0x13: registers[Rd] = registers[Rr]; break; // MOV
        case 0x14: registers[Rd] ^= registers[Rr]; break; // EOR
        case 0x15: registers[Rd] = registers[Rr] * registers[Rd]; break; // MULS
        case 0x16: registers[Rd] = registers[Rr] * registers[Rd] >> 1; break; // FMUL
        case 0x17: registers[Rd] = registers[Rr] * registers[Rd] >> 1; break; // FMULS
        // New bit manipulation instructions
        case 0x18: sreg |= (1 << Rd); break; // BSET (set bit in status register)
        case 0x19: sreg &= ~(1 << Rd); break; // BCLR (clear bit in status register)
        case 0x1A: sreg = (sreg & ~(1 << 6)) | ((registers[Rd] & (1 << k)) << 6); break; // BST (store bit in SREG)
        case 0x1B: registers[Rd] = (registers[Rd] & ~(1 << k)) | ((sreg & (1 << 6)) >> 6); break; // BLD (load bit from SREG)

        case 0x1C: registers[Rd] >>= 1; break; // LSR (Logical Shift Right)
        case 0x1D: registers[Rd] = (registers[Rd] >> 1) | (registers[Rd] & 0x80); break; // ASR (Arithmetic Shift Right)
        case 0x1E: registers[Rd] = (registers[Rd] << 1) | (sreg & 1); break; // ROL (Rotate Left)
        case 0x1F: registers[Rd] = (registers[Rd] >> 1) | ((sreg & 1) << 7); break; // ROR (Rotate Right)
        default: std::cout << "Unhandled ALU operation\n";
    }
}

// Execute Memory Operations
void CPU::executeMemoryOperation(uint16_t opcode, uint8_t Rd, uint8_t Rr, uint16_t addr, int16_t k){
    switch (opcode) {
        case 0x2D: registers[Rd] = memory.readSRAM(addr); break; // LDS
        case 0x80: memory.writeSRAM(addr, registers[Rr]); break; // STS
        case 0x90: registers[Rd] = memory.readEEPROM(addr); break; // IN
        case 0x91: memory.writeEEPROM(addr, registers[Rr]); break; // OUT
        case 0x92: memory.writeSRAM(--stackPointer, registers[Rd]); break; // PUSH
        case 0x93: registers[Rd] = memory.readSRAM(stackPointer++); break; // POP
        case 0x94: registers[Rd] = memory.readFlash(addr); break; // LPM
        case 0x95: memory.writeFlash(addr, registers[Rr] & 0xFF); break; // SPM
        case 0x96: registers[Rd] = memory.readFlash(addr + 1); break; // ELPM
        // New Load/Store Variants
        
        case 0xA6: registers[Rd] = memory.readSRAM(registers[30] + k); break; // LDD (Z+k)
        case 0xA7: memory.writeSRAM(registers[30] + k, registers[Rr]); break; // STD (Z+k)
        
        

        // Indirect load/store with X, Y, Z registers
        case 0xA0: registers[Rd] = memory.readSRAM(registers[26]); break; // LD (X)
        case 0xA1: memory.writeSRAM(registers[26], registers[Rr]); break; // ST (X)
        case 0xA2: registers[Rd] = memory.readSRAM(registers[28]); break; // LD (Y)
        case 0xA3: memory.writeSRAM(registers[28], registers[Rr]); break; // ST (Y)
        case 0xA4: registers[Rd] = memory.readSRAM(registers[30]); break; // LD (Z)
        case 0xA5: memory.writeSRAM(registers[30], registers[Rr]); break; // ST (Z)

        // LD/ST with pre-decrement and post-increment
        case 0xA8: registers[Rd] = memory.readSRAM(registers[26]++); break; // LD X+
        case 0xA9: registers[Rd] = memory.readSRAM(--registers[26]); break; // LD -X
        case 0xAA: memory.writeSRAM(registers[26]++, registers[Rr]); break; // ST X+
        case 0xAB: memory.writeSRAM(--registers[26], registers[Rr]); break; // ST -X

        case 0xAC: registers[Rd] = memory.readSRAM(registers[28]++); break; // LD Y+
        case 0xAD: registers[Rd] = memory.readSRAM(--registers[28]); break; // LD -Y
        case 0xAE: memory.writeSRAM(registers[28]++, registers[Rr]); break; // ST Y+
        case 0xAF: memory.writeSRAM(--registers[28], registers[Rr]); break; // ST -Y

        case 0xB0: registers[Rd] = memory.readSRAM(registers[30]++); break; // LD Z+
        case 0xB1: registers[Rd] = memory.readSRAM(--registers[30]); break; // LD -Z
        case 0xB2: memory.writeSRAM(registers[30]++, registers[Rr]); break; // ST Z+
        case 0xB3: memory.writeSRAM(--registers[30], registers[Rr]); break; // ST -Z

        default: std::cout << "Unhandled Memory operation\n";
    }
}

// Execute Branch Operations
void CPU::executeBranchOperation(uint16_t opcode, int16_t k) {
    switch (opcode) {
        case 0xC000: programCounter += k; break; // RJMP
        case 0xD000: 
            memory.writeSRAM(--stackPointer, programCounter & 0xFF);
            memory.writeSRAM(--stackPointer, (programCounter >> 8) & 0xFF);
            programCounter += k; 
            break; // RCALL
        case 0xE006: if (sreg & (1 << 3)) programCounter += k; break; // BRMI
        case 0xE007: if (!(sreg & (1 << 3))) programCounter += k; break; // BRPL
        case 0xE00A: if (!(sreg & (1 << 1))) programCounter += k; break; // BRNE
        case 0xE00B: if (sreg & (1 << 1)) programCounter += k; break; // BREQ
        case 0xE00C: if (!(sreg & (1 << 0))) programCounter += k; break; // BRSH
        case 0xE00D: if (sreg & (1 << 0)) programCounter += k; break; // BRLO
        // New Jump Instructions
        case 0x9509: programCounter = memory.readSRAM(stackPointer++) | (memory.readSRAM(stackPointer++) << 8); break; // RET
        case 0x9518: programCounter = memory.readSRAM(stackPointer++) | (memory.readSRAM(stackPointer++) << 8); sreg |= (1 << 7); break; // RETI
        case 0x940C: programCounter = (registers[31] << 8) | registers[30]; break; // IJMP
        case 0x950E: programCounter = (registers[31] << 8) | registers[30]; memory.writeSRAM(--stackPointer, programCounter & 0xFF); memory.writeSRAM(--stackPointer, (programCounter >> 8) & 0xFF); break; // ICALL
        case 0x940E: programCounter = memory.readSRAM(stackPointer++) | (memory.readSRAM(stackPointer++) << 8); break; // EIJMP        
        // Absolute jump and call instructions
        
        case 0x940D: 
            memory.writeSRAM(--stackPointer, programCounter & 0xFF);
            memory.writeSRAM(--stackPointer, (programCounter >> 8) & 0xFF);
            programCounter = (registers[31] << 8) | registers[30]; 
            break; // ICALL

        
        case 0x950F: 
            memory.writeSRAM(--stackPointer, programCounter & 0xFF);
            memory.writeSRAM(--stackPointer, (programCounter >> 8) & 0xFF);
            programCounter = memory.readSRAM(stackPointer++) | (memory.readSRAM(stackPointer++) << 8); 
            break; // EICALL

        
        // Absolute Jump and Call
        case 0x9400: programCounter = k; break; // JMP
        case 0x9401: 
            memory.writeSRAM(--stackPointer, programCounter & 0xFF);
            memory.writeSRAM(--stackPointer, (programCounter >> 8) & 0xFF);
            programCounter = k; 
            break; // CALL
        default: std::cout << "Unhandled Branch operation\n";
    }
}

// Execute Control Instructions
void CPU::executeControlInstruction(uint16_t opcode, uint8_t Rd, int16_t k){
    switch (opcode) {
        case 0xE0: sreg |= (1 << 7); break; // SEI (Enable Global Interrupt)
        case 0xE1: sreg &= ~(1 << 7); break; // CLI (Disable Global Interrupt)
        case 0xE2: sleepModeEnabled = true; break; // SLEEP
        case 0xE3: sleepModeEnabled = false; break; // WAKEUP
        // New Skip Instructions
        case 0xFC: if (!(registers[Rd] & (1 << k))) programCounter += 2; break; // SBRC
        case 0xFD: if (registers[Rd] & (1 << k)) programCounter += 2; break; // SBRS
        case 0xFE: if (!(memory.readIO(Rd) & (1 << k))) programCounter += 2; break; // SBIC
        case 0xFF: if (memory.readIO(Rd) & (1 << k)) programCounter += 2; break; // SBIS
        // Miscellaneous instructions
        case 0x0000: break; // NOP (No operation)
        case 0x95A8: std::cout << "BREAK: Debug Halt\n"; halted = true; break; // BREAK
        case 0x95A9: resetWatchdogTimer(); break; // WDR (Watchdog Reset)
        default: std::cout << "Unhandled Control operation\n";
    }
}

// Main instruction decoder
void CPU::executeInstruction(uint16_t instruction) {
    // HALT: Check for termination instruction (0xFFFF)
    if (instruction == 0xFFFF) {
        halted = true; // Set HALT flag
        std::cout << "CPU Halted: Execution terminated.\n";
        return; // Exit function early to stop execution
    }

    uint16_t opcode = extractOpcode(instruction);
    uint8_t Rd = (instruction >> 8) & 0x1F;
    uint8_t Rr = (instruction >> 4) & 0x1F;
    int16_t k = instruction & 0xFFF;
    uint16_t addr = (registers[30] << 8) | registers[31];

    if (opcode < 0x20) executeALUOperation(opcode, Rd, Rr, k);
    else if (opcode >= 0x80 && opcode <= 0x98) executeMemoryOperation(opcode, Rd, Rr, addr, k); 
    else if (opcode >= 0xC000) executeBranchOperation(opcode, k);
    else executeControlInstruction(opcode, Rd, k);
}


