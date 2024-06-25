#ifndef GUI_COMPONENT_H
#define GUI_COMPONENT_H

// Include necessary GTKmm headers
#include <gtkmm.h>
#include <iostream>

// Author information
// Replace with your name and other relevant details
#define AUTHOR "Subhendu Mishra"
#define PROJECT_NAME "Your Project Name"
#define PROJECT_URL "https://example.com"
#define PROJECT_EMAIL "email@example.com"

// GPL license information
// You can replace this with the appropriate license text or file
#define LICENSE "GPL-3.0"

class GuiComponent : public Gtk::Box {
public:
    GuiComponent();
    virtual ~GuiComponent(); // Destructor

private:
    Gtk::Button button; // Example widget

    // Example callback function for button click
    void on_button_clicked();
};

#endif // GUI_COMPONENT_H
