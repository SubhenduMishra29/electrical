#ifndef POTENTIAL_TRANSFORMER_H
#define POTENTIAL_TRANSFORMER_H

#include "Transformer.h"

class PotentialTransformer : public Transformer {
private:
    double ratedPrimaryVoltage;          // Rated primary voltage
    double ratedSecondaryVoltage;        // Rated secondary voltage
    double transformationRatio;          // Transformation ratio (R)
    double nominalRatio;                 // Nominal ratio (Kn)
    double turnsRatio;                   // Turns ratio (n)
    double voltageRatioError;            // Voltage ratio error
    double phaseAngleError;              // Phase angle error (degrees)

public:
    // Constructors
    PotentialTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryVoltage, double ratedSecondaryVoltage,
                         double transformationRatio, double nominalRatio, double voltageRatioError, double phaseAngleError);

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

#endif // POTENTIAL_TRANSFORMER_H
