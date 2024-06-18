// load.h

#ifndef LOAD_H
#define LOAD_H

#include <string>

class Load {
private:
    double powerConsumption;  // in MW
    std::string type;

public:
    Load(double powerConsumption, std::string type);
    double getPowerConsumption();
};

#endif // LOAD_H
