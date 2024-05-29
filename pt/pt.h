// PotentialTransformer.h

#ifndef POTENTIAL_TRANSFORMER_H
#define POTENTIAL_TRANSFORMER_H

class PotentialTransformer {
private:
    double primaryVoltage;
    double secondaryVoltage;
    double turnsRatio;

public:
    PotentialTransformer(double primaryV, double turns);
    double getPrimaryVoltage();
    double getSecondaryVoltage();
};

#endif

