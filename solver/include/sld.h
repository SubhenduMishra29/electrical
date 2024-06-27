#ifndef SLD_H
#define SLD_H

#include "bus.h"
#include "transformer.h"
#include "generator.h"
#include "load.h"
#include "transmission_line.h"
#include "circuit_breaker.h"
#include "relay.h"
#include "capacitor.h"
#include "reactor.h"
#include "grid.h"
#include "CT.h"
#include "PT.h"
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
