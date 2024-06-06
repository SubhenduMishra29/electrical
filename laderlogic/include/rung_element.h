/*
 * File: rung_element.h
 * Author: Subhendu Mishra
 * Description: Declaration of RungElement class, the base class for elements in a ladder logic rung.
 * License: GPL (General Public License)
 */

#ifndef RUNG_ELEMENT_H
#define RUNG_ELEMENT_H

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

class Wire; // Forward declaration of Wire class

class RungElement {
public:
    virtual bool evaluate(std::unordered_map<std::string, bool>& states) = 0;
    virtual std::string getName() const = 0;
    virtual ~RungElement() = default;

    // Methods for managing connections
    virtual void connectTo(std::shared_ptr<RungElement> element);
    virtual void disconnectFrom(std::shared_ptr<RungElement> element);
    virtual bool isConnectedTo(std::shared_ptr<RungElement> element) const;

protected:
    std::vector<std::shared_ptr<Wire>> connections; // Vector to store connections
};

#endif // RUNG_ELEMENT_H


