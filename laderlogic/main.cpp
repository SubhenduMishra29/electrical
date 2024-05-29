#include <iostream>
#include "simulator.h"
#include "logic_element.h"
#include "timer_element.h"
#include "output_element.h"

int main() {
    // Create a Simulator instance
    Simulator simulator;

    // Define inputs
    simulator.setInput("start_button", true); // Start button pressed

    // Define ladder logic for Star/Delta starter
    Rung star_rung;
    star_rung.addElement(std::make_shared<LogicElement>("start_button", true, AND));
    star_rung.addElement(std::make_shared<OutputElement>("star_output", true)); // Initial Star connection

    Rung transition_timer;
    transition_timer.addElement(std::make_shared<LogicElement>("start_button", true, AND));
    transition_timer.addElement(std::make_shared<TimerElement>(5)); // 5 ticks for timer

    Rung delta_rung;
    delta_rung.addElement(std::make_shared<LogicElement>("start_button", true, AND));
    delta_rung.addElement(std::make_shared<LogicElement>("transition_timer", true, AND)); // After timer expires
    delta_rung.addElement(std::make_shared<OutputElement>("delta_output", true)); // Switch to Delta connection

    // Add rungs to the simulator
    simulator.addRung(star_rung);
    simulator.addRung(transition_timer);
    simulator.addRung(delta_rung);

    // Simulate ladder logic
    for (int i = 0; i < 10; i++) {
        std::cout << "Tick " << i << ":\n";
        simulator.simulate();
        std::cout << "Star Output State: " << (simulator.getOutput("star_output") ? "Engaged" : "Disengaged") << std::endl;
        std::cout << "Delta Output State: " << (simulator.getOutput("delta_output") ? "Engaged" : "Disengaged") << std::endl;
    }

    return 0;
}
