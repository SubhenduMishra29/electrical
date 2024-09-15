/**
 * @file grid.h
 * @brief Header file for the Grid class.
 * 
 * This file contains the definition of the Grid class, which represents a power grid and includes various attributes and methods related to grid characteristics and simulations.
 * 
 * @author Subhendu Mishra
 * @date [Date]
 * @license GPL - [License URL]
 */

#ifndef GRID_H
#define GRID_H

#include "voltage.h"  ///< Include the header for Voltage class

/**
 * @class Grid
 * @brief Represents a power grid with various electrical characteristics.
 * 
 * The Grid class models a power grid including its voltage, power, frequency, and other attributes. It also provides methods to simulate faults and handle protection mechanisms.
 * 
 * @author [Your Name]
 * @date [Date]
 */
class Grid {
public:
    /**
     * @brief Constructs a Grid object with specified attributes.
     * @param voltage The voltage of the grid.
     * @param availablePower The available power of the grid.
     * @param frequency The frequency of the grid.
     * @param numberOfPhases The number of phases in the grid.
     * @param voltageRegulation The voltage regulation of the grid.
     * @param powerFactor The power factor of the grid.
     * @param harmonicDistortion The harmonic distortion of the grid.
     * @param transientResponse The transient response of the grid.
     */
    std::string id;
    Grid(Voltage voltage, double availablePower, double frequency, int numberOfPhases,
         double voltageRegulation, double powerFactor,
         double harmonicDistortion, double transientResponse);

    // Getter and setter methods...

    /**
     * @brief Simulates a fault in the grid.
     * 
     * This method simulates a fault by reducing the available power by 10%.
     */
    void simulateFault();

    /**
     * @brief Handles protection mechanisms in response to a fault.
     * 
     * This method can be expanded based on specific protection logic, such as tripping circuit breakers or isolating faulty sections.
     */
    void handleProtection();

private:
    Voltage voltage;  ///< Voltage of the grid
    double availablePower;  ///< Available power of the grid
    double frequency;  ///< Frequency of the grid
    int numberOfPhases;  ///< Number of phases in the grid
    double voltageRegulation;  ///< Voltage regulation of the grid
    double powerFactor;  ///< Power factor of the grid
    double harmonicDistortion;  ///< Harmonic distortion of the grid
    double transientResponse;  ///< Transient response of the grid
    double threePhaseMVAsc;  ///< Three-phase MVAsc value
    double onePhaseMVAsc;  ///< One-phase MVAsc value
    double xRRatioPositive;  ///< X/R ratio for positive sequence
    double xRRatioZero;  ///< X/R ratio for zero sequence
    double threePhaseSymmetricalKAsc;  ///< Three-phase symmetrical KAsc value
    double onePhaseSymmetricalKAsc;  ///< One-phase symmetrical KAsc value
};

#endif // GRID_H
