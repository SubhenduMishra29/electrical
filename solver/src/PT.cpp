#include "PotentialTransformer.h"

// Constructor
PotentialTransformer::PotentialTransformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double ratedPrimaryVoltage, double ratedSecondaryVoltage,
                                           double transformationRatio, double nominalRatio, double voltageRatioError, double phaseAngleError)
    : Transformer(primaryBus, secondaryBus, turnsRatio), ratedPrimaryVoltage(ratedPrimaryVoltage), ratedSecondaryVoltage(ratedSecondaryVoltage),
      transformationRatio(transformationRatio), nominalRatio(nominalRatio), voltageRatioError(voltageRatioError), phaseAngleError(phaseAngleError) {
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
