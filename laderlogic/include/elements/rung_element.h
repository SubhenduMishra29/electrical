/*
 * File: rung_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of the RungElement class, the base class for elements in a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_ELEMENT_H
#define RUNG_ELEMENT_H

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

class Wire; // Forward declaration of Wire class

// Base class for an element in a rung
class RungElement : public std::enable_shared_from_this<RungElement> {
public:
    // Pure virtual function to evaluate the element
    virtual bool evaluate(std::unordered_map<std::string, bool>& states) = 0;

    // Pure virtual function to get the name of the element
    virtual std::string getName() const = 0;

    // Pure virtual function to check if the element is a terminating element
    virtual bool isTerminatingElement() const = 0;

    // Destructor
    virtual ~RungElement() = default;

    // Connect this element to another element
    virtual void connectTo(std::shared_ptr<RungElement> element);

    // Check if this element is connected to another element
    virtual bool isConnectedTo(std::shared_ptr<RungElement> element) const;

protected:
    std::vector<std::shared_ptr<Wire>> connections; // Vector to store connections
};

#endif // RUNG_ELEMENT_H


