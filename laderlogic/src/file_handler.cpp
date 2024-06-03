#include "file_handler.h"
#include <fstream>
#include <sstream>

std::unordered_map<std::string, bool> FileHandler::parseInputFile(const std::string& filename) {
    std::unordered_map<std::string, bool> elements;

    std::ifstream file(filename);
    if (!file.is_open()) {
        // Handle error opening file
        return elements;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string elementType, elementName;
        bool initialState;

        iss >> elementType >> elementName >> initialState;

        elements[elementName] = initialState;
    }

    file.close();

    return elements;
}
