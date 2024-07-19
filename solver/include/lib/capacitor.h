#ifndef CAPACITOR_H
#define CAPACITOR_H

#include <string>

class Capacitor {
private:
    std::string id;                 // ID of the capacitor
    double capacitance;             // Capacitance of the capacitor (in Farads)
    double voltageRating;           // Maximum voltage rating of the capacitor (in volts)
    double lossFactor;              // Loss factor of the capacitor
    bool hasSurgeProtection;        // Indicates if surge protection is implemented
    std::string insulationLevel;    // Insulation level of the capacitor
    std::string location;           // Location of the capacitor (indoor or outdoor)
    std::string protectionDevices;  // Protection devices used (e.g., series reactors, relays)

public:
    // Constructor
    Capacitor(const std::string& id, double capacitance, double voltageRating, double lossFactor,
              bool hasSurgeProtection, const std::string& insulationLevel, const std::string& location,
              const std::string& protectionDevices);

    // Destructor
    ~Capacitor();

    // Getters for Capacitor attributes
    std::string getId() const;
    double getCapacitance() const;
    double getVoltageRating() const;
    double getLossFactor() const;
    bool hasSurgeProtectionDevice() const;
    std::string getInsulationLevel() const;
    std::string getLocation() const;
    std::string getProtectionDevices() const;

    // Additional methods specific to Capacitor if needed
};

#endif // CAPACITOR_H
