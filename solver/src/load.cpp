// load.cpp

#include "load.h"

Load::Load(double powerConsumption, std::string type) {
    this->powerConsumption = powerConsumption;
    this->type = type;
}

double Load::getPowerConsumption() {
    return powerConsumption;
}
