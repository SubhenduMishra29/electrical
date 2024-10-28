#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include "core16.h" // Include the header file for the ATmega16_Core definition

// Define the function prototypes for all AVR instruction set

// Arithmetic and Logic Instructions
void add(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Add without carry
void adc(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Add with carry
void adiw(ATmega16_Core* core, uint16_t* Rd, uint8_t K); // Add immediate to word
void sub(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Subtract without carry
void sbc(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Subtract with carry
void subi(ATmega16_Core* core, uint8_t Rd, uint8_t K);   // Subtract immediate
void sbci(ATmega16_Core* core, uint8_t Rd, uint8_t K);   // Subtract immediate with carry
void sbiw(ATmega16_Core* core, uint16_t* Rd, uint8_t K); // Subtract immediate from word
void and_inst(ATmega16_Core* core, uint8_t Rd, uint8_t Rr); // Logical AND
void andi(ATmega16_Core* core, uint8_t Rd, uint8_t K);   // Logical AND with immediate
void or_inst(ATmega16_Core* core, uint8_t Rd, uint8_t Rr); // Logical OR
void ori(ATmega16_Core* core, uint8_t Rd, uint8_t K);    // Logical OR with immediate
void eor(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Exclusive OR
void com(ATmega16_Core* core, uint8_t Rd);               // One's complement
void neg(ATmega16_Core* core, uint8_t Rd);               // Two's complement
void inc(ATmega16_Core* core, uint8_t Rd);               // Increment
void dec(ATmega16_Core* core, uint8_t Rd);               // Decrement
void mul(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Multiply
void muls(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);  // Multiply signed
void mulsu(ATmega16_Core* core, uint8_t Rd, uint8_t Rr); // Multiply signed with unsigned
void fmul(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);  // Fractional multiply
void fmulc(ATmega16_Core* core, uint8_t Rd, uint8_t Rr); // Fractional multiply with rounding
void fmulsu(ATmega16_Core* core, uint8_t Rd, uint8_t Rr); // Fractional multiply signed/unsigned
void lsl(ATmega16_Core* core, uint8_t Rd);               // Logical shift left
void lsr(ATmega16_Core* core, uint8_t Rd);               // Logical shift right
void rol(ATmega16_Core* core, uint8_t Rd);               // Rotate left through carry
void ror(ATmega16_Core* core, uint8_t Rd);               // Rotate right through carry
void asr(ATmega16_Core* core, uint8_t Rd);               // Arithmetic shift right
void swap(ATmega16_Core* core, uint8_t Rd);              // Swap nibbles

// Data Transfer Instructions
void mov(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Copy register
void movw(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);  // Copy register pair
void ldi(ATmega16_Core* core, uint8_t Rd, uint8_t K);    // Load immediate
void lds(ATmega16_Core* core, uint8_t Rd, uint16_t k);   // Load direct from data space
void sts(ATmega16_Core* core, uint16_t k, uint8_t Rr);   // Store direct to data space
void ld(ATmega16_Core* core, uint8_t Rd, uint16_t addr); // Load indirect with displacement
void st(ATmega16_Core* core, uint16_t addr, uint8_t Rr); // Store indirect with displacement
void ld_x(ATmega16_Core* core, uint8_t Rd);              // Load indirect from X
void st_x(ATmega16_Core* core, uint8_t Rr);              // Store indirect to X
void ld_y(ATmega16_Core* core, uint8_t Rd);              // Load indirect from Y
void st_y(ATmega16_Core* core, uint8_t Rr);              // Store indirect to Y
void ld_z(ATmega16_Core* core, uint8_t Rd);              // Load indirect from Z
void st_z(ATmega16_Core* core, uint8_t Rr);              // Store indirect to Z
void push(ATmega16_Core* core, uint8_t Rr);              // Push register on stack
void pop(ATmega16_Core* core, uint8_t Rd);               // Pop register from stack

// Bit and Bit-Test Instructions
void sbr(ATmega16_Core* core, uint8_t Rd, uint8_t K);    // Set bits in register
void cbr(ATmega16_Core* core, uint8_t Rd, uint8_t K);    // Clear bits in register
void bst(ATmega16_Core* core, uint8_t Rd, uint8_t b);    // Bit store from register to T
void bld(ATmega16_Core* core, uint8_t Rd, uint8_t b);    // Bit load from T to register
void sbi(ATmega16_Core* core, uint16_t addr, uint8_t b); // Set bit in I/O register
void cbi(ATmega16_Core* core, uint16_t addr, uint8_t b); // Clear bit in I/O register
void sbic(ATmega16_Core* core, uint16_t addr, uint8_t b); // Skip if bit in I/O register is cleared
void sbis(ATmega16_Core* core, uint16_t addr, uint8_t b); // Skip if bit in I/O register is set

// Control Instructions
void jmp(ATmega16_Core* core, uint16_t addr);            // Jump to address
void rjmp(ATmega16_Core* core, int16_t k);               // Relative jump
void ijmp(ATmega16_Core* core);                          // Indirect jump via Z
void call(ATmega16_Core* core, uint16_t addr);           // Call subroutine
void rcall(ATmega16_Core* core, int16_t k);              // Relative call subroutine
void icall(ATmega16_Core* core);                         // Indirect call via Z
void ret(ATmega16_Core* core);                           // Return from subroutine
void reti(ATmega16_Core* core);                          // Return from interrupt
void cp(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);    // Compare
void cpc(ATmega16_Core* core, uint8_t Rd, uint8_t Rr);   // Compare with carry
void cpi(ATmega16_Core* core, uint8_t Rd, uint8_t K);    // Compare with immediate
void brbs(ATmega16_Core* core, uint8_t s, int8_t k);     // Branch if bit in SREG is set
void brbc(ATmega16_Core* core, uint8_t s, int8_t k);     // Branch if bit in SREG is cleared

// MCU Control Instructions
void sei(ATmega16_Core* core);                           // Set global interrupt flag
void cli(ATmega16_Core* core);                           // Clear global interrupt flag
void wdr(ATmega16_Core* core);                           // Watchdog reset
void nop(ATmega16_Core* core);                           // No operation
void sleep(ATmega16_Core* core);                         // Sleep mode
void break_inst(ATmega16_Core* core);                    // Breakpoint

// Add additional MCU instructions as necessary...

#endif // INSTRUCTION_SET_H
