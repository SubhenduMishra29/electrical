#ifndef BUS_H
#define BUS_H

#include <vector>
#include "generator.h"
#include "load.h"
#include "transmission_line.h"
#include "transformer.h" // Include transformer header
#include "PowerSystemError.h"
class Bus {
private:
    std::vector<Generator*> generators;
    std::vector<Load*> loads;
    std::vector<TransmissionLine*> transmissionLines;
    std::vector<Transformer*> transformers; // Vector to hold transformers
    double voltage;  // in kV

public:
    Bus(double voltage);
    void addGenerator(Generator* generator);
    void addLoad(Load* load);
    void addTransmissionLine(TransmissionLine* line);
    void addTransformer(Transformer* transformer); // Method to add transformer
    double getVoltage();
    void setVoltage(double voltage); // Method to set voltage
    void calculatePowerFlow();
};

#endif // BUS_H
