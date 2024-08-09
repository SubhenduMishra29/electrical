// power_quality.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef POWER_QUALITY_H
#define POWER_QUALITY_H

class PowerSystem;  // Forward declaration

class PowerQuality {
public:
    PowerQuality(); // Constructor

    void perform(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // POWER_QUALITY_H
