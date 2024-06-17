#ifndef LINE_H
#define LINE_H

struct Line {
    int id;          // Line ID
    int fromBus;     // From bus ID
    int toBus;       // To bus ID
    double impedance; // Line impedance (assumed to be purely reactive for simplicity)
};

#endif // LINE_H

