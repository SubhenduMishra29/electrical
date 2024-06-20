#ifndef LOAD_H
#define LOAD_H

#include <string>
#include "PowerSystemError.h"

class Load {
private:
    std::string id;
    double powerDemand; // in MW

public:
    Load(const std::string& id, double powerDemand);
    ~Load();

    std::string getId() const;
    double getPowerDemand() const;
};

#endif // LOAD_H
