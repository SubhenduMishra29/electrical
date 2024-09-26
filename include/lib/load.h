#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include <cmath>
#include "Line.h"

// Enums for load types and categories
enum class LoadType {
    RESIDENTIAL,
    INDUSTRIAL,
    COMMERCIAL
};

enum class LoadCategory {
    CONSTANT_POWER,
    CONSTANT_CURRENT,
    CONSTANT_IMPEDANCE,
    ZIP
};

// Class representing a complex load in the power system.
class Load {
private:
    std::string id; ///< Unique identifier for the load
    double activePowerDemand; ///< Active power demand in MW
    double reactivePowerDemand; ///< Reactive power demand in MVAR
    LoadType loadType; ///< Type of load (e.g., Residential, Industrial)
    LoadCategory loadCategory; ///< Category of load (e.g., Constant Power, Constant Impedance)
    bool isThreePhase; ///< True if the load is three-phase, False if single-phase
    std::shared_ptr<Line> connectedLine; ///< The line connected to the load

    // Time-varying profile function
    std::function<double(double)> timeVaryingPowerDemand; ///< Function to get power demand based on time
    bool hasTimeVaryingProfile; ///< Flag indicating if a time-varying profile is set

    // ZIP Model coefficients
    double constantImpedance; ///< Coefficient for constant impedance load
    double constantCurrent; ///< Coefficient for constant current load
    double constantPower; ///< Coefficient for constant power load

public:
    // Constructor
    Load(const std::string& id, double activePowerDemand, double reactivePowerDemand, 
         LoadType loadType, LoadCategory loadCategory, bool isThreePhase);

    // Destructor
    ~Load();

    // Get the ID of the load
    std::string getId() const;

    // Get the active power demand of the load
    double getActivePowerDemand() const;

    // Get the reactive power demand of the load
    double getReactivePowerDemand() const;

    // Get the total apparent power (S) of the load
    double getApparentPower() const;

    // Add a line connected to the load (only one line can be connected)
    void addLine(const std::shared_ptr<Line>& line);

    // Get the connected line
    std::shared_ptr<Line> getConnectedLine() const;

    // Get the load type (e.g., Residential, Industrial)
    LoadType getLoadType() const;

    // Get the load category (e.g., Constant Power, Constant Impedance)
    LoadCategory getLoadCategory() const;

    // Check if the load is three-phase or single-phase
    bool isThreePhaseLoad() const;

    // Set a time-varying power demand function
    void setTimeVaryingProfile(std::function<double(double)> profileFunction);

    // Get power demand at a specific time
    double getPowerDemandAtTime(double time) const;

    // Set ZIP model coefficients
    void setZIPModel(double impedanceCoeff, double currentCoeff, double powerCoeff);

    // Calculate power demand based on ZIP model
    double getPowerDemandUsingZIP(double voltage, double current) const;
};

#endif // LOAD_H
