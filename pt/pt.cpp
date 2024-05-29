// PotentialTransformer.cpp

#include "PotentialTransformer.h"

PotentialTransformer::PotentialTransformer(double primaryV, double turns) {
    if (turns <= 0) {
        throw std::invalid_argument("Turns ratio must be greater than zero");
    }
    
    primaryVoltage = primaryV;
    turnsRatio = turns;
    secondaryVoltage = primaryVoltage / turnsRatio;
}

double PotentialTransformer::getPrimaryVoltage() {
    return primaryVoltage;
}

double PotentialTransformer::getSecondaryVoltage() {
    return secondaryVoltage;
}

