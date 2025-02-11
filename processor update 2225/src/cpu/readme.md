# AVR Instruction Emulator

## Overview
This project is an **AVR instruction emulator** that processes and executes AVR machine instructions. It is designed to be modular, breaking down execution into different categories:

- **Arithmetic & Logic:** `executeALUOperation()`
- **Memory Operations:** `executeMemoryOperation()`
- **Branching & Control Flow:** `executeBranchOperation()`
- **Main Execution:** `executeInstruction()`

---

## 1️⃣ `executeInstruction(uint16_t instruction)`
This is the **main function** that takes a **16-bit AVR instruction** and determines which category it belongs to.

### **Step-by-Step Execution:**
1. **Extracts the opcode** using `extractOpcode(instruction)`.
2. **Extracts operands** like:
   - `Rd` (destination register)
   - `Rr` (source register)
   - `k` (immediate value or branch offset)
   - `addr` (memory address)
3. **Routes the instruction:**
   - If **arithmetic/logic** (`opcode < 0x20`), it calls `executeALUOperation()`.
   - If **memory operation** (`0x80 <= opcode <= 0x98`), it calls `executeMemoryOperation()`.
   - If **branching instruction** (`opcode >= 0xC000`), it calls `executeBranchOperation()`.
   - If unknown, it prints `"Unknown instruction"`.

---

## 2️⃣ `executeALUOperation(opcode, Rd, Rr, k)`
Handles **arithmetic and logic operations** like `ADD`, `SUB`, `MUL`, `AND`, `OR`, `XOR`, `NEG`, `INC`, `DEC`, `TST`, `LSL`, `LSR`, `ROL`, `ROR`.

### **Example Execution:**
- **ADD (opcode = 0x1, Rd += Rr)**:
  ```cpp
  registers[Rd] += registers[Rr];
  ```
- **TST (opcode = 0xB, test if zero)**:
  ```cpp
  sreg |= (registers[Rd] == 0) << 1; // Set Zero Flag in Status Register
  ```

---

## 3️⃣ `executeMemoryOperation(opcode, Rd, Rr, addr)`
Handles **load/store operations** like `LDS`, `STS`, `IN`, `OUT`, `PUSH`, `POP`, `LPM`, `SPM`.

### **Example Execution:**
- **Load from SRAM (`LDS Rd, addr`)**:
  ```cpp
  registers[Rd] = memory.readSRAM(addr);
  ```
- **Store to SRAM (`STS addr, Rr`)**:
  ```cpp
  memory.writeSRAM(addr, registers[Rr]);
  ```
- **Stack Operations**:
  - `PUSH` saves a register to the stack:
    ```cpp
    memory.writeSRAM(--stackPointer, registers[Rd]);
    ```
  - `POP` retrieves a value from the stack:
    ```cpp
    registers[Rd] = memory.readSRAM(stackPointer++);
    ```

---

## 4️⃣ `executeBranchOperation(opcode, k)`
Handles **jump and branching instructions** like `RJMP`, `RCALL`, `BRNE`, `BREQ`, `BRMI`, etc.

### **Example Execution:**
- **Relative Jump (`RJMP k`)**:
  ```cpp
  programCounter += k;
  ```
- **Conditional Branch (`BRNE k`)** (Branch if Not Equal):
  ```cpp
  if (!(sreg & (1 << 1))) programCounter += k; // Check Zero flag in Status Register
  ```

---

## How to Call `executeInstruction()`
To use this function in a program:
```cpp
CPU cpu;
uint16_t instruction = 0x940C; // Example: JMP instruction
cpu.executeInstruction(instruction);
```

---

## 📌 Summary
- `executeInstruction()` **routes the instruction** to the correct handler.
- `executeALUOperation()` **performs arithmetic and logic operations**.
- `executeMemoryOperation()` **handles data loads and stores**.
- `executeBranchOperation()` **controls jumps and branches**.

This structure makes the AVR emulator **efficient and modular**, allowing easy expansion. 🚀

