#ifndef BUS_H
#define BUS_H

#include <vector>
#include <string>

enum BusType {
    SLACK,    // Slack bus
    PV,       // Generator bus
    PQ        // Load bus
};

struct Generator {
    double activePower;       // Active power output in pu
    double reactivePower;     // Reactive power output in pu
    double maxReactivePower;  // Maximum reactive power limit
    double minReactivePower;  // Minimum reactive power limit
};

struct Load {
    double activePowerDemand;       // Active power demand in pu
    double reactivePowerDemand;     // Reactive power demand in pu
};

class Bus {
public:
    Bus(int id, const std::string& name, BusType type);

    // Getters
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

    // Setters
    void setVoltageMagnitude(double voltageMagnitude);
    void setVoltageAngle(double voltageAngle);
    void setRealPowerInjection(double realPowerInjection);
    void setReactivePowerInjection(double reactivePowerInjection);
    void addConnectedBus(int busId);
    void addGenerator(const Generator& generator);
    void addLoad(const Load& load);

private:
    int id;                             // Bus ID
    std::string name;                   // Bus name or identifier
    BusType type;                       // Type of the bus (SLACK, PV, PQ)
    double voltageMagnitude;            // Voltage magnitude in per unit (pu)
    double voltageAngle;                // Voltage angle in degrees
    double realPowerInjection;          // Real power injection in pu
    double reactivePowerInjection;      // Reactive power injection in pu
    std::vector<int> connectedBuses;    // List of connected buses (for adjacency representation)
    std::vector<Generator> generators;  // List of generators connected to the bus
    std::vector<Load> loads;            // List of loads connected to the bus
};

#endif // BUS_H
