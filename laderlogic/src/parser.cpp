/*
 * File: parser.cpp
 * Author: Subhendu Mishra
 * Description: Implementation of the Parser class for parsing ladder logic configuration files.
 * License: GPL (General Public License)
 */

#include "parser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Parse a ladder logic file and return a shared pointer to the Ladder object
std::shared_ptr<Ladder> Parser::parseLadderFile(const std::string& filename, const std::unordered_map<std::string, bool>& states) {
    auto ladder = std::make_shared<Ladder>();

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string keyword;
        iss >> keyword;

        if (keyword == "element") {
            std::string elementType, elementName;
            bool elementState;
            iss >> elementType >> elementName >> elementState;

            std::shared_ptr<RungElement> element;
            if (elementType == "output") {
                element = std::make_shared<OutputElement>(elementName, elementState);
            }

            ladder->addElement(element);
        }
    }

    file.close();
    return ladder;
}
