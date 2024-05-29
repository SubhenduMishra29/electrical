#ifndef TIMER_ELEMENT_H
#define TIMER_ELEMENT_H

#include "rung_element.h"

class TimerElement : public RungElement {
private:
    int duration;
    int counter;
    bool active;

public:
    TimerElement(int duration);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    void reset();
};

#endif // TIMER_ELEMENT_H
