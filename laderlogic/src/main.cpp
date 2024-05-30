#include <iostream>
#include "simulator.h"
#include "pushbutton.h"
#include "contact.h"
#include "coil.h"
#include "bulb.h"

int main() {
    // Create a Simulator instance
    Simulator simulator;

    // Define inputs
    simulator.setInput("start_button", true); // Start button pressed
    simulator.setInput("stop_button", false); // Stop button not pressed

    // Define ladder logic

    // Rung 1: Start button pressed AND Stop button not pressed
    Rung rung1;
    rung1.addElement(std::make_shared<Contact>("start_button", true));
    rung1.addElement(std::make_shared<Contact>("stop_button", false));
    rung1.addElement(std::make_shared<Coil>("motor")); // Turn on motor

    // Rung 2: Motor is on
    Rung rung2;
    rung2.addElement(std::make_shared<Coil>("motor")); // Motor remains on
    rung2.addElement(std::make_shared<Bulb>("lamp")); // Turn on lamp

    // Add rungs to the simulator
    simulator.addRung(rung1);
    simulator.addRung(rung2);

    // Simulate ladder logic
    simulator.simulate();

    // Print output states
    std::cout << "Motor State: " << (simulator.getOutput("motor") ? "On" : "Off") << std::endl;
    std::cout << "Lamp State: " << (simulator.getOutput("lamp") ? "On" : "Off") << std::endl;

    return 0;
}
