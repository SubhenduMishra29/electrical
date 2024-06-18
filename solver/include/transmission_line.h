// transmission_line.h

#ifndef TRANSMISSION_LINE_H
#define TRANSMISSION_LINE_H

#include "bus.h"  // Include bus header

class TransmissionLine {
private:
    Bus* bus1;
    Bus* bus2;
    double impedance;  // in ohms
    double length;     // in kilometers

public:
    TransmissionLine(Bus* bus1, Bus* bus2, double impedance, double length);
    void simulatePowerFlow();
};

#endif // TRANSMISSION_LINE_H
