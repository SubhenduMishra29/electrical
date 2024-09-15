#include "lib/bus.h"
#include <iostream>
#include <stdexcept> // For error handling

Bus::Bus()
    : id(""), voltage(), totalCurrent(0.0, 0.0), type(BusType::PQ) {}

Bus::Bus(const std::string& id, const std::string& voltageStr)
    : id(id), voltage(), totalCurrent(0.0, 0.0), type(BusType::PQ) {
    try {
        double voltageValue = std::stod(voltageStr);
        this->voltage = Voltage(voltageValue, 0.0); // Assuming initial angle = 0
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid voltage format for Bus ID: " << id << ". Error: " << e.what() << std::endl;
    }
}

Bus::Bus(const std::string& id, const std::string& voltageStr, BusType type)
    : id(id), voltage(), totalCurrent(0.0, 0.0), type(type) {
    try {
        double voltageValue = std::stod(voltageStr);
        this->voltage = Voltage(voltageValue, 0.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid voltage format for Bus ID: " << id << ". Error: " << e.what() << std::endl;
    }
}

void Bus::addLine(const std::shared_ptr<Line>& line, bool isIncoming) {
    if (isIncoming) {
        incomingLines[line->getId()] = line;
        std::cout << "Line " << line->getId() << " added to Bus " << id << " as incoming." << std::endl;
    } else {
        outgoingLines[line->getId()] = line;
        std::cout << "Line " << line->getId() << " added to Bus " << id << " as outgoing." << std::endl;
    }
}

void Bus::updateBusValues() {
    totalCurrent = Current(0.0, 0.0);

    // Sum currents from incoming lines
    for (const auto& pair : incomingLines) {
        std::complex<double> inCurrent = pair.second->getOutCurrent();
        totalCurrent = totalCurrent + Current(inCurrent.real(), inCurrent.imag());
    }

    // Subtract currents from outgoing lines
    for (const auto& pair : outgoingLines) {
        std::complex<double> outCurrent = pair.second->getOutCurrent();
        totalCurrent = totalCurrent - Current(outCurrent.real(), outCurrent.imag());
    }

    std::cout << "Updated total current at Bus " << id << ": ";
    totalCurrent.printDetails();
}

void Bus::displayInfo() const {
    std::cout << "____________________ Bus Information _____________________" << std::endl;
    std::cout << "Bus ID: " << id << std::endl;
    
    voltage.printDetails();
    totalCurrent.printDetails();

    std::cout << "Bus Type: " << (type == BusType::SLACK ? "Slack" :
                                  type == BusType::PV ? "PV" : "PQ") << std::endl;
    std::cout << "Incoming Lines: " << incomingLines.size() << std::endl;
    std::cout << "Outgoing Lines: " << outgoingLines.size() << std::endl;
    std::cout << "__________________________________________________________" << std::endl;
}
