#include "lib/bus.h"
#include "lib/parser_utils.h"
#include <iostream>
#include <stdexcept> // For std::invalid_argument

Bus::Bus()
    : id(""), voltage(24.0), totalCurrent(0.0) { 
    // No additional initialization required
}

Bus::Bus(const std::string& id, const std::string& voltageStr)
    : id(id), voltage(24.0), totalCurrent(0.0) {
    try {
        // Split the voltage string into number and character parts
        SplitResult result = splitNumberAndChars(voltageStr);
        std::cout << "IN BUS: Added Bus ID: " << id << " with Voltage: " << result.numberPart << result.charPart << std::endl;

        // Convert the number part of the voltage to a double
        double voltageValue = std::stod(result.numberPart);  // Converts "11" to 11.0
        std::cout << "Voltage: " << voltageValue << std::endl;
        this->voltage = voltageValue; // Set the voltage

        // Initialize totalCurrent
        this->totalCurrent = 0.0;        
        std::cout << "Exited bus constructor" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error in Bus constructor: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in Bus constructor: " << e.what() << std::endl;
    }
    // Display bus information
        displayInfo();
}

// Commented out for simplification
/*
bool Bus::addLineId(const std::string& lineId) {
    if (lineIds.find(lineId) == lineIds.end()) {
        lineIds.insert(lineId);
        std::cout << "Line ID " << lineId << " added to Bus " << id << std::endl;
        return true;
    } else {
        std::cout << "Line ID " << lineId << " already exists for Bus " << id << std::endl;
        return false;
    }
}

std::vector<std::string> Bus::getLineIds() const {
    return std::vector<std::string>(lineIds.begin(), lineIds.end());
}
*/

void Bus::updateBusValues() {
    // Placeholder for actual implementation
}

void Bus::displayInfo() const {
    std::cout << "____________________Inside Bus Class_____________________" << std::endl
              << "Bus ID: " << id << std::endl;

    std::cout << "Voltage: " << voltage << " V" << std::endl;

    // std::cout << "Total Current: " << totalCurrent << std::endl; // Uncomment if needed
    // std::cout << "Connected Lines: " << std::endl;
    // for (const auto& lineId : lineIds) {
    //     std::cout << "Line ID: " << lineId << std::endl; // Print only IDs
    // }
}
