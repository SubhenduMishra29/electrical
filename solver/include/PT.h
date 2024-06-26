#ifndef POTENTIAL_TRANSFORMER_H
#define POTENTIAL_TRANSFORMER_H

#include "Transformer.h"

class PotentialTransformer : public Transformer {
private:
    double ratedPrimaryVoltage;
    double ratedSecondaryVoltage;

public:
    PotentialTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryVoltage, double ratedSecondaryVoltage);

    double getRatedPrimaryVoltage() const;
    void setRatedPrimaryVoltage(double voltage);

    double getRatedSecondaryVoltage() const;
    void setRatedSecondaryVoltage(double voltage);

    // Additional methods specific to PT if needed
};

#endif // POTENTIAL_TRANSFORMER_H
