// Load.h
#ifndef LOAD_H
#define LOAD_H
#include "PowerSystemError.h"
class Load {
public:
    double activePowerDemand;
    double reactivePowerDemand;

    Load(double activePowerDemand, double reactivePowerDemand)
        : activePowerDemand(activePowerDemand), reactivePowerDemand(reactivePowerDemand) {}
};

#endif // LOAD_H
