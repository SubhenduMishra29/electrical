// output_generator.h
#ifndef OUTPUT_GENERATOR_H
#define OUTPUT_GENERATOR_H

#include "power_system.h"
#include "PowerSystemError.h"

class OutputGenerator {
public:
    static void generateReport(const PowerSystem& powerSystem, const std::string& filename);
};

#endif // OUTPUT_GENERATOR_H
