#ifndef LOGIC_ELEMENT_H
#define LOGIC_ELEMENT_H

#include "rung_element.h"

enum LogicType { AND, OR, NOT };

class LogicElement : public RungElement {
private:
    std::string name;
    bool state;
    LogicType type;

public:
    LogicElement(std::string name, bool state, LogicType type);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
};

#endif // LOGIC_ELEMENT_H
