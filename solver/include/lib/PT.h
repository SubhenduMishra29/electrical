#ifndef PT_H
#define PT_H

#include "lib/transformer.h"
#include "lib/bus.h"
#include <string>
class Bus;
class PotentialTransformer : public Transformer {
private:
    double ratedPrimaryVoltage;          // Rated primary voltage (VP)
    double ratedSecondaryVoltage;        // Rated secondary voltage (VS)
    double transformationRatio;          // Transformation ratio (R)
    double nominalRatio;                 // Nominal ratio (Kn)
    double turnsRatio;                   // Turns ratio (n)
    double voltageRatioError;            // Voltage ratio error
    double phaseAngleError;              // Phase angle error (degrees)

public:
    // Constructor
    PotentialTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryVoltage, double ratedSecondaryVoltage, double transformationRatio, double nominalRatio, double voltageRatioError, double phaseAngleError);

    // Getters and setters for PT-specific attributes
    double getRatedPrimaryVoltage() const;
    void setRatedPrimaryVoltage(double voltage);

    double getRatedSecondaryVoltage() const;
    void setRatedSecondaryVoltage(double voltage);

    double getTransformationRatio() const;
    void setTransformationRatio(double ratio);

    double getNominalRatio() const;
    void setNominalRatio(double ratio);

    double getTurnsRatio() const;
    void setTurnsRatio(double ratio);

    double getVoltageRatioError() const;
    void setVoltageRatioError(double error);

    double getPhaseAngleError() const;
    void setPhaseAngleError(double error);

    // Additional methods specific to PT if needed
};

#endif // PT_H
