/*
 * File: Port.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#include <string>

class Connection {
private:
    int id;
    std::string name;

public:
    Connection(int connectionId, const std::string& connectionName) : id(connectionId), name(connectionName) {}

    // Getters for connection ID and name
    int getId() const { return id; }
    std::string getName() const { return name; }
};

class Port {
private:
    std::string name;
    std::string type; // Type of the port (NO or NC)
    Connection inConnection;
    Connection outConnection;

public:
    Port(const std::string& portName, const std::string& portType) : name(portName), type(portType), inConnection(-1, ""), outConnection(-1, "") {}

    // Methods to manage connections
    void connectIn(const Connection& connection) { inConnection = connection; }
    void connectOut(const Connection& connection) { outConnection = connection; }
    void disconnectIn() { inConnection = Connection(-1, ""); }
    void disconnectOut() { outConnection = Connection(-1, ""); }

    // Method to check if port is connected
    bool isConnected() const { return inConnection.getId() != -1 || outConnection.getId() != -1; }

    // Getters for connections
    Connection getInConnection() const { return inConnection; }
    Connection getOutConnection() const { return outConnection; }

    // Getter for port type
    std::string getType() const { return type; }

    // Method to toggle port type based on coil state
    void toggleType(bool coilState) {
        if (coilState) {
            // Coil is on, change from NO to NC
            if (type == "NO") {
                type = "NC";
            }
        } else {
            // Coil is off, change from NC to NO
            if (type == "NC") {
                type = "NO";
            }
        }
    }
};
