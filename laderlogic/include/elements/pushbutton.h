// pushbutton.h
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
    PushButton(std::string name, bool state);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName() const override;
    void setState(bool state);

    // Methods for managing connections
    void connectTo(std::shared_ptr<RungElement> element) override;
    void disconnectFrom(std::shared_ptr<RungElement> element) override;
    bool isConnectedTo(std::shared_ptr<RungElement> element) const override;
};

#endif // PUSHBUTTON_H
