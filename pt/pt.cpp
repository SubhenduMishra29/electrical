// PotentialTransformer.cpp

#include "PotentialTransformer.h"

PotentialTransformer::PotentialTransformer(double primaryV, double turns) {
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

