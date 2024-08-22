// automatic_device_evaluation.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef AUTOMATIC_DEVICE_EVALUATION_H
#define AUTOMATIC_DEVICE_EVALUATION_H

class PowerSystem;  // Forward declaration

class AutomaticDeviceEvaluation {
public:
    AutomaticDeviceEvaluation(); // Constructor

    void perform(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // AUTOMATIC_DEVICE_EVALUATION_H
