#include "output_element.h"

OutputElement::OutputElement(std::string name, bool state) : name(name), state(state) {}

bool OutputElement::evaluate(std::unordered_map<std::string, bool>& states) {
    return state;
}

std::string OutputElement::getName() {
    return name;
}

bool OutputElement::getState() {
    return state;
}
