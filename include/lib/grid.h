#ifndef GRID_H
#define GRID_H

#include <memory>
#include <string>
#include <iostream>
#include <complex>

#include <cmath>
#include "line.h"
#include "voltage.h"
#include "current.h"  // Include the header for the Current class

class Grid {
private:
    std::string id;
    Voltage voltage; ///< Voltage of the grid
    Current current; ///< Current in the grid
    double frequency; ///< Frequency of the grid
    double base_power; ///< Power in the grid
    double SC_capacity; ///< Short Circuit Capacity
    std::shared_ptr<Line> connectedLine; ///< The single line connected to the grid

    // Retrieves a Line object by its ID
    std::shared_ptr<Line> getLineById(const std::string& lineId);

public:
    Grid(const std::string& id, const std::string& voltage);
    
    // Previous constructors can be added here as needed.

    /**
     * @brief Sets the voltage of the grid and updates the connected line.
     * @param v The new voltage value.
     */
    void setVoltage(const Voltage& v);

    /**
     * @brief Sets the current of the grid.
     * @param c The new current value.
     */
    void setCurrent(const Current& c);

    /**
     * @brief Sets the frequency of the grid.
     * @param f The new frequency value.
     */
    void setFrequency(double f);

    /**
     * @brief Sets the power of the grid.
     * @param p The new power value.
     */
    void setPower(double p);

    /**
     * @brief Connects a line to the grid.
     * @param lineId The ID of the line to be connected.
     */
    void connectLine(const std::string& lineId);

    /**
     * @brief Updates the connected line with the current grid properties.
     */
    void updateConnectedLine();

    /**
     * @brief Calculates various parameters of the grid, such as impedance, power factor, and short circuit current.
     */
    void calculateParameters();

    /**
     * @brief Displays the grid information.
     */
    void displayInfo() const;
};

#endif // GRID_H
