#ifndef SPI_H
#define SPI_H
#include <iostream>
class SPI {
public:
    enum class Mode {
        Master,
        Slave
    };

    enum class ClockPolarity {
        Low,
        High
    };

    enum class ClockPhase {
        FirstEdge,
        SecondEdge
    };

    void configure(Mode mode, ClockPolarity polarity, ClockPhase phase);
    void reset();
    // ...other methods...
    void enableInterrupt() {
        std::cout << "SPI interrupt enabled.\n";
    }
};

#endif // SPI_H
