#include "lib/bus.h"
#include <iostream>
#include <stdexcept> // For error handling

Bus::Bus()
    : id(""), voltage(), totalCurrent(0.0, 0.0), type(BusType::PQ), hasGenerator(false), isReferenceBus(false) {}

Bus::Bus(const std::string& id, const std::string& voltageStr)
    : id(id), voltage(), totalCurrent(0.0, 0.0), type(BusType::PQ), hasGenerator(false), isReferenceBus(false) {
    try {
        double voltageValue = std::stod(voltageStr);
        this->voltage = Voltage(voltageValue, 0.0); // Assuming initial angle = 0
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid voltage format for Bus ID: " << id << ". Error: " << e.what() << std::endl;
    }
}

Bus::Bus(const std::string& id, const std::string& voltageStr, BusType type)
    : id(id), voltage(), totalCurrent(0.0, 0.0), type(type), hasGenerator(false), isReferenceBus(false) {
    try {
        double voltageValue = std::stod(voltageStr);
        this->voltage = Voltage(voltageValue, 0.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid voltage format for Bus ID: " << id << ". Error: " << e.what() << std::endl;
    }
}

void Bus::addLine(const std::shared_ptr<Line>& line) {
    lines[line->getId()] = line;
    std::cout << "Line " << line->getId() << " added to Bus " << id << "." << std::endl;
}

void Bus::updateBusValues() {
    totalCurrent = Current(0.0, 0.0);

    // Sum currents from all lines
    for (const auto& pair : lines) {
        // Adjust the current based on the line state
        Current lineCurrent = pair.second->getOutCurrent();  // Assuming this returns the current in the desired direction
        totalCurrent = totalCurrent + lineCurrent;
    }

    std::cout << "Updated total current at Bus " << id << ": ";
    totalCurrent.printDetails();
}


void Bus::setVoltage(const Voltage& v) {
    voltage = v;
    std::cout << "Voltage set for Bus " << id << ": ";
    voltage.printDetails(); // Assuming you have a method to display voltage details
}


void Bus::displayInfo() const {
    std::cout << "____________________ Bus Information _____________________" << std::endl;
    std::cout << "Bus ID: " << id << std::endl;

    voltage.printDetails();
    totalCurrent.printDetails();

    std::cout << "Bus Type: " << (type == BusType::SLACK ? "Slack" :
                                  type == BusType::PV ? "PV" : "PQ") << std::endl;
    std::cout << "Connected Lines: " << lines.size() << std::endl;
    std::cout << "__________________________________________________________" << std::endl;
}
