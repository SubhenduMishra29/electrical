/*
 * File: parser.h
 * Author: Subhendu Mishra
 * Description: Declaration of the Parser class for parsing ladder logic configuration files.
 * License: GPL (General Public License)
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <memory>
#include "ladder.h"

// Class for parsing and building the ladder logic structure
class Parser {
public:
    // Parse a ladder logic file and return a shared pointer to the Ladder object
    static std::shared_ptr<Ladder> parseLadderFile(const std::string& filename, const std::unordered_map<std::string, bool>& states);
};

#endif // PARSER_H
