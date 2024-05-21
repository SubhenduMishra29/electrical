/*
 * File: Port.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef PORT_H
#define PORT_H

#include <string>

/**
 * @brief Class representing a connection with an ID and name.
 */
class Connection {
private:
    int id; /**< ID of the connection */
    std::string name; /**< Name of the connection */

public:
    /**
     * @brief Constructor for Connection.
     * @param connectionId ID of the connection.
     * @param connectionName Name of the connection.
     */
    Connection(int connectionId, const std::string& connectionName) 
        : id(connectionId), name(connectionName) {}

    /**
     * @brief Getter for connection ID.
     * @return ID of the connection.
     */
    int getId() const { return id; }

    /**
     * @brief Getter for connection name.
     * @return Name of the connection.
     */
    std::string getName() const { return name; }
};

/**
 * @brief Class representing a port with an input and output connection, and voltage.
 */
class Port {
private:
    Connection inPort; /**< Input port */
    Connection outPort; /**< Output port */
    double voltage; /**< Voltage of the port */

public:
    /**
     * @brief Constructor for Port.
     * @param inPortId ID of the input port.
     * @param inPortName Name of the input port.
     * @param outPortId ID of the output port.
     * @param outPortName Name of the output port.
     */
    Port(int inPortId, const std::string& inPortName, int outPortId, const std::string& outPortName) 
        : inPort(inPortId, inPortName), outPort(outPortId, outPortName), voltage(0.0) {}

    /**
     * @brief Method to set the voltage of the port.
     * @param volt Voltage to be set.
     */
    void setVoltage(double volt) { voltage = volt; }

    /**
     * @brief Method to get the voltage of the port.
     * @return Current voltage of the port.
     */
    double getVoltage() const { return voltage; }

    /**
     * @brief Method to connect an input connection.
     * @param connection Connection to be set as input.
     */
    void connectIn(const Connection& connection) { inPort = connection; }

    /**
     * @brief Method to connect an output connection.
     * @param connection Connection to be set as output.
     */
    void connectOut(const Connection& connection) { outPort = connection; }

    /**
     * @brief Method to disconnect the input connection.
     */
    void disconnectIn() { inPort = Connection(-1, ""); }

    /**
     * @brief Method to disconnect the output connection.
     */
    void disconnectOut() { outPort = Connection(-1, ""); }

    /**
     * @brief Method to check if the port is connected.
     * @return True if either input or output connection is valid, otherwise false.
     */
    bool isConnected() const { return inPort.getId() != -1 || outPort.getId() != -1; }

    /**
     * @brief Getter for input port.
     * @return Input port.
     */
    Connection getInPort() const { return inPort; }

    /**
     * @brief Getter for output port.
     * @return Output port.
     */
    Connection getOutPort() const { return outPort; }
};

#endif // PORT_H
