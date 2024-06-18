#ifndef CAPACITOR_H
#define CAPACITOR_H

#include <string>

class Capacitor {
private:
    std::string id;
    double capacitance; // in Farads

public:
    Capacitor(const std::string& id, double capacitance);
    ~Capacitor();

    std::string getId() const;
    double getCapacitance() const;
};

#endif // CAPACITOR_H
