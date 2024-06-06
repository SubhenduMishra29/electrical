/*
 * File: rung.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Rung class representing a ladder logic rung.
 * License: GPL (General Public License)
 */

#include "rung.h"
#include "rung_submodule.h"

void Rung::addElement(std::shared_ptr<RungElement> element) {
    elements.push_back(element);
}

void Rung::addSubmodule(std::shared_ptr<RungSubmodule> submodule) {
    submodules.push_back(submodule);
}

bool Rung::evaluate(std::unordered_map<std::string, bool>& states) {
    for (const auto& element : elements) {
        if (!element->evaluate(states)) {
            return false;
        }
    }
    for (const auto& submodule : submodules) {
        if (!submodule->evaluate(states)) {
            return false;
        }
    }
    return true;
}

std::vector<std::shared_ptr<RungElement>>& Rung::getElements() {
    return elements;
}

std::vector<std::shared_ptr<RungSubmodule>>& Rung::getSubmodules() {
    return submodules;
}

