#ifndef RUNG_H
#define RUNG_H

#include <vector>
#include <memory>
#include "rung_element.h"

class Rung {
private:
    std::vector<std::shared_ptr<RungElement>> elements;

public:
    void addElement(std::shared_ptr<RungElement> element);
    bool evaluate(std::unordered_map<std::string, bool>& states);
    void resetTimers();
    std::vector<std::shared_ptr<RungElement>>& getElements();
};

#endif // RUNG_H
