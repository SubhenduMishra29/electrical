/*
 * File: Contactor.h
 * Author: Subhendu Mishra
 * Description: Definition of the Contactor class representing a contactor in an electrical system.
 * License: GPL
 */

#ifndef CONTACTOR_H
#define CONTACTOR_H

#include <iostream>
#include <vector>
#include "MainContact.h"
#include "AuxiliaryContact.h"
#include "State.h"

class Contactor {
private:
    std::string manufacturer; // Manufacturer of the contactor
    std::string model; // Model of the contactor
    State state; // State of the contactor (coil and contacts)
    std::vector<MainContact> mainContacts; // Main contacts of the contactor
    std::vector<AuxiliaryContact> auxiliaryContacts; // Auxiliary contacts of the contactor
    double maxCurrent; // Maximum rated current for main contacts

public:
    // Constructor
    Contactor(const std::string& manuf, const std::string& mdl, double maxCurr)
        : manufacturer(manuf), model(mdl), state(false, false, false), maxCurrent(maxCurr) {} // Initialize member variables

    // Method to add a main contact
    void addMainContact(const std::string& material, double size, double currentRating, double maxCurrent) {
        mainContacts.emplace_back(material, size, currentRating, maxCurrent, state);
    }

    // Method to add an auxiliary contact
    void addAuxiliaryContact(const std::string& type, const std::string& material, double size, double currentRating, double maxCurrent) {
        auxiliaryContacts.emplace_back(type, material, size, currentRating, maxCurrent, state);
    }

    // Method to turn on/off the coil and update contacts accordingly
    void turnOnCoil(bool on) {
        state.setCoilState(on);

        for (auto& main : mainContacts) {
            main.setState(on);
        }

        for (auto& aux : auxiliaryContacts) {
            if (aux.isLinked()) {
                aux.setState(aux.getLinkedMainContact()->getState());
            } else {
                aux.setState(false);
            }
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
            main.printDetails();
        }

        std::cout << "Auxiliary Contacts:\n";
        for (const auto& aux : auxiliaryContacts) {
            aux.printDetails();
        }
    }

    // Method to check if current of any main contact exceeds the maximum rated current
    void checkMainContactsCurrent() const {
        for (const auto& main : mainContacts) {
            if (main.getCurrent() > maxCurrent) {
                throw std::runtime_error("Current exceeds maximum rated current for main contact.");
            }
        }
    }
};

#endif // CONTACTOR_H
