// wire.h
#ifndef WIRE_H
#define WIRE_H

#include <memory>
#include "rung_element.h"

class Wire {
private:
    std::shared_ptr<RungElement> startElement;
    std::shared_ptr<RungElement> endElement;

public:
    Wire(std::shared_ptr<RungElement> start, std::shared_ptr<RungElement> end);
    std::shared_ptr<RungElement> getStartElement() const;
    std::shared_ptr<RungElement> getEndElement() const;
};

#endif // WIRE_H
