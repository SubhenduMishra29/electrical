//contact.cpp
#include "contact.h"

Contact::Contact(std::string name, bool normally_open) : name(name), normally_open(normally_open) {}

bool Contact::evaluate(std::unordered_map<std::string, bool>& states) {
    bool state = states[name];
    return normally_open ? state : !state;
}

std::string Contact::getName() const {
    return name;
}
