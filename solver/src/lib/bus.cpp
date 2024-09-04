#include "lib/bus.h"

Bus::Bus(const std::string& name, const Voltage& busVoltage, BusType type)
    : busVoltage(busVoltage), type(type), current(0.0), inflowPower(0.0), outflowPower(0.0),
      id(name), shuntConductor("None"), voltageRegulator("On"), regulatorSetpoint("11kV"),
      voltageBand("±2%"), emergencyBackup("No"), harmonicDistortion("0.5%"), busbarProtection("Yes") {}

void Bus::addTransmissionLine(TransmissionLine* line) {
    transmissionLines.push_back(line);
    recalculateBusState(); // Recalculate bus state whenever a new line is added
}

void Bus::removeTransmissionLine(TransmissionLine* line) {
    // Correctly remove the transmission line from the vector
    auto it = std::remove(transmissionLines.begin(), transmissionLines.end(), line);
    if (it != transmissionLines.end()) {
        transmissionLines.erase(it, transmissionLines.end());
        recalculateBusState(); // Recalculate bus state after removal
    }
}

Voltage Bus::getVoltage() const {
    return busVoltage;
}

void Bus::setVoltage(const Voltage& voltage) {
    this->busVoltage = voltage;
    recalculateBusState(); // Recalculate bus state whenever voltage is updated
}

double Bus::getCurrent() const {
    return current;
}

void Bus::setCurrent(double current) {
    this->current = current;
    recalculateBusState(); // Recalculate bus state whenever current is updated
}

double Bus::getInflowPower() const {
    return inflowPower;
}

double Bus::getOutflowPower() const {
    return outflowPower;
}

BusType Bus::getType() const {
    return type;
}

void Bus::setType(BusType type) {
    this->type = type;
}

std::string Bus::getId() const {
    return id;
}

void Bus::setId(const std::string& id) {
    this->id = id;
}

std::string Bus::getShuntConductor() const {
    return shuntConductor;
}

void Bus::setShuntConductor(const std::string& shuntConductor) {
    this->shuntConductor = shuntConductor;
}

std::string Bus::getVoltageRegulator() const {
    return voltageRegulator;
}

void Bus::setVoltageRegulator(const std::string& voltageRegulator) {
    this->voltageRegulator = voltageRegulator;
}

std::string Bus::getRegulatorSetpoint() const {
    return regulatorSetpoint;
}

void Bus::setRegulatorSetpoint(const std::string& regulatorSetpoint) {
    this->regulatorSetpoint = regulatorSetpoint;
}

std::string Bus::getVoltageBand() const {
    return voltageBand;
}

void Bus::setVoltageBand(const std::string& voltageBand) {
    this->voltageBand = voltageBand;
}

std::string Bus::getEmergencyBackup() const {
    return emergencyBackup;
}

void Bus::setEmergencyBackup(const std::string& emergencyBackup) {
    this->emergencyBackup = emergencyBackup;
}

std::string Bus::getHarmonicDistortion() const {
    return harmonicDistortion;
}

void Bus::setHarmonicDistortion(const std::string& harmonicDistortion) {
    this->harmonicDistortion = harmonicDistortion;
}

std::string Bus::getBusbarProtection() const {
    return busbarProtection;
}

void Bus::setBusbarProtection(const std::string& busbarProtection) {
    this->busbarProtection = busbarProtection;
}

void Bus::recalculateBusState() {
    // Placeholder method for recalculating voltage and current at the bus
    // This would involve solving power flow equations, which depend on the specifics
    // of the system model, including line impedances, connected loads, etc.

    calculatePowerFlow();

    // Update the bus voltage and current based on inflow and outflow power
    // Placeholder logic: simplistic adjustment based on inflow and outflow
    double voltageMagnitude = busVoltage.getVoltageMagnitude() - (outflowPower - inflowPower) * 0.01;
    double voltageAngle = busVoltage.getVoltageAngle(); // Keep the same angle for simplicity

    busVoltage.setVoltage(std::polar(voltageMagnitude, voltageAngle));

    // Assume the current is proportional to the power difference
    current = std::abs((inflowPower - outflowPower) / voltageMagnitude);
}

void Bus::calculatePowerFlow() {
    inflowPower = 0.0;
    outflowPower = 0.0;

    for (const auto& line : transmissionLines) {
        // Assume TransmissionLine has methods to get connected bus voltage and current
        Voltage connectedBusVoltage = line->getConnectedBusVoltage(this);
        double powerFlow = std::real(busVoltage.getVoltage() * std::conj(connectedBusVoltage.getVoltage() * current));

        if (powerFlow > 0) {
            inflowPower += powerFlow;
        } else {
            outflowPower += -powerFlow;
        }
    }
}
