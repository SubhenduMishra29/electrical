#ifndef CONTACT_FUNCTIONS_H
#define CONTACT_FUNCTIONS_H

#include <sstream>
#include "Contactor.h"

// Function to automatically add main contacts with auto-numbering
void autoAddMainContacts(Contactor& contactor, int numContacts);

// Function to automatically add auxiliary contacts with auto-numbering
void autoAddAuxiliaryContacts(Contactor& contactor, int numContacts);

#endif // CONTACT_FUNCTIONS_H
