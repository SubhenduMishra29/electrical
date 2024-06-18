//transformer.cpp
#include "transformer.h"

Transformer::Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio) {
    this->primaryBus = primaryBus;
    this->secondaryBus = secondaryBus;
    this->turnsRatio = turnsRatio;
}

void Transformer::applyTurnsRatio() {
    // Implement transformer behavior to adjust voltages based on turns ratio
    double primaryVoltage = primaryBus->getVoltage();
    double secondaryVoltage = primaryVoltage * turnsRatio;
    secondaryBus->setVoltage(secondaryVoltage);
}
