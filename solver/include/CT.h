#ifndef CURRENT_TRANSFORMER_H
#define CURRENT_TRANSFORMER_H

#include "Transformer.h"
#include <string>

class CurrentTransformer : public Transformer {
private:
    double ratedPrimaryCurrent;          // Rated primary current (IP)
    double ratedSecondaryCurrent;        // Rated secondary current (IS)
    double transformationRatio;         // Transformation ratio (R)
    double nominalRatio;                 // Nominal ratio (Kn)
    double turnsRatio;                   // Turns ratio (n)
    double currentRatioError;            // Current ratio error
    double phaseAngleError;              // Phase angle error (degrees)

public:
    // Constructors
    CurrentTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryCurrent, double ratedSecondaryCurrent,
                       double transformationRatio, double nominalRatio, double currentRatioError, double phaseAngleError);

    // Getters and setters for CT-specific attributes
    double getRatedPrimaryCurrent() const;
    void setRatedPrimaryCurrent(double current);

    double getRatedSecondaryCurrent() const;
    void setRatedSecondaryCurrent(double current);

    double getTransformationRatio() const;
    void setTransformationRatio(double ratio);

    double getNominalRatio() const;
    void setNominalRatio(double ratio);

    double getTurnsRatio() const;
    void setTurnsRatio(double ratio);

    double getCurrentRatioError() const;
    void setCurrentRatioError(double error);

    double getPhaseAngleError() const;
    void setPhaseAngleError(double error);

    // Additional methods specific to CT if needed
};

#endif // CURRENT_TRANSFORMER_H
