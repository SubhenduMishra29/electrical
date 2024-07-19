#include "lib/CT.h"

// Constructor definition
CurrentTransformer::CurrentTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryCurrent, double ratedSecondaryCurrent,
                                       double transformationRatio, double nominalRatio, double currentRatioError, double phaseAngleError)
    : Transformer(primaryBus, secondaryBus, turnsRatio), ratedPrimaryCurrent(ratedPrimaryCurrent), ratedSecondaryCurrent(ratedSecondaryCurrent),
      transformationRatio(transformationRatio), nominalRatio(nominalRatio), currentRatioError(currentRatioError), phaseAngleError(phaseAngleError) {
    // Additional initialization if needed
}

// Getters and setters
double CurrentTransformer::getRatedPrimaryCurrent() const {
    return ratedPrimaryCurrent;
}

void CurrentTransformer::setRatedPrimaryCurrent(double current) {
    ratedPrimaryCurrent = current;
}

double CurrentTransformer::getRatedSecondaryCurrent() const {
    return ratedSecondaryCurrent;
}

void CurrentTransformer::setRatedSecondaryCurrent(double current) {
    ratedSecondaryCurrent = current;
}

double CurrentTransformer::getTransformationRatio() const {
    return transformationRatio;
}

void CurrentTransformer::setTransformationRatio(double ratio) {
    transformationRatio = ratio;
}

double CurrentTransformer::getNominalRatio() const {
    return nominalRatio;
}

void CurrentTransformer::setNominalRatio(double ratio) {
    nominalRatio = ratio;
}

double CurrentTransformer::getTurnsRatio() const {
    return turnsRatio;
}

void CurrentTransformer::setTurnsRatio(double ratio) {
    turnsRatio = ratio;
}

double CurrentTransformer::getCurrentRatioError() const {
    return currentRatioError;
}

void CurrentTransformer::setCurrentRatioError(double error) {
    currentRatioError = error;
}

double CurrentTransformer::getPhaseAngleError() const {
    return phaseAngleError;
}

void CurrentTransformer::setPhaseAngleError(double error) {
    phaseAngleError = error;
}
