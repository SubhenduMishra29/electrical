/*
 * File: contact.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Contact class representing a contact element in ladder logic programming.
 * License: GPL (General Public License)
 */

#ifndef CONTACT_H
#define CONTACT_H

#include "rung_element.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Wire; // Forward declaration of Wire class
class CoilElement; // Forward declaration of CoilElement class

class Contact : public RungElement {
private:
    std::string name;
    bool normallyOpen;
    std::vector<std::shared_ptr<Wire>> connections; // Vector to store connections
    std::shared_ptr<CoilElement> linkedCoil; // Pointer to the linked coil element

public:
    // Constructor initializes the contact element with a name and whether it is normally open or not.
    Contact(std::string name, bool normallyOpen);

    // Evaluate the contact element based on the current states.
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    // Get the name of the contact element.
    std::string getName() const override;

    // Methods for managing connections
    void connectTo(std::shared_ptr<RungElement> element) override;
    void disconnectFrom(std::shared_ptr<RungElement> element) override;
    bool isConnectedTo(std::shared_ptr<RungElement> element) const override;

    // Link the contact to a coil element
    void linkToCoil(std::shared_ptr<CoilElement> coil);
};

#endif // CONTACT_H
