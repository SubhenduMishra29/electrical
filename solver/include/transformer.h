#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "bus.h"
#include "PowerSystemError.h"

class Transformer {
private:
    Bus* primaryBus;
    Bus* secondaryBus;
    double turnsRatio;

public:
    Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio);
    void applyTurnsRatio();
};

#endif // TRANSFORMER_H
