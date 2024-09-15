#ifndef CONFIG_H
#define CONFIG_H
/**
 * Author: Subhendu Mishra
 * License: GPL
 */
#include <string>

/**
 * @brief Namespace for configuration settings.
 */
namespace Config {

/**
 * @brief Maximum number of iterations for load flow analysis.
 */
const int MAX_ITERATIONS = 100;

/**
 * @brief Convergence tolerance for load flow analysis.
 */
const double CONVERGENCE_TOLERANCE = 1e-6;

/**
 * @brief File path for default configuration settings.
 */
const std::string DEFAULT_CONFIG_FILE = "config.txt";

/**
 * @brief Reads configuration settings from a file.
 * 
 * @param filename The name of the configuration file.
 * @return True if configuration was read successfully, false otherwise.
 */
bool readConfigFile(const std::string& filename);

/**
 * @brief Retrieves the value of a specific configuration parameter.
 * 
 * @param key The key of the configuration parameter.
 * @return The value of the configuration parameter as a string.
 */
std::string getConfigValue(const std::string& key);

} // namespace Config

#endif // CONFIG_H
