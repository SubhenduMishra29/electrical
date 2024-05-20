#include "ContactFunctions.h"

void autoAddMainContacts(Contactor& contactor, int numContacts) {
    for (int i = 1; i <= numContacts; ++i) {
        std::stringstream ss;
        ss << "Material " << i;
        contactor.addMainContact(ss.str(), i * 10.0, i * 5.0, 100.0);
    }
}

void autoAddAuxiliaryContacts(Contactor& contactor, int numContacts) {
    for (int i = 1; i <= numContacts; ++i) {
        std::stringstream ss;
        ss << "Contact " << i;
        contactor.addAuxiliaryContact("NC", ss.str(), i * 10.0, i * 5.0, 50.0);
    }
}
