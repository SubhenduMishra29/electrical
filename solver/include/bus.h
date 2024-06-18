// bus.h
#ifndef BUS_H
#define BUS_H

#include <vector>
#include <string>
#include <utility>
#include "BusType.h"
#include "Generator.h"
#include "Load.h"

class Bus {
private:
    int id;
    std::string name;
    BusType type;
    double voltageMagnitude;
    double voltageAngle;
    double realPowerInjection;
    double reactivePowerInjection;
    bool isSlack;
    std::vector<int> connectedBuses;
    std::vector<Generator> generators;
    std::vector<Load> loads;

public:
    Bus(int id, const std::string& name, BusType type);

    int getId() const;
    std::string getName() const;
    BusType getType() const;
    double getVoltageMagnitude() const;
    double getVoltageAngle() const;
    double getRealPowerInjection() const;
    double getReactivePowerInjection() const;
    std::vector<int> getConnectedBuses() const;
    std::vector<Generator> getGenerators() const;
    std::vector<Load> getLoads() const;

    void setVoltageMagnitude(double voltageMagnitude);
    void setVoltageAngle(double voltageAngle);
    void setRealPowerInjection(double realPowerInjection);
    void setReactivePowerInjection(double reactivePowerInjection);
    void addConnectedBus(int busId);
    void addGenerator(const Generator& generator);
    void addLoad(const Load& load);

    std::pair<double, double> calculateTotalLoad() const;
    std::pair<double, double> calculateTotalGeneration() const;
};

#endif // BUS_H
