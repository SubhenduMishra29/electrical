/**
 * @file powerflow.h
 * @brief Header file for the PowerFlow class, which provides various methods for power system analysis.
 * 
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef POWERFLOW_H
#define POWERFLOW_H

#include "power_system.h"
#include "lib/study/load_flow.h"
#include "lib/study/voltage_drop.h"
#include "lib/study/short_circuit.h"
#include "lib/study/dc_short_circuit.h"
#include "lib/study/dc_load_flow.h"
#include "lib/study/power_factor_correction.h"
#include "lib/study/automatic_device_evaluation.h"
#include "lib/study/power_system_study.h"
#include "lib/study/protection_coordination.h"
#include "lib/study/motor_starting.h"
#include "lib/study/transient_stability.h"
#include "lib/study/harmonic.h"
#include "lib/study/arc_flash.h"
#include "lib/study/power_quality.h"
#include "lib/study/voltage_imbalance.h"

/**
 * @class PowerFlow
 * @brief Class to perform various types of power system analysis.
 * 
 * This class provides methods to perform load flow analysis, voltage drop calculation,
 * short circuit analysis, and other types of power system studies.
 */
class PowerSystem;

class PowerFlow {
public:
    /**
     * @brief Default constructor for PowerFlow.
     */
    PowerFlow();

    /**
     * @brief Perform load flow analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performLoadFlow(PowerSystem& powerSystem);

    /**
     * @brief Calculate voltage drop across the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void calculateVoltageDrop(PowerSystem& powerSystem);

    /**
     * @brief Perform short circuit analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performShortCircuitAnalysis(PowerSystem& powerSystem);

    /**
     * @brief Perform DC short circuit analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performDCShortCircuitAnalysis(PowerSystem& powerSystem);

    /**
     * @brief Perform DC load flow analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performDCLoadFlow(PowerSystem& powerSystem);

    /**
     * @brief Perform power factor correction analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void powerFactorCorrection(PowerSystem& powerSystem);

    /**
     * @brief Perform automatic device evaluation on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performAutomaticDeviceEvaluation(PowerSystem& powerSystem);

    /**
     * @brief Perform a general power system study.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performPowerSystemStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform protection coordination study on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performProtectionCoordinationStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform motor starting study on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performMotorStartingStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform transient stability study on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performTransientStabilityStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform harmonic analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performHarmonicStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform arc flash study on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performArcFlashStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform power quality analysis on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performPowerQualityStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform voltage drop study on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performVoltageDropStudy(PowerSystem& powerSystem);

    /**
     * @brief Perform voltage imbalance study on the power system.
     * @param powerSystem The PowerSystem object representing the power system state.
     */
    void performVoltageImbalanceStudy(PowerSystem& powerSystem);
};

#endif // POWERFLOW_H
