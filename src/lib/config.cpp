#include "lib/config.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace Config {

static std::unordered_map<std::string, std::string> configMap;

bool readConfigFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string key;
        std::string value;
        if (std::getline(lineStream, key, '=') && std::getline(lineStream, value)) {
            configMap[key] = value;
        }
    }

    file.close();
    return true;
}

std::string getConfigValue(const std::string& key) {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second;
    }
    return "";
}

} // namespace Config
