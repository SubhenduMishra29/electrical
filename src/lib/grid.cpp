#include "lib/grid.h"

Grid::Grid(const std::string& id, const std::string& voltageStr) : id(id) {
    double voltageValue = std::stod(voltageStr);
    this->voltage = Voltage(voltageValue, 0.0); // Assuming initial angle = 0
    displayInfo();
}

std::shared_ptr<Line> Grid::getLineById(const std::string& lineId) {
    // Implement this method to retrieve a Line object by its ID
    // For now, we will return a dummy Line object for demonstration
    return std::make_shared<Line>(lineId);
}

void Grid::setVoltage(const Voltage& v) {
    voltage = v;

    if (connectedLine) {
        connectedLine->setVoltage(voltage);
    } else {
        std::cerr << "No line connected to the grid to set voltage." << std::endl;
    }
}

void Grid::setCurrent(const Current& c) {
    current = c;
    updateConnectedLine(); // Update the connected line when current changes
}

void Grid::setFrequency(double f) {
    frequency = f;
    // Implement any additional logic required for frequency change
}

void Grid::setPower(double p) {
    base_power = p;
    // Implement any additional logic required for power change
}

void Grid::connectLine(const std::string& lineId) {
    // Retrieve the line using its ID
    std::shared_ptr<Line> line = getLineById(lineId);

    if (line) {
        connectedLine = line;
        connectedLine->setVoltage(voltage); // Set the current grid voltage on the connected line
        std::cout << "Line " << lineId << " connected to the grid." << std::endl;
    } else {
        std::cerr << "Error: Line with ID " << lineId << " not found." << std::endl;
    }
}

void Grid::updateConnectedLine() {
    if (connectedLine) {
        connectedLine->setVoltage(voltage);
        // Uncomment the next line if you want to set the current on the line as well
        // connectedLine->setCurrent(current);
    } else {
        std::cerr << "Error: No line is connected to the grid." << std::endl;
    }
}

void Grid::calculateParameters() {
    // Example calculation for impedance
    if (std::abs(current.getValue()) > 0.0) {
        double impedance = std::abs(voltage.getValue()) / std::abs(current.getValue());
        std::cout << "Calculated Impedance: " << impedance << " Ohms" << std::endl;
    } else {
        std::cerr << "Error: Current is zero, cannot calculate impedance." << std::endl;
    }

    // Example calculation for power factor
    double realPower = base_power; // Placeholder: Use actual real power value
    double reactivePower = 0.0; // You should have a method to get this value
    double powerFactor = realPower / std::sqrt(realPower * realPower + reactivePower * reactivePower);
    std::cout << "Calculated Power Factor: " << powerFactor << std::endl;

    // Short circuit current calculation (simplified)
    if (SC_capacity > 0) {
        double shortCircuitCurrent = SC_capacity / std::abs(voltage.getValue());
        std::cout << "Calculated Short Circuit Current: " << shortCircuitCurrent << " A" << std::endl;
    } else {
        std::cerr << "Error: Short Circuit Capacity is not set." << std::endl;
    }

    // Additional calculations can be added as needed
}

void Grid::displayInfo() const {
    std::cout << "____________________ Grid Information _____________________" << std::endl;
    std::cout << "Grid ID: " << id << std::endl;
    
    std::cout << "Voltage Details:" << std::endl;
    voltage.printDetails();

    std::cout << "Current: " << current.getValue() << " A" << std::endl; // Assuming getValue() method exists
    std::cout << "Frequency: " << frequency << " Hz" << std::endl;
    std::cout << "Base Power: " << base_power << " W" << std::endl;
    std::cout << "Short Circuit Capacity: " << SC_capacity << " VA" << std::endl;

    if (connectedLine) {
        std::cout << "Connected Line ID: " << connectedLine->getId() << std::endl; // Assuming getId() method exists
    } else {
        std::cout << "No line is currently connected." << std::endl;
    }

    std::cout << "__________________________________________________________" << std::endl;
}

