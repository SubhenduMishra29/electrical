#ifndef RUNG_ELEMENT_H
#define RUNG_ELEMENT_H

#include <string>
#include <unordered_map>

class RungElement {
public:
    virtual bool evaluate(std::unordered_map<std::string, bool>& states) = 0;
    virtual std::string getName() const = 0;
    virtual ~RungElement() = default;
};

#endif // RUNG_ELEMENT_H
