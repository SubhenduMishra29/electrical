#ifndef CT_H
#define CT_H

/**
 * Author: Subhendu Mishra
 * License: GPL
 * Current Transformers (CTs)
 *  ratio: The transformation ratio between primary and secondary currents.
 *  accuracy_class: Defines the accuracy of the CT for measurement and protection purposes.
 *  burden: The maximum load that the CT can handle without significant errors.
 *  insulation_level: The voltage level for which the CT’s insulation is rated.
 *  core_type: Type of core used (e.g., Toroidal, E-I) affects the accuracy and saturation characteristics.
 *  temperature_rating: Maximum operating temperature.
 *  insulation_material: Material used for insulation, influencing durability and performance.
 *  response_time: Time taken for the CT to respond to changes in current.
 *  current_rating: Rated primary and secondary currents for accurate measurement.
 *  frequency: The frequency at which the CT operates.
 *  saturation_current: Current at which the CT core starts to saturate.
 *  test_condition: Type of test conducted to ensure the CT meets standards.
 *  protection_class: Class defining the CT’s suitability for protection applications.
 */

#include "lib/transformer.h"
#include <string>

class CurrentTransformer : public Transformer {
private:
    double ratedPrimaryCurrent;          // Rated primary current (IP)
    double ratedSecondaryCurrent;        // Rated secondary current (IS)
    double transformationRatio;          // Transformation ratio (R)
    double nominalRatio;                 // Nominal ratio (Kn)
    double turnsRatio;                   // Turns ratio (n)
    double currentRatioError;            // Current ratio error
    double phaseAngleError;              // Phase angle error (degrees)

public:
    // Constructor
    CurrentTransformer(double transformationRatio, double nominalRatio, double currentRatioError, double phaseAngleError);

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

#endif // CT_H
