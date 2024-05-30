// File: contact.cpp
// Author: Subhendu Mishra
// Description: Implementation of the Contact class representing a contact element in ladder logic programming.
// License: GPL (General Public License)

#include "contact.h"

// Constructor initializes the contact element with a name and whether it's normally open or normally closed.
Contact::Contact(std::string name, bool normally_open) : name(name), normally_open(normally_open) {}

// Evaluate the contact element based on the current states.
bool Contact::evaluate(std::unordered_map<std::string, bool>& states) {
    // Retrieve the state of the input associated with this contact from the states map.
    bool state = states[name];
    
    // If the contact is normally open, return its state directly.
    // If the contact is normally closed, return the opposite of its state.
    return normally_open ? state : !state;
}

// Get the name of the contact element.
std::string Contact::getName() const {
    return name;
}
