/*
 * File: ContactFunctions.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef CONTACT_FUNCTIONS_H
#define CONTACT_FUNCTIONS_H

#include <sstream>
#include "Contactor.h"

/**
 * @brief Function to automatically add main contacts with auto-numbering.
 * @param contactor The Contactor object to which main contacts are added.
 * @param numContacts Number of main contacts to add.
 */
void autoAddMainContacts(Contactor& contactor, int numContacts) {
    for (int i = 1; i <= numContacts; ++i) {
        std::stringstream ss;
        ss << "MainContact " << i;
        contactor.addMainContact(ss.str(), i+100, "OutPort", 100.0); // Example parameters
    }
}

/**
 * @brief Function to automatically add auxiliary contacts with auto-numbering.
 * @param contactor The Contactor object to which auxiliary contacts are added.
 * @param numContacts Number of auxiliary contacts to add.
 */
void autoAddAuxiliaryContacts(Contactor& contactor, int numContacts) {
    for (int i = 1; i <= numContacts; ++i) {
        std::stringstream ss;
        ss << "AuxContact " << i;
        contactor.addAuxiliaryContact(ss.str(), i+200, "OutPort", "NC", 50.0); // Example parameters
    }
}

#endif // CONTACT_FUNCTIONS_H
