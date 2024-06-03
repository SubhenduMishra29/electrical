#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>

class FileHandler {
public:
    static std::vector<std::string> readLines(const std::string& filename);
};

#endif // FILE_HANDLER_H
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <unordered_map>
#include <memory>

class FileHandler {
public:
    static std::unordered_map<std::string, bool> parseInputFile(const std::string& filename);
};

#endif // FILE_HANDLER_H
