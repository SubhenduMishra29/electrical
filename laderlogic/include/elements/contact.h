// contact.h
#ifndef CONTACT_H
#define CONTACT_H

#include "rung_element.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Wire; // Forward declaration of Wire class

class Contact : public RungElement {
private:
    std::string name;
    bool normallyOpen;
    std::vector<std::shared_ptr<Wire>> connections; // Vector to store connections

public:
    Contact(std::string name, bool normallyOpen);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName() const override;

    // Methods for managing connections
    void connectTo(std::shared_ptr<RungElement> element) override;
    void disconnectFrom(std::shared_ptr<RungElement> element) override;
    bool isConnectedTo(std::shared_ptr<RungElement> element) const override;
};

#endif // CONTACT_H

