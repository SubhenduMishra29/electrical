#include <gtkmm.h>
#include "splash_screen.h"
#include "electrical/gui/gui_component.h" // Assuming GuiComponent is in electrical/gui/gui_component.h

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.main_app");

    // Create and show the splash screen
    SplashScreen splashScreen;

    // Run the application main loop after a short delay to display splash screen
    Glib::signal_timeout().connect([&]() {
        // Create main application window
        Gtk::Window window;
        window.set_title("Main Application");

        // Create an instance of GuiComponent
        GuiComponent guiComponent;
        window.add(guiComponent);

        // Show window and run application
        window.show_all();
        return app->run(window);
    }, 1000); // Delay before showing main window (adjust as needed)

    return app->run();
}
