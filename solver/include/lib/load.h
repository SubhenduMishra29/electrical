#ifndef LOAD_H
#define LOAD_H

#include <string>
#include "PowerSystemError.h"

/// @brief 
class Load {
private:
    std::string id;
    double powerDemand; // in MW

public:
    /// @brief 
    /// @param id 
    /// @param powerDemand 
    Load(const std::string& id, double powerDemand);
    ~Load();

    std::string getId() const;
    double getPowerDemand() const;
    double getPowerConsumption() const;
};

#endif // LOAD_H
