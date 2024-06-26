#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "bus.h"
#include "PowerSystemError.h"

class Transformer {
private:
    Bus* primaryBus;
    Bus* secondaryBus;
    double turnsRatio;
    double impedance;
    double primaryVoltageRating;
    double secondaryVoltageRating;
    double powerRating;
    double noLoadLosses;
    double loadLosses;
    double tapSetting;

public:
    // Basic constructor
    Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio);

    // Detailed constructor
    Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double impedance, double primaryVoltageRating, double secondaryVoltageRating, double powerRating, double noLoadLosses, double loadLosses, double tapSetting);

    // Getters and setters
    Bus* getPrimaryBus() const;
    void setPrimaryBus(Bus* bus);

    Bus* getSecondaryBus() const;
    void setSecondaryBus(Bus* bus);

    double getTurnsRatio() const;
    void setTurnsRatio(double ratio);

    double getImpedance() const;
    void setImpedance(double impedance);

    double getPrimaryVoltageRating() const;
    void setPrimaryVoltageRating(double voltage);

    double getSecondaryVoltageRating() const;
    void setSecondaryVoltageRating(double voltage);

    double getPowerRating() const;
    void setPowerRating(double power);

    double getNoLoadLosses() const;
    void setNoLoadLosses(double losses);

    double getLoadLosses() const;
    void setLoadLosses(double losses);

    double getTapSetting() const;
    void setTapSetting(double tap);

    // Other methods
    void applyTurnsRatio() const;
    void calculateEfficiency() const;
    void adjustTap(double newTapSetting);
};

#endif // TRANSFORMER_H
