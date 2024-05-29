#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "rung_element.h"

class PushButton : public RungElement {
private:
    std::string name;
    bool state;

public:
    PushButton(std::string name, bool state);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName() const override;
    void setState(bool state);
};

#endif // PUSHBUTTON_H
