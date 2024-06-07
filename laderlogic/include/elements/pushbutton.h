/*
 * File: pushbutton.h
 * Author: Subhendu Mishra
 * Description: Declaration of the PushButton class representing a push button element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "rung_element.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Wire; // Forward declaration of Wire class

class PushButton : public RungElement {
private:
    std::string name;
    bool state;
    std::vector<std::shared_ptr<Wire>> connections; // Vector to store connections

public:
    // Constructor initializes the push button element with a name and initial state.
    PushButton(std::string name, bool state);

    // Evaluate the push button element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the push button element.
    std::string getName() const override;

    // Set the state of the push button element.
    void setState(bool state);

    // Methods for managing connections
    void connectTo(std::shared_ptr<RungElement> element) override;
    void disconnectFrom(std::shared_ptr<RungElement> element) override;
    bool isConnectedTo(std::shared_ptr<RungElement> element) const override;
};

#endif // PUSHBUTTON_H
