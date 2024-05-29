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
#include "Port.h"
#include "MainContact.h"
#include "AuxiliaryContact.h"
#include "State.h"

class Contactor {
private:
    std::string manufacturer;
    std::string model;
    State state;
    std::vector<MainContact> mainContacts;
    std::vector<AuxiliaryContact> auxiliaryContacts;
    std::vector<Port> ports;
    double maxMainCurrent;
    double maxAuxiliaryCurrent;

    double ratedInsulationVoltage;
    double ratedImpulseWithstandVoltage;
    double ratedMakingCapacity;
    double ratedBreakingCapacity;
    double ratedOperationalCurrent;
    double utilizationCurrentAC1;
    double utilizationCurrentAC2;
    double utilizationCurrentAC3;
    double utilizationCurrentAC4;
    double utilizationCurrentAC8b;
    int maxFrequencyOfOperations;
    long mechanicalLifeCycles;
    double permissibleShortTimeRatings;
    double vibrationResistance;
    double serviceTemperatureMin;
    double serviceTemperatureMax;
    double storageTemperatureMin;
    double storageTemperatureMax;
    int degreeOfPollution;
    std::string protectiveTreatment;
    double altitudeWithoutDeration;
    std::string mainTerminalCapacity;
    int numberOfBuiltInAuxiliaryContacts;
    std::string terminalCapacity;
    std::vector<double> coilVoltageAvailable;
    std::vector<std::string> coilVoltageLimits;
    std::vector<double> coilVoltageVA;
    std::vector<double> coilVoltageCosPhi;
    std::vector<double> coilVoltageWatts;
    std::vector<double> coilVoltagePickUp;
    std::vector<double> coilVoltageDropOff;

public:
    Contactor(const std::string& manuf, const std::string& mdl)
        : manufacturer(manuf), model(mdl), state(false, false, false), maxMainCurrent(0), maxAuxiliaryCurrent(0),
          ratedInsulationVoltage(0), ratedImpulseWithstandVoltage(0), ratedMakingCapacity(0), ratedBreakingCapacity(0),
          ratedOperationalCurrent(0), utilizationCurrentAC1(0), utilizationCurrentAC2(0), utilizationCurrentAC3(0),
          utilizationCurrentAC4(0), utilizationCurrentAC8b(0), maxFrequencyOfOperations(0), mechanicalLifeCycles(0),
          permissibleShortTimeRatings(0), vibrationResistance(0), serviceTemperatureMin(0), serviceTemperatureMax(0),
          storageTemperatureMin(0), storageTemperatureMax(0), degreeOfPollution(0), protectiveTreatment(""),
          altitudeWithoutDeration(0), mainTerminalCapacity(""), numberOfBuiltInAuxiliaryContacts(0), terminalCapacity(""),
          coilVoltageAvailable(), coilVoltageLimits(), coilVoltageVA(), coilVoltageCosPhi(), coilVoltageWatts(),
          coilVoltagePickUp(), coilVoltageDropOff() {}

    void addMainContact(const std::string& name, double initialInValue0, double initialInValue1, double maxCurr) {
        mainContacts.emplace_back(initialInValue0, initialInValue1, false, maxCurr);
    }

    void addAuxiliaryContact(const std::string& type, const std::string& name, double initialInValue0, double initialInValue1, double maxCurr) {
        auxiliaryContacts.emplace_back(initialInValue0, initialInValue1, false, (type == "NO") ? NO : NC, maxCurr);
    }

    void addPort(double inVal0, double inVal1, bool state) {
        ports.emplace_back(inVal0, inVal1, state);
    }

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

    void checkMainContactsCurrent() const {
        for (const auto& main : mainContacts) {
            if (main.getCurrent() > maxMainCurrent) {
                throw std::runtime_error("Current exceeds maximum rated current for main contact.");
            }
        }
    }

    void checkAuxiliaryContactsCurrent() const {
        for (const auto& aux : auxiliaryContacts) {
            if (aux.getCurrent() > maxAuxiliaryCurrent) {
                throw std::runtime_error("Current exceeds maximum rated current for auxiliary contact.");
            }
        }
    }
};

#endif // CONTACTOR_H
