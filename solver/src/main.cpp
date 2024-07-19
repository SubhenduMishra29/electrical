#include "power_system.h"
#include <iostream>

int main(int argc, char* argv[]) {
    PowerSystem ps;

    if (argc > 1) {
        // Load from file
        ps.loadSLDFromFile(argv[1]);
    } else {
        // Load from CLI input
        std::string cliInput = "CLI input string here"; // Replace with actual CLI input
        ps.loadSLDFromCLI(cliInput);
    }

    try {
        ps.runSimulation();
    } catch (const PowerSystemError& e) {
        std::cerr << "Power System Error: " << e.what() << std::endl;
        return 1; // Return 1 to indicate error
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1; // Return 1 to indicate error
    }

    // Optionally, check if the power flow converged
    if (ps.isConverged()) {
        std::cout << "Power flow converged successfully." << std::endl;
    } else {
        std::cout << "Power flow did not converge within specified iterations." << std::endl;
    }

    return 0;
}
