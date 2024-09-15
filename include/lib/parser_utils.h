#ifndef PARSER_UTILS_H
#define PARSER_UTILS_H
#include <iostream>
#include <string>
#include <cctype>

struct SplitResult {
    std::string numberPart;
    std::string charPart;
};

SplitResult splitNumberAndChars(const std::string& str);


#endif // PARSER_UTILS_H
