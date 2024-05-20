/*
 * File: ErrorHandling.h
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef STATE_H
#define STATE_H

#include <stdexcept>
#include "ErrorHandling.h" // Include the error handling module

class State {
private:
    // Member variables...

public:
    // Constructor and other member functions...

    // Setter functions with error handling
    void setMainContactCurrent(double current) {
        if (current <= maxMainCurrent) {
            mainContactCurrent = current;
        } else {
            throw MaxCurrentExceededException("Current exceeds maximum current for main contact.");
        }
    }

    void setAuxiliaryContactCurrent(double current) {
        if (current <= maxAuxiliaryCurrent) {
            auxiliaryContactCurrent = current;
        } else {
            throw MaxCurrentExceededException("Current exceeds maximum current for auxiliary contact.");
        }
    }
};

#endif // STATE_H
