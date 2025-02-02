#ifndef TWI_H
#define TWI_H

#include <cstdint> // Include cstdint for uint32_t

class TWI {
public:
    void initialize(uint32_t clockFrequency);
    // Other TWI/I2C related methods
};

#endif // TWI_H
