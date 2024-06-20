// input_parser.h
#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "power_system.h"
#include "PowerSystemError.h"

class InputParser {
public:
    static PowerSystem parseInputFile(const std::string& filename);
};

#endif // INPUT_PARSER_H
