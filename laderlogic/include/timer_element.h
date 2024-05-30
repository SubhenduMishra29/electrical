/*
 * File: timer_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of TimerElement class representing a timer element in ladder logic programming.
 * License: [License Type]
 */

#ifndef TIMER_ELEMENT_H
#define TIMER_ELEMENT_H

#include "rung_element.h"
#include <unordered_map>

class TimerElement : public RungElement {
private:
    int duration;   // Duration of the timer
    int counter;    // Counter for the timer
    bool active;    // Indicates whether the timer is active

public:
    // Constructor initializes the timer element with a duration.
    TimerElement(int duration);

    // Evaluate the timer element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Reset the timer element to its initial state.
    void reset();
};

#endif // TIMER_ELEMENT_H
