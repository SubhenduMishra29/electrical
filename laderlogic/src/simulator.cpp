void Simulator::simulate() {
    // Create a temporary map to hold the updated output states
    std::unordered_map<std::string, bool> updated_output_states = output_states;

    // Iterate through each rung in the ladder logic
    for (auto& rung : ladder_logic) {
        // Evaluate the current rung based on the current input states
        bool result = rung.evaluate(input_states);

        // Update output states for each element in the rung
        for (auto& element : rung.getElements()) {
            // If the element is a coil, update its output state
            if (auto coil = std::dynamic_pointer_cast<Coil>(element)) {
                updated_output_states[coil->getName()] = result;
            } 
            // If the element is a bulb, update its output state
            else if (auto bulb = std::dynamic_pointer_cast<Bulb>(element)) {
                updated_output_states[bulb->getName()] = result;
            }
        }
    }

    // Update the main output_states map with the updated states from the temporary map
    output_states = updated_output_states;
}
