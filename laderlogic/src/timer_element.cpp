/*
 * File: timer_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of TimerElement class for managing timer functionality.
 * License: GPL (General Public License)
 */

#ifndef TIMER_ELEMENT_H
#define TIMER_ELEMENT_H

#include <unordered_map>

class TimerElement {
private:
    int duration;
    int counter;
    bool active;

public:
    // Constructor initializes the timer with a given duration.
    TimerElement(int duration);

    // Evaluate the timer based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states);

    // Reset the timer to its initial state.
    void reset();
};

#endif /* TIMER_ELEMENT_H */
