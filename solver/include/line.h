// line.h
#ifndef LINE_H
#define LINE_H

struct Line {
    int id;           // Line ID
    int fromBus;      // Index of the bus where the line starts
    int toBus;        // Index of the bus where the line ends
    double impedance; // Impedance of the line (for simplicity, assumed constant)
};

#endif // LINE_H

