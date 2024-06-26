#ifndef CURRENT_TRANSFORMER_H
#define CURRENT_TRANSFORMER_H

#include "Transformer.h"

class CurrentTransformer : public Transformer {
private:
    double ratedPrimaryCurrent;
    double ratedSecondaryCurrent;

public:
    CurrentTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryCurrent, double ratedSecondaryCurrent);

    double getRatedPrimaryCurrent() const;
    void setRatedPrimaryCurrent(double current);

    double getRatedSecondaryCurrent() const;
    void setRatedSecondaryCurrent(double current);

    // Additional methods specific to CT if needed
};

#endif // CURRENT_TRANSFORMER_H
