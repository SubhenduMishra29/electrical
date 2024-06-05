#include "rung.h"
#include <stdexcept>
#include <iostream>

void Rung::addElement(std::shared_ptr<RungElement> element) {
    if (!element) {
        throw std::invalid_argument("Cannot add a null element to the rung.");
    }
    if (branches.empty()) {
        branches.push_back({});
    }
    branches[0].push_back(element);
}

void Rung::addBranch(const std::vector<std::shared_ptr<RungElement>>& branch) {
    for (const auto& element : branch) {
        if (!element) {
            throw std::invalid_argument("Cannot add a null element to the branch.");
        }
    }
    branches.push_back(branch);
}

bool Rung::evaluate(std::unordered_map<std::string, bool>& states) {
    try {
        for (const auto& branch : branches) {
            bool branchResult = true;
            for (const auto& element : branch) {
                if (!element) {
                    throw std::runtime_error("Encountered null element during evaluation.");
                }
                if (!element->evaluate(states)) {
                    branchResult = false;
                    break;
                }
            }
            if (branchResult) {
                return true;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error evaluating rung: " << e.what() << std::endl;
        return false;
    }
    return false;
}

std::vector<std::vector<std::shared_ptr<RungElement>>>& Rung::getBranches() {
    if (branches.empty()) {
        throw std::runtime_error("No branches in the rung.");
    }
    return branches;
}
