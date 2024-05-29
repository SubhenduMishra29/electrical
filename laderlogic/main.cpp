#include <iostream>
#include "simulator.h"

int main() {
    // Create a Simulator instance
    Simulator simulator;

    // Define inputs and outputs
    simulator.setInput("sensor1", true);
    simulator.setInput("sensor2", false);

    // Define ladder logic
    Rung rung1, rung2;
    rung1.addElement("sensor1", true);
    rung1.addElement("sensor2", false);
    rung1.addElement("output1", true);
    rung2.addElement("sensor1", false);
    rung2.addElement("output2", true);

    // Add rungs to the simulator
    simulator.addRung(rung1);
    simulator.addRung(rung2);

    // Simulate ladder logic
    simulator.simulate();

    // Get output states
    std::cout << "Output 1 State: " << simulator.getOutput("output1") << std::endl;
    std::cout << "Output 2 State: " << simulator.getOutput("output2") << std::endl;

    return 0;
}
