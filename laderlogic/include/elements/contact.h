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
class Coil; // Forward declaration of Coil class

/**
 * @brief The Contact class represents a contact element in ladder logic programming.
 */
class Contact : public RungElement {
private:
    std::string name; ///< Name of the contact element
    bool normallyOpen; ///< Flag indicating whether the contact is normally open
    std::vector<std::shared_ptr<Wire>> connections; ///< Vector to store connections
    std::shared_ptr<Coil> linkedCoil; ///< Pointer to the linked coil

public:
    /**
     * @brief Constructor for Contact class.
     * @param name Name of the contact element
     * @param normallyOpen Flag indicating whether the contact is normally open
     */
    Contact(std::string name, bool normallyOpen);

    /**
     * @brief Evaluate the contact element based on the current states.
     * @param states Map containing the current states of the inputs.
     * @return The evaluated state of the contact element.
     */
    bool evaluate(std::unordered_map<std::string, bool>& states) override;

    /**
     * @brief Get the name of the contact element.
     * @return The name of the contact element.
     */
    std::string getName() const override;

    /**
     * @brief Connect the contact to a specified element.
     * @param element The element to connect to.
     */
    void connectTo(std::shared_ptr<RungElement> element) override;

    /**
     * @brief Disconnect the contact from a specified element.
     * @param element The element to disconnect from.
     */
    void disconnectFrom(std::shared_ptr<RungElement> element) override;

    /**
     * @brief Check if the contact is connected to a specified element.
     * @param element The element to check for connection.
     * @return True if the contact is connected to the specified element, otherwise false.
     */
    bool isConnectedTo(std::shared_ptr<RungElement> element) const override;

    /**
     * @brief Link the contact to a coil.
     * @param coil The coil to link to.
     */
    void linkToCoil(std::shared_ptr<Coil> coil);

    /**
     * @brief Check if the contact is linked to a coil.
     * @return True if the contact is linked to a coil, otherwise false.
     */
    bool isLinkedToCoil() const;
};

#endif // CONTACT_H
