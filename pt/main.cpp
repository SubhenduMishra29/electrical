#include <iostream>
#include "PotentialTransformer.h"

int main() {
    double primaryVoltage = 11000; // Example primary voltage in volts
    double turnsRatio = 10; // Example turns ratio

    PotentialTransformer pt(primaryVoltage, turnsRatio);

    std::cout << "Primary Voltage: " << pt.getPrimaryVoltage() << " V\n";
    std::cout << "Secondary Voltage: " << pt.getSecondaryVoltage() << " V\n";

    return 0;
}
