#ifndef RELAY_H
#define RELAY_H

#include <string>

class Relay {
private:
    std::string id;
    double setting; // in Amps

public:
    Relay(const std::string& id, double setting);
    ~Relay();

    std::string getId() const;
    double getSetting() const;
};

#endif // RELAY_H
