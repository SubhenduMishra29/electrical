#ifndef CAPACITOR_BANK_H
#define CAPACITOR_BANK_H

#include "Capacitor.h"
#include <string>
#include <vector>

class CapacitorBank {
private:
    std::string id;                     // ID of the capacitor bank
    double capacitance;                 // Total capacitance of the bank (in Farads or microfarads)
    double voltageRating;               // Maximum voltage rating of the capacitor bank
    double frequency;                   // Operating frequency (in Hz)
    double temperatureRating;           // Maximum operating temperature (in °C)
    double powerRating;                 // Maximum reactive power rating (in kVAR)
    int numUnits;                       // Number of capacitor units in the bank
    std::string configuration;          // Configuration of the bank (e.g., single-phase, three-phase)
    std::string placement;              // Optimal placement consideration
    bool hasProtection;                 // Indicates if protection (e.g., series reactors, relays) is implemented

    std::vector<Capacitor> capacitors;  // Vector to hold individual capacitors in the bank

public:
    // Constructor
    CapacitorBank(const std::string& id, double capacitance, double voltageRating, double frequency,
                  double temperatureRating, double powerRating, int numUnits, const std::string& configuration,
                  const std::string& placement, bool hasProtection);

    // Destructor
    ~CapacitorBank();

    // Methods to manage capacitors
    void addCapacitor(const Capacitor& capacitor);
    std::vector<Capacitor> getCapacitors() const;

    // Getters for CapacitorBank attributes
    std::string getId() const;
    double getCapacitance() const;
    double getVoltageRating() const;
    double getFrequency() const;
    double getTemperatureRating() const;
    double getPowerRating() const;
    int getNumUnits() const;
    std::string getConfiguration() const;
    std::string getPlacement() const;
    bool hasProtectionDevices() const;

    // Additional methods specific to CapacitorBank if needed
};

#endif // CAPACITOR_BANK_H
