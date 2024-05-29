#include "logic_element.h"

LogicElement::LogicElement(std::string name, bool state, LogicType type) : name(name), state(state), type(type) {}

bool LogicElement::evaluate(std::unordered_map<std::string, bool>& states) {
    if (states.find(name) == states.end()) {
        return false;
    }

    bool input_state = states[name];
    switch (type) {
        case AND:
            return input_state && state;
        case OR:
            return input_state || state;
        case NOT:
            return !input_state;
        default:
            return false;
    }
}
