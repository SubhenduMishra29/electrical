class Memory {
    // ...existing code...
public:
    void writeEEPROM(uint16_t addr, uint8_t data);
    uint8_t readEEPROM(uint16_t addr);
    // ...existing code...
private:
    uint8_t eeprom[EEPROM_SIZE];
    // ...existing code...
};
