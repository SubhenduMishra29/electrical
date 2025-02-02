#include "CPU.h"
#include <iostream>

void CPU::executeALUOperation(uint8_t opcode, uint8_t Rd, uint8_t Rr, int8_t k) {
    uint16_t addr; // Declare addr variable
    uint16_t instruction; // Declare instruction variable
    switch (opcode) {
        case 0x1: // ADD Rd, Rr
            {
                uint16_t result = registers[Rd] + registers[Rr];
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result & 0xFF;
                std::cout << "Executing ADD R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x2: // ADC Rd, Rr (Add with Carry)
            {
                uint16_t result = registers[Rd] + registers[Rr] + (sreg & 0x1);
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result & 0xFF;
                std::cout << "Executing ADC R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x3: // SUB Rd, Rr
            {
                uint16_t result = registers[Rd] - registers[Rr];
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result & 0xFF;
                std::cout << "Executing SUB R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x4: // ANDI Rd, K (Logical AND with Immediate)
            registers[Rd] &= k;
            updateFlags(registers[Rd], registers[Rd], k);
            std::cout << "Executing ANDI R" << (int)Rd << ", " << (int)k << "\n";
            updateCycleCount(1);
            break;
        case 0x5: // AND Rd, Rr (Logical AND)
            {
                uint8_t result = registers[Rd] & registers[Rr];
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result;
                std::cout << "Executing AND R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x6: // OR Rd, Rr (Logical OR)
            {
                uint8_t result = registers[Rd] | registers[Rr];
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result;
                std::cout << "Executing OR R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x7: // XOR Rd, Rr (Logical XOR)
            {
                uint8_t result = registers[Rd] ^ registers[Rr];
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result;
                std::cout << "Executing XOR R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x8: // SUBI Rd, K (Subtract Immediate)
            {
                uint16_t result = registers[Rd] - k;
                updateFlags(result, registers[Rd], k);
                registers[Rd] = result & 0xFF;
                std::cout << "Executing SUBI R" << (int)Rd << ", " << (int)k << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x9: // ORI Rd, K (Logical OR with Immediate)
            registers[Rd] |= k;
            updateFlags(registers[Rd], registers[Rd], k);
            std::cout << "Executing ORI R" << (int)Rd << ", " << (int)k << "\n";
            updateCycleCount(1);
            break;
        case 0xA: // EORI Rd, K (Logical Exclusive OR with Immediate)
            registers[Rd] ^= k;
            updateFlags(registers[Rd], registers[Rd], k);
            std::cout << "Executing EORI R" << (int)Rd << ", " << (int)k << "\n";
            updateCycleCount(1);
            break;
        case 0xB: // COM Rd (One's Complement)
            registers[Rd] = ~registers[Rd];
            updateFlags(registers[Rd], registers[Rd], 0);
            std::cout << "Executing COM R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        case 0xC: // NEG Rd (Two's Complement)
            registers[Rd] = -registers[Rd];
            updateFlags(registers[Rd], registers[Rd], 0);
            std::cout << "Executing NEG R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        case 0xD: // INC Rd (Increment)
            registers[Rd]++;
            updateFlags(registers[Rd], registers[Rd], 1);
            std::cout << "Executing INC R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        case 0xE: // DEC Rd (Decrement)
            registers[Rd]--;
            updateFlags(registers[Rd], registers[Rd], -1);
            std::cout << "Executing DEC R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        case 0xF: // TST Rd (Test for Zero or Minus)
            updateFlags(registers[Rd], registers[Rd], 0);
            std::cout << "Executing TST R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        // Add more ALU operations here
        case 0x10: // LSL Rd (Logical Shift Left)
            {
                uint8_t result = registers[Rd] << 1;
                updateFlags(result, registers[Rd], 0);
                registers[Rd] = result;
                std::cout << "Executing LSL R" << (int)Rd << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x11: // LSR Rd (Logical Shift Right)
            {
                uint8_t result = registers[Rd] >> 1;
                updateFlags(result, registers[Rd], 0);
                registers[Rd] = result;
                std::cout << "Executing LSR R" << (int)Rd << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x12: // ROL Rd (Rotate Left through Carry)
            {
                uint8_t carry = (sreg & 0x1) ? 1 : 0;
                uint8_t result = (registers[Rd] << 1) | carry;
                updateFlags(result, registers[Rd], 0);
                registers[Rd] = result;
                std::cout << "Executing ROL R" << (int)Rd << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x13: // ROR Rd (Rotate Right through Carry)
            {
                uint8_t carry = (sreg & 0x1) ? 0x80 : 0;
                uint8_t result = (registers[Rd] >> 1) | carry;
                updateFlags(result, registers[Rd], 0);
                registers[Rd] = result;
                std::cout << "Executing ROR R" << (int)Rd << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x14: // ASR Rd (Arithmetic Shift Right)
            {
                uint8_t result = (registers[Rd] >> 1) | (registers[Rd] & 0x80);
                updateFlags(result, registers[Rd], 0);
                registers[Rd] = result;
                std::cout << "Executing ASR R" << (int)Rd << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x15: // SWAP Rd (Swap Nibbles)
            {
                uint8_t result = (registers[Rd] << 4) | (registers[Rd] >> 4);
                updateFlags(result, registers[Rd], 0);
                registers[Rd] = result;
                std::cout << "Executing SWAP R" << (int)Rd << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x16: // SBIW Rd, K (Subtract Immediate from Word)
            {
                uint16_t result = (registers[Rd] | (registers[Rd + 1] << 8)) - k;
                updateFlags(result, registers[Rd], k);
                registers[Rd] = result & 0xFF;
                registers[Rd + 1] = (result >> 8) & 0xFF;
                std::cout << "Executing SBIW R" << (int)Rd << ", " << (int)k << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x17: // ADIW Rd, K (Add Immediate to Word)
            {
                uint16_t result = (registers[Rd] | (registers[Rd + 1] << 8)) + k;
                updateFlags(result, registers[Rd], k);
                registers[Rd] = result & 0xFF;
                registers[Rd + 1] = (result >> 8) & 0xFF;
                std::cout << "Executing ADIW R" << (int)Rd << ", " << (int)k << "\n";
                updateCycleCount(2);
            }
            break;
        // Add more ALU operations here
        case 0x18: // CLR Rd (Clear Register)
            registers[Rd] = 0;
            updateFlags(registers[Rd], registers[Rd], 0);
            std::cout << "Executing CLR R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        case 0x19: // SER Rd (Set Register)
            registers[Rd] = 0xFF;
            updateFlags(registers[Rd], registers[Rd], 0);
            std::cout << "Executing SER R" << (int)Rd << "\n";
            updateCycleCount(1);
            break;
        case 0x20: // MUL Rd, Rr (Multiply Registers)
            {
                uint16_t result = registers[Rd] * registers[Rr];
                registers[Rd] = result & 0xFF;
                registers[Rd + 1] = (result >> 8) & 0xFF;
                std::cout << "Executing MUL R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x21: // DIV Rd, Rr (Divide Registers)
            {
                if (registers[Rr] != 0) {
                    uint8_t result = registers[Rd] / registers[Rr];
                    registers[Rd] = result;
                    std::cout << "Executing DIV R" << (int)Rd << ", R" << (int)Rr << "\n";
                    updateCycleCount(2);
                } else {
                    std::cout << "Error: Division by zero\n";
                }
            }
            break;
        case 0x22: // MULS Rd, Rr (Signed Multiply Registers)
            {
                int16_t result = (int8_t)registers[Rd] * (int8_t)registers[Rr];
                registers[Rd] = result & 0xFF;
                registers[Rd + 1] = (result >> 8) & 0xFF;
                std::cout << "Executing MULS R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x23: // FMUL Rd, Rr (Fractional Multiply Registers)
            {
                uint16_t result = (registers[Rd] * registers[Rr]) << 1;
                registers[0] = result & 0xFF;
                registers[1] = (result >> 8) & 0xFF;
                updateFlags(result, registers[Rd], registers[Rr]);
                std::cout << "Executing FMUL R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x24: // FMULS Rd, Rr (Fractional Signed Multiply Registers)
            {
                int16_t result = ((int8_t)registers[Rd] * (int8_t)registers[Rr]) << 1;
                registers[0] = result & 0xFF;
                registers[1] = (result >> 8) & 0xFF;
                updateFlags(result, registers[Rd], registers[Rr]);
                std::cout << "Executing FMULS R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        case 0x25: // FMULSU Rd, Rr (Fractional Signed/Unsigned Multiply Registers)
            {
                int16_t result = ((int8_t)registers[Rd] * registers[Rr]) << 1;
                registers[0] = result & 0xFF;
                registers[1] = (result >> 8) & 0xFF;
                updateFlags(result, registers[Rd], registers[Rr]);
                std::cout << "Executing FMULSU R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(2);
            }
            break;
        // Add more ALU operations here
        case 0x26: // CP Rd, Rr (Compare Registers)
            {
                uint16_t result = registers[Rd] - registers[Rr];
                updateFlags(result, registers[Rd], registers[Rr]);
                std::cout << "Executing CP R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x27: // CPC Rd, Rr (Compare Registers with Carry)
            {
                uint16_t result = registers[Rd] - registers[Rr] - (sreg & 0x1);
                updateFlags(result, registers[Rd], registers[Rr]);
                std::cout << "Executing CPC R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x28: // CPI Rd, K (Compare Register with Immediate)
            {
                uint16_t result = registers[Rd] - k;
                updateFlags(result, registers[Rd], k);
                std::cout << "Executing CPI R" << (int)Rd << ", " << (int)k << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x29: // SBC Rd, Rr (Subtract with Carry)
            {
                uint16_t result = registers[Rd] - registers[Rr] - (sreg & 0x1);
                updateFlags(result, registers[Rd], registers[Rr]);
                registers[Rd] = result & 0xFF;
                std::cout << "Executing SBC R" << (int)Rd << ", R" << (int)Rr << "\n";
                updateCycleCount(1);
            }
            break;
        case 0x2A: // MOV Rd, Rr (Copy Register)
            registers[Rd] = registers[Rr];
            std::cout << "Executing MOV R" << (int)Rd << ", R" << (int)Rr << "\n";
            updateCycleCount(1);
            break;
        case 0x2B: // MOVW Rd, Rr (Copy Register Pair)
            registers[Rd] = registers[Rr];
            registers[Rd + 1] = registers[Rr + 1];
            std::cout << "Executing MOVW R" << (int)Rd << ", R" << (int)Rr << "\n";
            break;
        case 0x2C: // LDI Rd, K (Load Immediate)
            registers[Rd] = k;
            std::cout << "Executing LDI R" << (int)Rd << ", " << (int)k << "\n";
            break;
        case 0x2D: // LDS Rd, addr (Load Direct from SRAM)
            registers[Rd] = memory.readSRAM(addr);
            std::cout << "Executing LDS R" << (int)Rd << ", " << addr << "\n";
            break;
        case 0x2E: // LD Rd, X (Load Indirect)
            registers[Rd] = memory.readSRAM(addr);
            std::cout << "Executing LD R" << (int)Rd << ", X\n";
            break;
        case 0x2F: // LD Rd, X+ (Load Indirect with Post-Increment)
            registers[Rd] = memory.readSRAM(addr);
            addr++;
            registers[26] = addr >> 8;
            registers[27] = addr & 0xFF;
            std::cout << "Executing LD R" << (int)Rd << ", X+\n";
            break;
        case 0x30: // LDD Rd, Y+q (Load Indirect with Displacement)
            {
                int8_t q = instruction & 0xFF;
                addr = (registers[28] << 8) | registers[29]; // Y register
                registers[Rd] = memory.readSRAM(addr + q);
                std::cout << "Executing LDD R" << (int)Rd << ", Y+" << (int)q << "\n";
            }
            break;
        case 0x31: // STD Y+q, Rr (Store Indirect with Displacement)
            {
                int8_t q = instruction & 0xFF;
                addr = (registers[28] << 8) | registers[29]; // Y register
                memory.writeSRAM(addr + q, registers[Rr]);
                std::cout << "Executing STD Y+" << (int)q << ", R" << (int)Rr << "\n";
            }
            break;
        case 0x32: // ST X, Rr (Store Indirect)
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing ST X, R" << (int)Rr << "\n";
            break;
        case 0x33: // ST X+, Rr (Store Indirect with Post-Increment)
            memory.writeSRAM(addr, registers[Rr]);
            addr++;
            registers[26] = addr >> 8;
            registers[27] = addr & 0xFF;
            std::cout << "Executing ST X+, R" << (int)Rr << "\n";
            break;
        case 0x34: // ST -X, Rr (Store Indirect with Pre-Decrement)
            addr--;
            registers[26] = addr >> 8;
            registers[27] = addr & 0xFF;
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing ST -X, R" << (int)Rr << "\n";
            break;
        case 0x35: // ST Y, Rr (Store Indirect)
            addr = (registers[28] << 8) | registers[29]; // Y register
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing ST Y, R" << (int)Rr << "\n";
            break;
        case 0x36: // ST Y+, Rr (Store Indirect with Post-Increment)
            addr = (registers[28] << 8) | registers[29]; // Y register
            memory.writeSRAM(addr, registers[Rr]);
            addr++;
            registers[28] = addr >> 8;
            registers[29] = addr & 0xFF;
            std::cout << "Executing ST Y+, R" << (int)Rr << "\n";
            break;
        case 0x37: // ST -Y, Rr (Store Indirect with Pre-Decrement)
            addr = (registers[28] << 8) | registers[29]; // Y register
            addr--;
            registers[28] = addr >> 8;
            registers[29] = addr & 0xFF;
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing ST -Y, R" << (int)Rr << "\n";
            break;
        case 0x38: // ST Z, Rr (Store Indirect)
            addr = (registers[30] << 8) | registers[31]; // Z register
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing ST Z, R" << (int)Rr << "\n";
            break;
        case 0x39: // ST Z+, Rr (Store Indirect with Post-Increment)
            addr = (registers[30] << 8) | registers[31]; // Z register
            memory.writeSRAM(addr, registers[Rr]);
            addr++;
            registers[30] = addr >> 8;
            registers[31] = addr & 0xFF;
            std::cout << "Executing ST Z+, R" << (int)Rr << "\n";
            break;
        case 0x3A: // ST -Z, Rr (Store Indirect with Pre-Decrement)
            addr = (registers[30] << 8) | registers[31]; // Z register
            addr--;
            registers[30] = addr >> 8;
            registers[31] = addr & 0xFF;
            memory.writeSRAM(addr, registers[Rr]);
            std::cout << "Executing ST -Z, R" << (int)Rr << "\n";
            break;
        // ...other ALU operations...
        default:
            std::cout << "Unknown ALU operation: " << (int)opcode << "\n";
            break;
    }
}