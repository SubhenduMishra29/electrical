// lib/Attribute.h
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class Attribute {
public:
    std::string key;
    std::string value;

    Attribute(const std::string& key, const std::string& value) : key(key), value(value) {}
};

#endif // ATTRIBUTE_H
