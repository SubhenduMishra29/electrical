#ifndef OUTPUT_GENERATOR_H
#define OUTPUT_GENERATOR_H

#include "power_system.h"
#include "PowerSystemError.h"

/**
 * @class OutputGenerator
 * @brief Class for generating reports based on the power system analysis.
 * 
 * This class includes methods for creating reports of the power system's
 * state and analysis results. The reports can be saved to a specified file.
 */
class OutputGenerator {
public:
    /**
     * @brief Generate a report of the power system state and analysis results.
     * 
     * This static method generates a report from the given PowerSystem
     * object and saves it to the specified file.
     * 
     * @param powerSystem The PowerSystem object containing system data and results.
     * @param filename The name of the file where the report will be saved.
     */
    static void generateReport(const PowerSystem& powerSystem, const std::string& filename);
};

#endif // OUTPUT_GENERATOR_H
