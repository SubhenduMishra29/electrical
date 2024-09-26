#ifndef PT_H
#define PT_H

/**
 * Potential Transformers (PTs)
 *  ratio: The transformation ratio between primary and secondary voltages.
 *  accuracy_class: Defines the accuracy of the PT for measurement and protection purposes.
 *  burden: The maximum load that the PT can handle without significant errors.
 *  insulation_level: The voltage level for which the PT’s insulation is rated.
 *  core_type: Type of core used (e.g., Shielded, Open Core) affects the accuracy and performance.
 *  temperature_rating: Maximum operating temperature.
 *  insulation_material: Material used for insulation, influencing durability and performance.
 *  response_time: Time taken for the PT to respond to changes in voltage.
 *  primary_voltage: Rated primary voltage.
 *  secondary_voltage: Rated secondary voltage.
 *  frequency: The frequency at which the PT operates.
 *  voltage_accuracy: Accuracy of the voltage measurement.
 *  test_condition: Type of test conducted to ensure the PT meets standards.
 *  protection_class: Class defining the PT’s suitability for protection applications.
 */

#include "lib/transformer.h"
#include <string>

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
    PotentialTransformer(double transformationRatio, double nominalRatio, double voltageRatioError, double phaseAngleError);

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
