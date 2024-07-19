#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include "PowerSystemError.h"

/// @brief 
class Generator {
private:
    std::string id;
    double powerOutput; // in MW

public:
    /// @brief 
    /// @param id 
    /// @param powerOutput 
    Generator(const std::string& id, double powerOutput);
    ~Generator();

    std::string getId() const;
    double getPowerOutput() const; // Ensure this method is declared
    double getCurrentOutput() const; // Ensure this method is declared
    
};

#endif // GENERATOR_H
