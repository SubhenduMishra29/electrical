#ifndef SPI_H
#define SPI_H

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
};

#endif // SPI_H
