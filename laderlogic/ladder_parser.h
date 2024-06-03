#ifndef LADDER_PARSER_H
#define LADDER_PARSER_H

#include <string>
#include <unordered_map>

class LadderParser {
public:
    static std::unordered_map<std::string, bool> parseLadderFile(const std::string& filename);
};

#endif // LADDER_PARSER_H
