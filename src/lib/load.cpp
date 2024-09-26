#include "lib/load.h"

// Constructor
Load::Load(const std::string& id, double activePowerDemand, double reactivePowerDemand, 
           LoadType loadType, LoadCategory loadCategory, bool isThreePhase)
    : id(id), activePowerDemand(activePowerDemand), reactivePowerDemand(reactivePowerDemand),
      loadType(loadType), loadCategory(loadCategory), isThreePhase(isThreePhase), 
      connectedLine(nullptr), hasTimeVaryingProfile(false), constantImpedance(0.0), 
      constantCurrent(0.0), constantPower(0.0) {}

// Destructor
Load::~Load() {}

// Get the ID of the load
std::string Load::getId() const {
    return id;
}

// Get the active power demand of the load
double Load::getActivePowerDemand() const {
    return activePowerDemand;
}

// Get the reactive power demand of the load
double Load::getReactivePowerDemand() const {
    return reactivePowerDemand;
}

// Get the apparent power (S = √(P^2 + Q^2)) of the load
double Load::getApparentPower() const {
    return std::sqrt((activePowerDemand * activePowerDemand) + (reactivePowerDemand * reactivePowerDemand));
}

// Add a line to the load (only one line can be connected)
void Load::addLine(const std::shared_ptr<Line>& line) {
    connectedLine = line;
    std::cout << "Line " << line->getId() << " connected to Load " << id << "." << std::endl;
}

// Get the connected line
std::shared_ptr<Line> Load::getConnectedLine() const {
    return connectedLine;
}

// Get the load type (e.g., Residential, Industrial)
LoadType Load::getLoadType() const {
    return loadType;
}

// Get the load category (e.g., Constant Power, Constant Impedance)
LoadCategory Load::getLoadCategory() const {
    return loadCategory;
}

// Check if the load is three-phase or single-phase
bool Load::isThreePhaseLoad() const {
    return isThreePhase;
}

// Set a time-varying power demand function
void Load::setTimeVaryingProfile(std::function<double(double)> profileFunction) {
    timeVaryingPowerDemand = profileFunction;
    hasTimeVaryingProfile = true;
}

// Get power demand at a specific time
double Load::getPowerDemandAtTime(double time) const {
    if (hasTimeVaryingProfile) {
        return timeVaryingPowerDemand(time);
    }
    return activePowerDemand; // Return static demand if no time-varying profile is set
}

// Set ZIP model coefficients
void Load::setZIPModel(double impedanceCoeff, double currentCoeff, double powerCoeff) {
    constantImpedance = impedanceCoeff;
    constantCurrent = currentCoeff;
    constantPower = powerCoeff;
}

// Calculate power demand based on ZIP model
double Load::getPowerDemandUsingZIP(double voltage, double current) const {
    if (constantImpedance <= 0 && constantCurrent <= 0 && constantPower <= 0) {
        // No ZIP model applied, return a default value or throw an exception
        std::cerr << "Warning: ZIP model coefficients are not set. Returning default value." << std::endl;
        return activePowerDemand; // Fallback to static demand
    }
    double powerDemand = constantImpedance * voltage * voltage +
                         constantCurrent * current +
                         constantPower;
    return powerDemand;
}
