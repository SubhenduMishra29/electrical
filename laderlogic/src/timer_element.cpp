#include "timer_element.h"

TimerElement::TimerElement(int duration) : duration(duration), counter(0), active(false) {}

bool TimerElement::evaluate(std::unordered_map<std::string, bool>& states) {
    if (!active) {
        active = true;
        counter = 0;
    }

    if (counter >= duration) {
        active = false;
        return true;
    } else {
        counter++;
        return false;
    }
}

void TimerElement::reset() {
    counter = 0;
    active = false;
}
