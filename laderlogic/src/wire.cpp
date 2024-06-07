// wire.cpp
#include "wire.h"

Wire::Wire(std::shared_ptr<RungElement> start, std::shared_ptr<RungElement> end)
    : startElement(start), endElement(end) {}

std::shared_ptr<RungElement> Wire::getStartElement() const {
    return startElement;
}

std::shared_ptr<RungElement> Wire::getEndElement() const {
    return endElement;
}
