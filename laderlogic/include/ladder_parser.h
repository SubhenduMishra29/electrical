/*
 * File: ladder_parser.h
 * Author: Subhendu Mishra
 * Description: Declaration of the LadderParser class for parsing ladder logic files.
 * License: GPL (General Public License)
 */

#ifndef LADDER_PARSER_H
#define LADDER_PARSER_H

#include <string>
#include <unordered_map>

class LadderParser {
public:
    // Parse a ladder logic file containing boolean states and return them as a map.
    static std::unordered_map<std::string, bool> parseLadderFile(const std::string& filename);
};

#endif // LADDER_PARSER_H
