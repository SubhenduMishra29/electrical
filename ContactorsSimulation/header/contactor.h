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

    // Method to add a port
    void addPort(int portInId, const std::string& portInName, int portOutId, const std::string& portOutName) {
        ports.emplace_back(portInId, portInName, portOutId, portOutName);
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

        for (auto& port : ports) {
            port.togglePort(on);
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

        std::cout << "Ports:\n";
        for (const auto& port : ports) {
            std::cout << "Input: " << port.getInValue() << ", Output: " << port.getOutValue() << std::endl;
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
