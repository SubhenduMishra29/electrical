#ifndef POWER_SYSTEM_ERROR_H
#define POWER_SYSTEM_ERROR_H

#include <exception>
#include <string>

class PowerSystemError : public std::exception {
private:
    std::string message;

public:
    explicit PowerSystemError(const std::string& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileNotFoundError : public PowerSystemError {
public:
    explicit FileNotFoundError(const std::string& msg) : PowerSystemError("File Not Found Error: " + msg) {}
};

class LoadFlowError : public PowerSystemError {
public:
    explicit LoadFlowError(const std::string& msg) : PowerSystemError("Load Flow Error: " + msg) {}
};

// Define other specific errors as needed
// ...

#endif // POWER_SYSTEM_ERROR_H
