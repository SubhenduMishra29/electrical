#ifndef COIL_H
#define COIL_H

#include "rung_element.h"

class Coil : public RungElement {
private:
    std::string name;

public:
    Coil(std::string name);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName() const override;
};

#endif // COIL_H
