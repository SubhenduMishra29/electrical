#include <iostream>
#include "Contactor.h"
#include "State.h"
#include "MainContact.h"
#include "AuxiliaryContact.h"

// Function to automatically add main contacts with auto-numbering
void autoAddMainContacts(Contactor& contactor, int numContacts) {
    for (int i = 1; i <= numContacts; ++i) {
        std::stringstream ss;
        ss << "Material " << i;
        contactor.addMainContact(ss.str(), i * 10.0, i * 5.0, 100.0); // Assuming a max current rating of 100 A for each main contact
    }
}

// Function to automatically add auxiliary contacts with auto-numbering
void autoAddAuxiliaryContacts(Contactor& contactor, int numContacts) {
    for (int i = 1; i <= numContacts; ++i) {
        std::stringstream ss;
        ss << "Contact " << i;
        contactor.addAuxiliaryContact("NC", ss.str(), i * 10.0, i * 5.0, 50.0); // Assuming a max current rating of 50 A for each auxiliary contact
    }
}

int main() {
    // Create a Contactor object
    Contactor myContactor("ABC Inc.", "Model XYZ");

    // Automatically add main and auxiliary contacts
    autoAddMainContacts(myContactor, 3);
    autoAddAuxiliaryContacts(myContactor, 5);

    // Turn on the coil to establish links between auxiliary and main contacts
    myContactor.turnOnCoil(true);

    // Print contactor details
    myContactor.printDetails();

    return 0;
}
