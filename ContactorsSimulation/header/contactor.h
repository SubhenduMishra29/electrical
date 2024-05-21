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

class Contactor {
private:
    std::string manufacturer; // Manufacturer of the contactor
    std::string model; // Model of the contactor
    std::vector<Port> ports; // Ports of the contactor
    double maxCurrent; // Maximum rated current for main contacts

public:
    // Constructor
    Contactor(const std::string& manuf, const std::string& mdl, double maxCurr)
        : manufacturer(manuf), model(mdl), maxCurrent(maxCurr) {} // Initialize member variables

    // Method to add a port
    void addPort(int portInId, const std::string& portInName, int portOutId, const std::string& portOutName) {
        ports.emplace_back(portInId, portInName, portOutId, portOutName);
    }

    // Method to turn on/off the coil and update port states accordingly
    void turnOnCoil(bool on) {
        for (auto& port : ports) {
            port.togglePort(on);
        }
    }

    // Method to print contactor details
    void printDetails() const {
        std::cout << "Contactor Details:\n"
                  << "Manufacturer: " << manufacturer << "\n"
                  << "Model: " << model << std::endl;

        std::cout << "Ports:\n";
        for (const auto& port : ports) {
            std::cout << "Input: " << port.getInValue() << ", Output: " << port.getOutValue() << std::endl;
        }
    }

    // Method to check if current of any port exceeds the maximum rated current
    void checkPortCurrents() const {
        // Assuming port current is always 0 for simplicity in this context
        // Add logic here if needed
    }
};

#endif // CONTACTOR_H
