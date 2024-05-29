#include "pushbutton.h"

PushButton::PushButton(std::string name, bool state) : name(name), state(state) {}

bool PushButton::evaluate(std::unordered_map<std::string, bool>& states) {
    states[name] = state;
    return state;
}

std::string PushButton::getName() const {
    return name;
}

void PushButton::setState(bool state) {
    this->state = state;
}
