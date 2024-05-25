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

public:
    // Constructor
    Contactor(const std::string& manuf, const std::string& mdl, double maxMainCurr, double maxAuxCurr)
        : manufacturer(manuf), model(mdl), state(false, false, false), maxMainCurrent(maxMainCurr), maxAuxiliaryCurrent(maxAuxCurr) {} // Initialize member variables

    // Method to add a main contact
    void addMainContact(double initialInValue0, double initialInValue1, bool initialState) {
        mainContacts.emplace_back(initialInValue0, initialInValue1, initialState, maxMainCurrent);
    }

    // Method to add an auxiliary contact
    void addAuxiliaryContact(double initialInValue0, double initialInValue1, bool initialState) {
        auxiliaryContacts.emplace_back(initialInValue0, initialInValue1, initialState, maxAuxiliaryCurrent);
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
                  << "Coil State: " << (state.getCoilState() ? "On" : "Off") << std::endl;

        std::cout << "Main Contacts:\n";
        for (const auto& main : mainContacts) {
            // Print main contact details if needed
        }

        std::cout << "Auxiliary Contacts:\n";
        for (const auto& aux : auxiliaryContacts) {
            // Print auxiliary contact details if needed
        }

        std::cout << "Ports:\n";
        for (const auto& port : ports) {
            // Print port details if needed
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
