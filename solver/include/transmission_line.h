#ifndef TRANSMISSION_LINE_H
#define TRANSMISSION_LINE_H

#include <string>
#include "PowerSystemError.h"

class TransmissionLine {
private:
    std::string id;
    double length; // in km
    double impedance; // in ohms

public:
    TransmissionLine(const std::string& id, double length, double impedance);
    ~TransmissionLine();

    std::string getId() const;
    double getLength() const;
    double getImpedance() const;
};

#endif // TRANSMISSION_LINE_H
