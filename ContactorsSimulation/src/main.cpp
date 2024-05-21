/*
 * File: Main.cpp
 * Author: Subhendu Mishra
 * License: GPL
 */

#include <iostream>
#include "Contactor.h"
#include "ContactFunctions.h"
#include "ErrorHandling.h" // Include the error handling module

int main() {
    try {
        // Create a Contactor object
        Contactor myContactor("ABC Inc.", "Model XYZ", "3RT20", "S00", "screw", true, true,
                              "Page Selection and ordering data • AC/DC operation 2/8 • Accessories 2/66 • Spare parts  2/94", 100.0);

        // Automatically add main and auxiliary contacts
        autoAddMainContacts(myContactor, 3);
        autoAddAuxiliaryContacts(myContactor, 5);

        // Turn on the coil to establish links between auxiliary and main contacts
        myContactor.turnOnCoil(true);

        // Print contactor details
        myContactor.printDetails();
    } catch (const std::exception& e) {
        // Handle any exceptions thrown
        handleException(e);
        return 1; // Return error status
    }

    return 0;
}
