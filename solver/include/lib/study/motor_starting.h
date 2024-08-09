// motor_starting.h 
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef MOTOR_STARTING_H
#define MOTOR_STARTING_H

class PowerSystem;  // Forward declaration

class MotorStarting {
public:
    MotorStarting(); // Constructor

    void perform(PowerSystem& powerSystem);
    // Add more methods and members as needed
};

#endif // MOTOR_STARTING_H
