#ifndef GRID_H
#define GRID_H
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#include "PowerSystemError.h"

class Grid {
private:
    double voltage;                 // Voltage of the external grid source
    double availablePower;          // Total available power from the grid source
    double frequency;               // Frequency of the grid (e.g., 50 Hz or 60 Hz)
    int numberOfPhases;             // Number of phases in the grid (1 for single-phase, 3 for three-phase)
    double voltageRegulation;       // Percentage regulation of voltage
    double powerFactor;             // Power factor of the grid
    double harmonicDistortion;      // Harmonic distortion percentage
    double transientResponse;       // Response time to transients

    // Additional attributes for short circuit and X/R ratios
    double threePhaseMVAsc;          // 3-phase MVA short circuit contribution
    double onePhaseMVAsc;            // 1-phase MVA short circuit contribution
    double xRRatioPositive;          // X/R ratio for positive sequence impedance
    double xRRatioZero;              // X/R ratio for zero sequence impedance
    double threePhaseSymmetricalKAsc;// 3-phase symmetrical short circuit current rating
    double onePhaseSymmetricalKAsc;  // 1-phase symmetrical short circuit current rating

public:
    Grid(double voltage, double availablePower, double frequency, int numberOfPhases,
         double voltageRegulation, double powerFactor,
         double harmonicDistortion, double transientResponse);

    // Getters for all attributes
    double getVoltage() const;
    double getAvailablePower() const;
    double getFrequency() const;
    int getNumberOfPhases() const;
    double getVoltageRegulation() const;
    double getPowerFactor() const;
    double getHarmonicDistortion() const;
    double getTransientResponse() const;

    // Setters for voltage and available power (other attributes can have setters as needed)
    void setVoltage(double voltage);
    void setAvailablePower(double availablePower);

    // Methods for short circuit and X/R ratios
    void setThreePhaseMVAsc(double mvAsc);
    void setOnePhaseMVAsc(double mvAsc);
    void setXRRatioPositive(double xRRatio);
    void setXRRatioZero(double xRRatio);
    void setThreePhaseSymmetricalKAsc(double kAsc);
    void setOnePhaseSymmetricalKAsc(double kAsc);

    double getThreePhaseMVAsc() const;
    double getOnePhaseMVAsc() const;
    double getXRRatioPositive() const;
    double getXRRatioZero() const;
    double getThreePhaseSymmetricalKAsc() const;
    double getOnePhaseSymmetricalKAsc() const;

    // Methods for simulating faults and protection responses (can be expanded)
    void simulateFault();
    void handleProtection();
};

#endif // GRID_H
/*                       Example for grid calling 
#include <iostream>
#include "grid.h"

int main() {
    // Create an instance of Grid with basic parameters
    Grid myGrid(230.0, 1000.0, 50.0, 3, 5.0, 0.9, 1.5, 0.2);

    // Set additional attributes for short circuit contributions and X/R ratios
    myGrid.setThreePhaseMVAsc(71.072);  // 3-phase MVA short circuit contribution
    myGrid.setOnePhaseMVAsc(51.314);    // 1-phase MVA short circuit contribution
    myGrid.setXRRatioPositive(10.0);    // X/R ratio for positive sequence impedance
    myGrid.setXRRatioZero(5.0);         // X/R ratio for zero sequence impedance
    myGrid.setThreePhaseSymmetricalKAsc(50.0); // 3-phase symmetrical short circuit current rating
    myGrid.setOnePhaseSymmetricalKAsc(35.0);   // 1-phase symmetrical short circuit current rating

    // Retrieve and display the attributes
    std::cout << "Grid Voltage: " << myGrid.getVoltage() << " V" << std::endl;
    std::cout << "Available Power: " << myGrid.getAvailablePower() << " W" << std::endl;
    std::cout << "Frequency: " << myGrid.getFrequency() << " Hz" << std::endl;
    std::cout << "Number of Phases: " << myGrid.getNumberOfPhases() << std::endl;
    std::cout << "Voltage Regulation: " << myGrid.getVoltageRegulation() << " %" << std::endl;
    std::cout << "Power Factor: " << myGrid.getPowerFactor() << std::endl;
    std::cout << "Harmonic Distortion: " << myGrid.getHarmonicDistortion() << " %" << std::endl;
    std::cout << "Transient Response: " << myGrid.getTransientResponse() << " s" << std::endl;
    
    // Retrieve and display the additional attributes
    std::cout << "3-Phase MVAsc: " << myGrid.getThreePhaseMVAsc() << " MVA" << std::endl;
    std::cout << "1-Phase MVAsc: " << myGrid.getOnePhaseMVAsc() << " MVA" << std::endl;
    std::cout << "X/R Ratio (Positive Sequence): " << myGrid.getXRRatioPositive() << std::endl;
    std::cout << "X/R Ratio (Zero Sequence): " << myGrid.getXRRatioZero() << std::endl;
    std::cout << "3-Phase Symmetrical KAsc: " << myGrid.getThreePhaseSymmetricalKAsc() << " kA" << std::endl;
    std::cout << "1-Phase Symmetrical KAsc: " << myGrid.getOnePhaseSymmetricalKAsc() << " kA" << std::endl;

    // Simulate a fault and handle protection (placeholder methods)
    myGrid.simulateFault();
    myGrid.handleProtection();

    return 0;
}
*/
/*
Implimentd ShortCircuit Parameters
Callout A: MVAsc
It is a radio button. If you click on it, you change the units of the data you entered below in MVA, KVA, or VA. I will leave it to MVAsc.
The letter sc next to MVA means short circuit. So MVAsc means MVA short circuit.
Callout B: 3-phase MVAsc
For 3-phase faults, you need to enter the MVA short circuit contribution from the grid. For this example, MVAsc is 71.072 MVA.
Callout C: 1 phase MVAsc
You need to enter the 1-phase MVAsc. It is calculated with the formula sqrt (3) * V line to line * I fault.  In this example, we have 51.314 MVA
Callout D: 1 Phase MVAsc
This value is auto-populated when you enter a value in Callout C. Unlike Callout C, it uses V line neutral* I fault.
Callout E: X/R 3 phase
Enter X/R for positive sequence impedance
Callout F: X/R 1 phase
Enter X/R for zero sequence impedance
Callout G: 3 phase kAsc
Enter the 3-phase symmetrical short circuit current rating. This value gets auto-populated when you enter 3-phase MVAsc.
Callout H: 1 phase kAsc
Enter the 1-phase (line to ground) symmetrical short circuit current rating. This value gets auto-populated when you enter 1 phase MVAsc.

*/