#include "lib/line.h"


/**
 * @brief Default constructor for the Line class.
 * Initializes all properties to default values.
 */
Line::Line()
    : id(""), inCurrent(Current()), outCurrent(Current()), voltage(Voltage()), impedance(0.0), capacitance(0.0), inductance(0.0) {}

/**
 * @brief Constructs a Line object with only an ID.
 * @param id The line ID.
 */
Line::Line(const std::string& id)
    : id(id), inCurrent(Current()), outCurrent(Current()), voltage(Voltage()), impedance(0.0), capacitance(0.0), inductance(0.0) {}

/**
 * @brief Constructs a Line object with specified properties.
 * @param id The line ID.
 * @param impedance The line impedance.
 * @param capacitance The line capacitance.
 * @param inductance The line inductance.
 */
Line::Line(const std::string& id, double impedance, double capacitance, double inductance)
    : id(id), inCurrent(Current()), outCurrent(Current()), voltage(Voltage()), impedance(impedance), capacitance(capacitance), inductance(inductance) {}

/**
 * @brief Gets the incoming current of the line.
 * @return The incoming current.
 */
Current Line::getInCurrent() const {
    return inCurrent;
}

/**
 * @brief Sets the incoming current of the line.
 * @param current The incoming current.
 */
void Line::setInCurrent(const Current& current) {
    inCurrent = current;
    // Update voltage drop based on incoming current
   // voltage = calculateVoltageDrop();
}
/**
 * @brief Calculates the voltage drop across the line based on the incoming current.
 * @return The calculated voltage drop.
 */
//Voltage Line::calculateVoltageDrop() const {
    // Voltage drop = Current * Impedance (assuming resistance only for simplicity)
//    double voltageDrop = inCurrent.getMagnitude() * impedance; // Assuming Current has a getMagnitude() method
//    return Voltage(voltageDrop); // Assuming Voltage can be constructed from a double
//}
/**
 * @brief Gets the outgoing current of the line.
 * @return The outgoing current.
 */
Current Line::getOutCurrent() const {
    return outCurrent;
}

/**
 * @brief Sets the outgoing current of the line.
 * @param current The outgoing current.
 */
void Line::setOutCurrent(const Current& current) {
    outCurrent = current;
}

/**
 * @brief Gets the voltage drop across the line.
 * @return The voltage drop.
 */
Voltage Line::getVoltage() const {
    return voltage;
}

/**
 * @brief Sets the voltage drop across the line.
 * @param v The voltage drop.
 */
void Line::setVoltage(const Voltage& v) {
    voltage = v;
}

/**
 * @brief Gets the impedance of the line.
 * @return The impedance.
 */
double Line::getImpedance() const {
    return impedance;
}

/**
 * @brief Gets the capacitance of the line.
 * @return The capacitance.
 */
double Line::getCapacitance() const {
    return capacitance;
}

/**
 * @brief Gets the inductance of the line.
 * @return The inductance.
 */
double Line::getInductance() const {
    return inductance;
}

/**
 * @brief Gets the ID of the line.
 * @return The line ID.
 */
std::string Line::getId() const {
    return id;
}

/**
 * @brief Updates the line properties based on current state.
 * Placeholder for any necessary adjustments.
 */
void Line::update() {
    // Implement specific update logic if needed
}

/**
 * @brief Calculates the voltage drop across the line based on the incoming current.
 * @return The calculated voltage drop.
 */
//Voltage Line::calculateVoltageDrop() const {
    // Voltage drop = Current * Impedance (assuming resistance only for simplicity)
///    double voltageDrop = inCurrent.getMagnitude() * impedance; // Assuming Current has a getMagnitude() method
//    return Voltage(voltageDrop); // Assuming Voltage can be constructed from a double
//}

/**
 * @brief Displays the line information to the console.
 */
void Line::displayInfo() const {
    std::cout << "-------------------------Line-------------------- " << std::endl;
    std::cout << "Line ID: " << id << std::endl;
    std::cout << "Incoming Current: " << inCurrent.getValue() << std::endl; // Assuming Current has a getValue() method
    std::cout << "Outgoing Current: " << outCurrent.getValue() << std::endl; // Assuming Current has a getValue() method
    std::cout << "Voltage Drop: " << voltage.getValue() << std::endl; // Assuming Voltage has a getValue() method
    std::cout << "Impedance: " << impedance << std::endl;
    std::cout << "Capacitance: " << capacitance << std::endl;
}
