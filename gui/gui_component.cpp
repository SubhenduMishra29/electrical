#include "gui_component.h"

// Constructor definition
GuiComponent::GuiComponent() {
    // Initialize your GUI components here
    button.set_label("Click me!");
    button.signal_clicked().connect(sigc::mem_fun(*this, &GuiComponent::on_button_clicked));
    
    // Pack components into the Box
    pack_start(button, Gtk::PACK_SHRINK);
}

// Destructor definition
GuiComponent::~GuiComponent() {
    // Perform cleanup if needed
}

// Example callback function for button click
void GuiComponent::on_button_clicked() {
    std::cout << "Button clicked!" << std::endl;
}
