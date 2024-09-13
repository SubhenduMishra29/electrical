// Function to split a string into numeric and character parts
#include "lib/parser_utils.h"


SplitResult splitNumberAndChars(const std::string& str) {
    SplitResult result;
    size_t i = 0;
    // Extract numeric part
    while (i < str.length() && (isdigit(str[i]) || str[i] == '.')) {
        result.numberPart += str[i];
        ++i;
    }
    // Extract remaining part (units)
    while (i < str.length()) {
        result.charPart += str[i];
        ++i;
    }
    return result;
}