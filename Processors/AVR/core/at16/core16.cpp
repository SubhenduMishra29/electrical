#include "core16.h"

// Constructor to initialize the ATmega16 core
ATmega16_Core::ATmega16_Core() {
    init();
}

// Initialize the ATmega16 core
void ATmega16_Core::init() {
    // Initialize registers, program counter, and memory
    std::fill_n(registers, NUM_REGISTERS, 0);
    PC = 0;
    std::fill_n(SRAM, SRAM_SIZE, 0);
    std::fill_n(EEPROM, EEPROM_SIZE, 0);
    std::fill_n(Flash, FLASH_SIZE, 0);  // Initialize flash memory for program storage
    std::fill_n(USART_Buffer, USART_BUFFER_SIZE, 0); // Initialize USART buffer
    USART_Buffer_Index = 0; // Reset USART buffer index
    is_running = true;

    // Initialize peripherals
    init_adc();
    init_timer16();
    init_usart();
}

// Load program into Flash memory via USART
void ATmega16_Core::load_program_via_usart() {
    printf("Waiting to receive program data via USART...\n");
    while (USART_Buffer_Index < FLASH_SIZE) {
        // Simulate receiving program data through USART (handled by usart_receive)
        // The program will write to Flash once it receives enough data
    }
    write_flash_from_usart_buffer();
    printf("Program loaded into Flash memory via USART.\n");
}

// Load program into Flash memory via GPIO pins
void ATmega16_Core::load_program_via_pins() {
    printf("Waiting for program data via pins...\n");
    
    // Simulating pin data input (for example, a simple loop to simulate timing)
    for (uint16_t i = 0; i < FLASH_SIZE; ++i) {
        // Simulate waiting for a pin signal to start loading
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate timing delay
        uint8_t pin_data = static_cast<uint8_t>(i % 256); // Simulated pin data (replace with actual input)
        write_flash_from_pin_data(pin_data);
    }

    printf("Program loaded into Flash memory via pins.\n");
}

// Simulate receiving data via USART (byte-by-byte)
void ATmega16_Core::usart_receive(uint8_t data) {
    if (USART_Buffer_Index < USART_BUFFER_SIZE) {
        USART_Buffer[USART_Buffer_Index++] = data; // Store data in buffer
        printf("Received byte via USART: 0x%02X\n", data);
    } else {
        printf("USART buffer full! Cannot receive more data.\n");
    }
}

// Simulate receiving data through pins and writing to Flash memory
void ATmega16_Core::pin_receive(uint8_t data) {
    // Handle receiving data through pins
    write_flash_from_pin_data(data);
}

// Helper function to write received data from USART buffer into Flash memory
void ATmega16_Core::write_flash_from_usart_buffer() {
    if (USART_Buffer_Index <= FLASH_SIZE) {
        std::copy(USART_Buffer, USART_Buffer + USART_Buffer_Index, Flash);
        printf("Flash memory successfully updated with USART data.\n");
    } else {
        printf("Error: Data exceeds Flash memory size!\n");
    }
}

// Helper function to write data directly to Flash memory from pin input
void ATmega16_Core::write_flash_from_pin_data(uint8_t data) {
    if (PC < FLASH_SIZE) {
        Flash[PC++] = data; // Write data to Flash memory
        printf("Wrote byte 0x%02X to Flash memory at address %u.\n", data, PC - 1);
    } else {
        printf("Error: Flash memory is full!\n");
    }
}

// Run the simulation for a specified number of cycles
void ATmega16_Core::run(uint32_t cycles) {
    for (uint32_t cycle = 0; cycle < cycles && is_running; ++cycle) {
        execute_instruction();
    }
    printf("Simulation complete after %u cycles.\n", cycles);
}

// Execute a single instruction based on the current opcode
void ATmega16_Core::execute_instruction() {
    uint8_t opcode = fetch_opcode();

    switch (opcode) {
        case 0x01: // MOV instruction
            mov(fetch_operand(), fetch_operand());
            break;

        case 0x20: { // ADC read instruction
            uint16_t result = read_adc(fetch_operand());
            printf("ADC Result: %u\n", result);
            break;
        }

        case 0x30: // USART send instruction
            usart_send(fetch_operand());
            break;

        case 0x50: // ADD instruction
            add(fetch_operand(), fetch_operand());
            break;

        case 0x51: // SUB instruction
            sub(fetch_operand(), fetch_operand());
            break;

        case 0x60: // JMP instruction
            jmp((fetch_operand() << 8) | fetch_operand());
            break;

        case 0xFF: // Invalid opcode
            handle_invalid_instruction(opcode);
            break;

        default:
            printf("Unknown opcode: 0x%02X\n", opcode);
            break;
    }
}

// Fetch opcode from Flash memory
uint8_t ATmega16_Core::fetch_opcode() {
    if (PC < FLASH_SIZE) {
        return Flash[PC++]; // Fetch from Flash memory
    } else {
        handle_invalid_memory_access("Program Counter out of bounds");
        return INVALID_OPCODE; // Return an invalid opcode
    }
}

// Fetch operand for the instruction
uint8_t ATmega16_Core::fetch_operand() {
    // In real implementation, fetch operand from Flash or register
    return 0; // Placeholder implementation
}

// Print the current state of the registers (for debugging)
void ATmega16_Core::print_registers() const {
    for (uint8_t i = 0; i < NUM_REGISTERS; ++i) {
        printf("R%d: 0x%02X\n", i, registers[i]);
    }
}
