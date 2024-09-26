#include "lib/components/CT.h"

// Constructor definition
CurrentTransformer::CurrentTransformer(double transformationRatio, double nominalRatio, double currentRatioError, double phaseAngleError)
    : Transformer("default_id", 1.0) // Initialize with a default ID and ratio
    , transformationRatio(transformationRatio)
    , nominalRatio(nominalRatio)
    , currentRatioError(currentRatioError)
    , phaseAngleError(phaseAngleError) {
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
