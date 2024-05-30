/*
 * File: pushbutton.h
 * Author: Subhendu Mishra
 * Description: Declaration of PushButton class for representing a push button element.
 * License: GPL (General Public License)
 */

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <string>
#include <unordered_map>
#include "rung_element.h"

class PushButton : public RungElement {
private:
    std::string name;
    bool state;

public:
    // Constructor initializes the push button with a name and initial state.
    PushButton(std::string name, bool state);

    // Evaluate the push button and update its state in the states map.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the push button.
    std::string getName() const;

    // Set the state of the push button.
    void setState(bool state);
};

#endif /* PUSHBUTTON_H */
