/*
 * File: ErrorHandling.h
 * Author: Subhendu Mishra
 * License: GPL
 */
#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <stdexcept>
#include <string>

// Custom exception class for maximum current exceeded error
class MaxCurrentExceededException : public std::invalid_argument {
public:
    explicit MaxCurrentExceededException(const std::string& message) : std::invalid_argument(message) {}
};

// Utility function for error handling
void handleException(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

#endif // ERROR_HANDLING_H
