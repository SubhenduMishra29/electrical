#ifndef CONTACT_H
#define CONTACT_H

#include "rung_element.h"

class Contact : public RungElement {
private:
    std::string name;
    bool normally_open;

public:
    Contact(std::string name, bool normally_open);
    bool evaluate(std::unordered_map<std::string, bool>& states) override;
    std::string getName() const override;
};

#endif // CONTACT_H
