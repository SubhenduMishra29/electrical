/*
 * File: ErrorHandling.h
 * Author: Subhendu Mishra
 * License: GPL
 */

#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <iostream>
#include <stdexcept>

/**
 * @brief Exception class for maximum current exceeded error.
 */
class MaxCurrentExceededException : public std::runtime_error {
public:
    /**
     * @brief Constructor for MaxCurrentExceededException.
     * @param message Error message.
     */
    explicit MaxCurrentExceededException(const std::string& message) : std::runtime_error(message) {}
};

/**
 * @brief Function to handle exceptions.
 * @param e The exception object.
 */
void handleException(const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
}

#endif // ERROR_HANDLING_H
