#ifndef SLD_H
#define SLD_H

#include "bus.h"
#include "line.h"
#include <vector>
#include "PowerSystemError.h"

// Class to represent the Single Line Diagram (SLD)
class SLD {
public:
    // Constructor
    SLD();

    // Function to assemble the SLD
    void assemble();

    // Getters
    std::vector<Bus>& getBuses();
    const std::vector<Bus>& getBuses() const;
    std::vector<Line>& getLines();
    const std::vector<Line>& getLines() const;

private:
    std::vector<Bus> buses;  // List of buses in the SLD
    std::vector<Line> lines; // List of lines in the SLD
};

#endif // SLD_H
