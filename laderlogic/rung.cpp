#include "rung.h"

void Rung::addElement(std::shared_ptr<RungElement> element) {
    elements.push_back(element);
}

bool Rung::evaluate(std::unordered_map<std::string, bool>& states) {
    bool result = true;

    for (auto& element : elements) {
        result = result && element->evaluate(states);
    }

    return result;
}

void Rung::resetTimers() {
    for (auto& element : elements) {
        if (auto timer = std::dynamic_pointer_cast<TimerElement>(element)) {
            timer->reset();
        }
    }
}

std::vector<std::shared_ptr<RungElement>>& Rung::getElements() {
    return elements;
}


