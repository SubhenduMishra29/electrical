/*
 * File: main.cpp
 * Author: Subhendu Mishra
 * Description: Main function for running the ladder logic simulator.
 * License: GPL (General Public License)
 */

#include <iostream>
#include "simulator.h"

int main() {
    try {
        // Initialize the simulator with a ladder logic file
        Simulator simulator("ladder_logic.txt");

        // Set input states (if needed)
        simulator.setInput("Input1", true);
        simulator.setInput("Input2", false);

        // Run the simulation
        simulator.simulate();

        // Get and print the output states
        auto outputStates = simulator.getOutputStates();
        for (const auto& output : outputStates) {
            std::cout << output.first << ": " << (output.second ? "ON" : "OFF") << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
