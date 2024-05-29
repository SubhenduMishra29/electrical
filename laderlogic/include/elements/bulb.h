#ifndef BULB_H
#define BULB_H

#include "rung_element.h"

class Bulb : public RungElement {
private:
    std::string name;

public:
    Bulb(std::string name);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName() const override;
};

#endif // BULB_H
