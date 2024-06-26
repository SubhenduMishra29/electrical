#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "bus.h"
#include "PowerSystemError.h"

class Transformer {
private:
    Bus* primaryBus;
    Bus* secondaryBus;
    double turnsRatio;
    double impedance;
    double primaryVoltageRating;
    double secondaryVoltageRating;
    double powerRating;
    double noLoadLosses;
    double loadLosses;
    double tapSetting;
    std::string oilType;
    std::string coolingType;
    bool buchholzRelay;
    std::string neutralPointConfiguration;
    std::string primaryWindingType;
    std::string secondaryWindingType;
    double xrRatio;
    double primaryWindingResistance;
    double secondaryWindingResistance;
    double magnetizingCurrent;
    double coreLoss;

    // Derived values
    double totalImpedance;
    double efficiency;

    void calculateDerivedValues();

public:
    // Basic constructor
    Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio);

    // Detailed constructor
    Transformer(Bus* primaryBus, Bus* secondaryBus, double turnsRatio, double impedance, double primaryVoltageRating, double secondaryVoltageRating, double powerRating, double noLoadLosses, double loadLosses, double tapSetting, std::string oilType, std::string coolingType, bool buchholzRelay, std::string neutralPointConfiguration, std::string primaryWindingType, std::string secondaryWindingType, double xrRatio, double primaryWindingResistance, double secondaryWindingResistance, double magnetizingCurrent, double coreLoss);

    // Getters and setters
    Bus* getPrimaryBus() const;
    void setPrimaryBus(Bus* bus);

    Bus* getSecondaryBus() const;
    void setSecondaryBus(Bus* bus);

    double getTurnsRatio() const;
    void setTurnsRatio(double ratio);

    double getImpedance() const;
    void setImpedance(double impedance);

    double getPrimaryVoltageRating() const;
    void setPrimaryVoltageRating(double voltage);

    double getSecondaryVoltageRating() const;
    void setSecondaryVoltageRating(double voltage);

    double getPowerRating() const;
    void setPowerRating(double power);

    double getNoLoadLosses() const;
    void setNoLoadLosses(double losses);

    double getLoadLosses() const;
    void setLoadLosses(double losses);

    double getTapSetting() const;
    void setTapSetting(double tap);

    std::string getOilType() const;
    void setOilType(const std::string& oil);

    std::string getCoolingType() const;
    void setCoolingType(const std::string& cooling);

    bool hasBuchholzRelay() const;
    void setBuchholzRelay(bool relay);

    std::string getNeutralPointConfiguration() const;
    void setNeutralPointConfiguration(const std::string& configuration);

    std::string getPrimaryWindingType() const;
    void setPrimaryWindingType(const std::string& type);

    std::string getSecondaryWindingType() const;
    void setSecondaryWindingType(const std::string& type);

    double getXrRatio() const;
    void setXrRatio(double ratio);

    double getPrimaryWindingResistance() const;
    void setPrimaryWindingResistance(double resistance);

    double getSecondaryWindingResistance() const;
    void setSecondaryWindingResistance(double resistance);

    double getMagnetizingCurrent() const;
    void setMagnetizingCurrent(double current);

    double getCoreLoss() const;
    void setCoreLoss(double loss);

    double getTotalImpedance() const;
    double getEfficiency() const;

    // Other methods
    void applyTurnsRatio() const;
    void adjustTap(double newTapSetting);
    void calculateEfficiency();
};

#endif // TRANSFORMER_H
