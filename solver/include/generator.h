#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>

class Generator {
private:
    std::string id;
    double powerOutput; // in MW

public:
    Generator(const std::string& id, double powerOutput);
    ~Generator();

    std::string getId() const;
    double getPowerOutput() const;
};

#endif // GENERATOR_H
