/*
 * File: Contactor.h
 * Author: Subhendu Mishra
 * License: GPL
 * Description: Definition of the Contactor class representing a contactor in an electrical system.
 */

#ifndef CONTACTOR_H
#define CONTACTOR_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Port.h" // Include the modified Port class header file
#include "MainContact.h" // Include the MainContact class header file
#include "AuxiliaryContact.h" // Include the AuxiliaryContact class header file
#include "State.h" // Include the State class header file

class Contactor {
private:
    std::string manufacturer; // Manufacturer of the contactor
    std::string model; // Model of the contactor
    State state; // State of the contactor (coil and contacts)
    std::vector<MainContact> mainContacts; // Main contacts of the contactor
    std::vector<AuxiliaryContact> auxiliaryContacts; // Auxiliary contacts of the contactor
    std::vector<Port> ports; // Ports of the contactor
    double maxMainCurrent; // Maximum rated current for main contacts
    double maxAuxiliaryCurrent; // Maximum rated current for auxiliary contacts

    // Additional technical specifications
    double ratedInsulationVoltage; // Rated insulation voltage, Ui
    double ratedImpulseWithstandVoltage; // Rated impulse withstand voltage, Uimp
    double ratedMakingCapacity; // Rated making capacity
    double ratedBreakingCapacity; // Rated breaking capacity
    double ratedOperationalCurrent; // Rated operational current, Ie at 55°C / Motor duty
    double utilizationCurrentAC1; // Utilization category AC-1
    double utilizationCurrentAC2; // Utilization category AC-2
    double utilizationCurrentAC3; // Utilization category AC-3
    double utilizationCurrentAC4; // Utilization category AC-4
    double utilizationCurrentAC8b; // Utilization category AC-8b
    int maxFrequencyOfOperations; // Maximum frequency of operations
    long mechanicalLifeCycles; // Mechanical life, number of operating cycles
    double permissibleShortTimeRatings; // Permissible short time ratings
    double vibrationResistance; // Vibration resistance conforming to IEC 60068-2-6
    double serviceTemperatureMin; // Minimum service temperature
    double serviceTemperatureMax; // Maximum service temperature
    double storageTemperatureMin; // Minimum storage temperature
    double storageTemperatureMax; // Maximum storage temperature
    int degreeOfPollution; // Degree of pollution
    std::string protectiveTreatment; // Protective treatment as per IEC 60068-2-30
    double altitudeWithoutDeration; // Altitude without deration
    std::string mainTerminalCapacity; // Main terminal capacity
    int numberOfBuiltInAuxiliaryContacts; // Number of built-in auxiliary contacts
    std::string terminalCapacity; // Terminal capacity
    std::vector<double> coilVoltageAvailable; // Available coil voltages
    std::vector<std::string> coilVoltageLimits; // Coil voltage limits
    std::vector<double> coilVoltageVA; // Coil voltage in VA
    std::vector<double> coilVoltageCosPhi; // Coil voltage cosPhi
    std::vector<double> coilVoltageWatts; // Coil voltage in watts
    std::vector<double> coilVoltagePickUp; // Coil voltage pick-up
    std::vector<double> coilVoltageDropOff; // Coil voltage drop-off

public:
    // Constructor to initialize the contactor with basic details
    Contactor(const std::string& manuf, const std::string& mdl, double maxMainCurr, double maxAuxCurr, double ratedInsVoltage, double ratedImpWithVoltage)
        : manufacturer(manuf), model(mdl), state(false, false, false), maxMainCurrent(maxMainCurr), maxAuxiliaryCurrent(maxAuxCurr),
          ratedInsulationVoltage(ratedInsVoltage), ratedImpulseWithstandVoltage(ratedImpWithVoltage), ratedMakingCapacity(0),
          ratedBreakingCapacity(0), ratedOperationalCurrent(0), utilizationCurrentAC1(0), utilizationCurrentAC2(0), utilizationCurrentAC3(0),
          utilizationCurrentAC4(0), utilizationCurrentAC8b(0), maxFrequencyOfOperations(0), mechanicalLifeCycles(0), permissibleShortTimeRatings(0),
          vibrationResistance(0), serviceTemperatureMin(0), serviceTemperatureMax(0), storageTemperatureMin(0), storageTemperatureMax(0),
          degreeOfPollution(0), protectiveTreatment(""), altitudeWithoutDeration(0), mainTerminalCapacity(""), numberOfBuiltInAuxiliaryContacts(0),
          terminalCapacity(""), coilVoltageAvailable(), coilVoltageLimits(), coilVoltageVA(), coilVoltageCosPhi(), coilVoltageWatts(),
          coilVoltagePickUp(), coilVoltageDropOff() {}

    // Method to add a main contact
    void addMainContact(const std::string& name, double initialInValue0, double initialInValue1, double maxCurr) {
        mainContacts.emplace_back(initialInValue0, initialInValue1, false, maxCurr); // Assuming the initial state is false (open)
    }

    // Method to add an auxiliary contact
    void addAuxiliaryContact(const std::string& type, const std::string& name, double initialInValue0, double initialInValue1, double maxCurr) {
        auxiliaryContacts.emplace_back(initialInValue0, initialInValue1, false, (type == "NO") ? NO : NC, maxCurr); // Assuming the initial state is false (open)
    }

    // Method to add a port
    void addPort(double inVal0, double inVal1, bool state) {
        ports.emplace_back(inVal0, inVal1, state);
    }

    // Method to turn on/off the coil and update contacts accordingly
    void turnOnCoil(bool on) {
        state.setCoilState(on);

        for (auto& main : mainContacts) {
            main.setState(on);
        }

        for (auto& aux : auxiliaryContacts) {
            aux.setState(on);
        }

        for (auto& port : ports) {
            port.setState(on);
        }
    }

    // Method to print contactor details
    void printDetails() const {
        std::cout << "Contactor Details:\n"
                  << "Manufacturer: " << manufacturer << "\n"
                  << "Model: " << model << "\n"
                  << "Main Contact State: " << (state.getMainContactState() ? "Closed" : "Open") << "\n"
                  << "Auxiliary Contact State: " << (state.getAuxiliaryContactState() ? "Closed" : "Open") << "\n"
                  << "Coil State: " << (state.getCoilState() ? "On" : "Off") << "\n"
                  << "Rated Insulation Voltage: " << ratedInsulationVoltage << " V\n"
                  << "Rated Impulse Withstand Voltage: " << ratedImpulseWithstandVoltage << " kV\n"
                  << "Rated Making Capacity: " << ratedMakingCapacity << " A\n"
                  << "Rated Breaking Capacity: " << ratedBreakingCapacity << " A\n"
                  << "Rated Operational Current: " << ratedOperationalCurrent << " A\n"
                  << "Utilization Current (AC-1): " << utilizationCurrentAC1 << " A\n"
                  << "Utilization Current (AC-2): " << utilizationCurrentAC2 << " A\n"
                  << "Utilization Current (AC-3): " << utilizationCurrentAC3 << " A\n"
                  << "Utilization Current (AC-4): " << utilizationCurrentAC4 << " A\n"
                  << "Utilization Current (AC-8b): " << utilizationCurrentAC8b << " A\n"
                  << "Max Frequency of Operations: " << maxFrequencyOfOperations << " cycles/hr\n"
                  << "Mechanical Life Cycles: " << mechanicalLifeCycles << " cycles\n"
                  << "Permissible Short Time Ratings: " << permissibleShortTimeRatings << " A\n"
                  << "Vibration Resistance: " << vibrationResistance << " g\n"
                  << "Service Temperature Min: " << serviceTemperatureMin << " °C\n"
                  << "Service Temperature Max: " << serviceTemperatureMax << " °C\n"
                  << "Storage Temperature Min: " << storageTemperatureMin << " °C\n"
                  << "Storage Temperature Max: " << storageTemperatureMax << " °C\n"
                  << "Degree of Pollution: " << degreeOfPollution << "\n"
                  << "Protective Treatment: " << protectiveTreatment << "\n"
                  << "Altitude Without Deration: " << altitudeWithoutDeration << " m\n"
                  << "Main Terminal Capacity: " << mainTerminalCapacity << "\n"
                  << "Number of Built-In Auxiliary Contacts: " << numberOfBuiltInAuxiliaryContacts << "\n"
                  << "Terminal Capacity: " << terminalCapacity << "\n";

        std::cout << "Available Coil Voltages: ";
        for (const auto& voltage : coilVoltageAvailable) {
            std::cout << voltage << " V ";
        }
        std::cout << "\nCoil Voltage Limits: ";
        for (const auto& limit : coilVoltageLimits) {
            std::cout << limit << " ";
        }
        std::cout << "\nCoil Voltage VA: ";
        for (const auto& va : coilVoltageVA) {
            std::cout << va << " VA ";
        }
        std::cout << "\nCoil Voltage CosPhi: ";
        for (const auto& cosPhi : coilVoltageCosPhi) {
            std::cout << cosPhi << " ";
        }
        std::cout << "\nCoil Voltage Watts: ";
        for (const auto& watts : coilVoltageWatts) {
            std::cout << watts << " W ";
        }
        std::cout << "\nCoil Voltage Pick-Up: ";
        for (const auto& pickUp : coilVoltagePickUp) {
            std::cout << pickUp << " V ";
        }
        std::cout << "\nCoil Voltage Drop-Off: ";
        for (const auto& dropOff : coilVoltageDropOff) {
            std::cout << dropOff << " V ";
        }
        std::cout << std::endl;

        std::cout << "Main Contacts:\n";
        for (const auto& main : mainContacts) {
            std::cout << "Current: " << main.getCurrent() << " A, Max Current: " << main.getMaxCurrent() << " A\n";
        }

        std::cout << "Auxiliary Contacts:\n";
        for (const auto& aux : auxiliaryContacts) {
            std::cout << "Current: " << aux.getCurrent() << " A, Max Current: " << aux.getMaxCurrent() << " A\n";
        }

        std::cout << "Ports:\n";
        for (const auto& port : ports) {
            std::cout << "State: " << (port.getState() ? "Active" : "Inactive") << "\n";
        }
    }

    // Method to check if current of any main contact exceeds the maximum rated current
    void checkMainContactsCurrent() const {
        for (const auto& main : mainContacts) {
            if (main.getCurrent() > maxMainCurrent) {
                throw std::runtime_error("Current exceeds maximum rated current for main contact.");
            }
        }
    }

    // Method to check if current of any auxiliary contact exceeds the maximum rated current
    void checkAuxiliaryContactsCurrent() const {
        for (const auto& aux : auxiliaryContacts) {
            if (aux.getCurrent() > maxAuxiliaryCurrent) {
                throw std::runtime_error("Current exceeds maximum rated current for auxiliary contact.");
            }
        }
    }
};

#endif // CONTACTOR_H
