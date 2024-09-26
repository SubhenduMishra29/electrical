#include "lib/components/PT.h"

// Constructor definition
PotentialTransformer::PotentialTransformer(double transformationRatio, double nominalRatio, double voltageRatioError, double phaseAngleError)
    : Transformer("default_id", 1.0) // Initialize with a default ID and ratio
    , transformationRatio(transformationRatio)
    , nominalRatio(nominalRatio)
    , voltageRatioError(voltageRatioError)
    , phaseAngleError(phaseAngleError) {
    // Additional initialization if needed
}

// Getters and setters
double PotentialTransformer::getRatedPrimaryVoltage() const {
    return ratedPrimaryVoltage;
}

void PotentialTransformer::setRatedPrimaryVoltage(double voltage) {
    ratedPrimaryVoltage = voltage;
}

double PotentialTransformer::getRatedSecondaryVoltage() const {
    return ratedSecondaryVoltage;
}

void PotentialTransformer::setRatedSecondaryVoltage(double voltage) {
    ratedSecondaryVoltage = voltage;
}

double PotentialTransformer::getTransformationRatio() const {
    return transformationRatio;
}

void PotentialTransformer::setTransformationRatio(double ratio) {
    transformationRatio = ratio;
}

double PotentialTransformer::getNominalRatio() const {
    return nominalRatio;
}

void PotentialTransformer::setNominalRatio(double ratio) {
    nominalRatio = ratio;
}

double PotentialTransformer::getTurnsRatio() const {
    return turnsRatio;
}

void PotentialTransformer::setTurnsRatio(double ratio) {
    turnsRatio = ratio;
}

double PotentialTransformer::getVoltageRatioError() const {
    return voltageRatioError;
}

void PotentialTransformer::setVoltageRatioError(double error) {
    voltageRatioError = error;
}

double PotentialTransformer::getPhaseAngleError() const {
    return phaseAngleError;
}

void PotentialTransformer::setPhaseAngleError(double error) {
    phaseAngleError = error;
}
