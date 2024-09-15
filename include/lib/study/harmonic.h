// harmonic.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef HARMONIC_H
#define HARMONIC_H

class PowerSystem;  // Forward declaration

class Harmonic {
public:
    Harmonic(); // Constructor

    void perform(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // HARMONIC_H
