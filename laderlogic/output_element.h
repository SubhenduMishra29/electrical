#ifndef OUTPUT_ELEMENT_H
#define OUTPUT_ELEMENT_H

#include "rung_element.h"

class OutputElement : public RungElement {
private:
    std::string name;
    bool state;

public:
    OutputElement(std::string name, bool state);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName();
    bool getState();
};

#endif // OUTPUT_ELEMENT_H
