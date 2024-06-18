#ifndef REACTOR_H
#define REACTOR_H

#include <string>

class Reactor {
private:
    std::string id;
    double inductance; // in Henrys

public:
    Reactor(const std::string& id, double inductance);
    ~Reactor();

    std::string getId() const;
    double getInductance() const;
};

#endif // REACTOR_H
