#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

/*
 * File: InputParser.h
 * Author: Subhendu Mishra
 * Description: Header file for the InputParser class, which is responsible for parsing input files
 *              and initializing the SLD (Single Line Diagram) with the components defined in the file.
 * License: GPL
 */

#include <string>
#include "SLD.h"

class InputParser {
public:
    // Function to parse input file and initialize SLD components
    void parseInputFile(const std::string& filename, SLD& sld);

private:
    // Helper functions to parse individual components
    void parseBus(const std::string& line, SLD& sld);
    void parseTransformer(const std::string& line, SLD& sld);
    void parseGenerator(const std::string& line, SLD& sld);
    void parseLoad(const std::string& line, SLD& sld);

    // Add other helper functions as needed
};

#endif // INPUT_PARSER_H
