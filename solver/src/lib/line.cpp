#include "lib/line.h"

/**
 * @brief Default constructor for the Line class.
 * Initializes all properties to zero.
 */
Line::Line()
    : id(""), outCurrent(0.0, 0.0), impedance(0.0), capacitance(0.0), inductance(0.0) {}

/**
 * @brief Constructs a Line object with specified properties.
 * @param id The line ID.
 * @param impedance The line impedance.
 * @param capacitance The line capacitance.
 * @param inductance The line inductance.
 */
Line::Line(const std::string& id, double impedance, double capacitance, double inductance)
    : id(id), outCurrent(0.0, 0.0), impedance(impedance), capacitance(capacitance), inductance(inductance) {}

/**
 * @brief Gets the outgoing current of the line.
 * @return The outgoing current.
 */
std::complex<double> Line::getOutCurrent() const {
    return outCurrent;
}

/**
 * @brief Sets the outgoing current of the line.
 * @param current The outgoing current.
 */
void Line::setOutCurrent(const std::complex<double>& current) {
    outCurrent = current;
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
 * @brief Updates the line properties. This is a placeholder for any necessary adjustments.
 */
void Line::update() {
    // Implement specific update logic if needed
}
Line::Line(const std::string& id){
    this->id = id;
    this->outCurrent = std::complex<double>(0.0, 0.0);
    this->impedance = 0.0;
    this->capacitance = 0.0;
    this->inductance = 0.0;
    displayInfo();
}

/**
 * @brief Displays the line information to the console.
 */
void Line::displayInfo() const {
    std::cout << "-------------------------Line-------------------- "<< std::endl;
    std::cout << "Line ID: " << id << std::endl;
    std::cout << "Outgoing Current: " << outCurrent << std::endl;
    std::cout << "Impedance: " << impedance << std::endl;
    std::cout << "Capacitance: " << capacitance << std::endl;
    std::cout << "Inductance: " << inductance << std::endl;
    std::cout << "------------------------------------------------- "<< std::endl;
}
