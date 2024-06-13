/*
 * File: ladder_parser.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the LadderParser class for parsing ladder logic files.
 * License: GPL (General Public License)
 */

#include "ladder_parser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Parse a ladder logic file containing boolean states and return them as a map
std::unordered_map<std::string, bool> LadderParser::parseLadderFile(const std::string& filename) {
    std::unordered_map<std::string, bool> states;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        bool state;
        iss >> name >> state;
        states[name] = state;
    }

    file.close();
    return states;
}
