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
 * @param contactor Reference to the Contactor object.
 * @param numContacts Number of main contacts to add.
 */
void autoAddMainContacts(Contactor& contactor, int numContacts);

/**
 * @brief Function to automatically add auxiliary contacts with auto-numbering.
 * @param contactor Reference to the Contactor object.
 * @param numContacts Number of auxiliary contacts to add.
 */
void autoAddAuxiliaryContacts(Contactor& contactor, int numContacts);

#endif // CONTACT_FUNCTIONS_H

