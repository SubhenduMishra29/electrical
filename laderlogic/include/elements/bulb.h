// bulb.h
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
    bool isTerminatingElement() const override; // Method to check if the Bulb is a terminating element
};

#endif // BULB_H

