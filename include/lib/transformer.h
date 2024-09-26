#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <memory>
#include "Line.h"
#include "Voltage.h"
#include "Current.h"

/**
 * @class Transformer
 * @brief Represents a transformer in a power system.
 * 
 * The Transformer class models an electrical transformer with various parameters and properties,
 * including voltage, current, impedance, and efficiency. It also manages associated lines.
 */
class Transformer {
private:
    std::string id;
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

    // Voltage and Current for primary and secondary
    Voltage primaryVoltage;
    Voltage secondaryVoltage;
    Current primaryCurrent;
    Current secondaryCurrent;

    // Tracks connected lines
    std::shared_ptr<Line> primaryLine; ///< Incoming lines
    std::shared_ptr<Line> secondaryLine; ///< Outgoing lines

    // Private methods for calculations
    void calculateTotalImpedance();
    void calculateEfficiency();
    void updateCurrents();
    void updateImpedanceRelatedValues();

public:
    // Basic constructor
    Transformer(const std::string& id, double turnsRatio);

    // Detailed constructor
    Transformer(const std::string& id, double turnsRatio, double impedance, double primaryVoltageRating, double secondaryVoltageRating,
                double powerRating, double noLoadLosses, double loadLosses, double tapSetting, 
                const std::string& oilType, const std::string& coolingType, bool buchholzRelay,
                const std::string& neutralPointConfiguration, const std::string& primaryWindingType,
                const std::string& secondaryWindingType, double xrRatio, double primaryWindingResistance,
                double secondaryWindingResistance, double magnetizingCurrent, double coreLoss);

    // Getters and setters
    std::string getId() const;
    void setId(const std::string& id);

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

    // Voltage and Current management
    Voltage getPrimaryVoltage() const;
    void setPrimaryVoltage(const Voltage& voltage);

    Voltage getSecondaryVoltage() const;
    void setSecondaryVoltage(const Voltage& voltage);

    Current getPrimaryCurrent() const;
    void setPrimaryCurrent(const Current& current);

    Current getSecondaryCurrent() const;
    void setSecondaryCurrent(const Current& current);

    // Line management
    void addLine(const std::shared_ptr<Line>& line, bool isPrimary);
    void removeLine(bool isPrimary);

    // Display transformer information
    void displayInfo() const;

    // Other methods
    void applyTurnsRatio() const;
    void adjustTap(double newTapSetting);
};

#endif // TRANSFORMER_H
