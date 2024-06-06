#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
#include <unordered_map>

class FileHandler {
public:
    // Read lines from a file and return them as a vector of strings.
    static std::vector<std::string> readLines(const std::string& filename);

    // Parse an input file containing boolean states and return them as a map.
    static std::unordered_map<std::string, bool> parseInputFile(const std::string& filename);
};

#endif // FILE_HANDLER_H
