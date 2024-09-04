#ifndef BUS_H
#define BUS_H

/**
 * @file Bus.h
 * @brief Header file for the Bus class, representing a bus in the power system.
 * 
 * This file declares the Bus class, which contains generators, loads, transmission lines, and transformers.
 * It includes methods for managing these components, setting and getting voltage, and calculating power flow.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#include <vector>
#include <string>
#include <complex>
#include <algorithm>
#include "lib/load.h"
#include "lib/powersystemerror.h"
#include "lib/transmission_line.h"
#include "lib/line.h"
#include "voltage.h"
#include "current.h"
#include "BusType.h"

class TransmissionLine; // Forward declaration

/**
 * @class Bus
 * @brief Represents a bus in the power system, containing voltage, current, and methods to calculate power flow.
 */
class Bus {
private:
    std::vector<TransmissionLine*> transmissionLines; ///< List of transmission lines connected to the bus
    Voltage busVoltage; ///< Voltage at the bus (complex value with magnitude and angle)
    double current; ///< Current at the bus in amperes
    double inflowPower; ///< Total inflow power in MW
    double outflowPower; ///< Total outflow power in MW
    BusType type; ///< Type of the bus (SLACK, PV, PQ)
    std::string id; ///< Identifier for the bus
    
    // New attributes
    std::string shuntConductor; ///< Type of shunt conductor
    std::string voltageRegulator; ///< Voltage regulator status
    std::string regulatorSetpoint; ///< Voltage regulator setpoint
    std::string voltageBand; ///< Voltage band
    std::string emergencyBackup; ///< Emergency backup status
    std::string harmonicDistortion; ///< Harmonic distortion percentage
    std::string busbarProtection; ///< Busbar protection status

    /**
     * @brief Recalculates the bus voltage and current based on connected transmission lines.
     */
    void recalculateBusState();

    /**
     * @brief Calculates the inflow and outflow power based on connected transmission lines.
     */
    void calculatePowerFlow();

public:
    /**
     * @brief Constructor for the Bus class.
     * @param name The name of the bus.
     * @param busVoltage The initial voltage at the bus.
     * @param type The type of the bus (SLACK, PV, PQ).
     */
    Bus(const std::string& name, const Voltage& busVoltage, BusType type);

    /**
     * @brief Destructor for the Bus class.
     */
    ~Bus() = default;

    // Existing methods
    void addTransmissionLine(TransmissionLine* line);
    void removeTransmissionLine(TransmissionLine* line);
    Voltage getVoltage() const;
    void setVoltage(const Voltage& voltage);
    double getCurrent() const;
    void setCurrent(double current);
    double getInflowPower() const;
    double getOutflowPower() const;
    BusType getType() const;
    void setType(BusType type);

    // New methods
    std::string getId() const;
    void setId(const std::string& id);

    std::string getShuntConductor() const;
    void setShuntConductor(const std::string& shuntConductor);

    std::string getVoltageRegulator() const;
    void setVoltageRegulator(const std::string& voltageRegulator);

    std::string getRegulatorSetpoint() const;
    void setRegulatorSetpoint(const std::string& regulatorSetpoint);

    std::string getVoltageBand() const;
    void setVoltageBand(const std::string& voltageBand);

    std::string getEmergencyBackup() const;
    void setEmergencyBackup(const std::string& emergencyBackup);

    std::string getHarmonicDistortion() const;
    void setHarmonicDistortion(const std::string& harmonicDistortion);

    std::string getBusbarProtection() const;
    void setBusbarProtection(const std::string& busbarProtection);
};

#endif // BUS_H
