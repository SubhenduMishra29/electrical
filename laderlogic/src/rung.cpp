#include "rung.h"
#include <stdexcept>
#include <iostream>

void Rung::addElement(std::shared_ptr<RungElement> element) {
    if (!element) {
        throw std::invalid_argument("Cannot add a null element to the rung.");
    }
    elements.push_back(element);
}

bool Rung::evaluate(std::unordered_map<std::string, bool>& states) {
    try {
        for (const auto& element : elements) {
            if (!element) {
                throw std::runtime_error("Encountered null element during evaluation.");
            }
            if (!element->evaluate(states)) {
                return false;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error evaluating rung: " << e.what() << std::endl;
        return false;
    }
    return true;
}

std::vector<std::shared_ptr<RungElement>>& Rung::getElements() {
    if (elements.empty()) {
        throw std::runtime_error("No elements in the rung.");
    }
    return elements;
}
