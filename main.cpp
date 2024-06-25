#include <gtkmm.h>
#include "splash_screen.h"
#include "electrical/gui/gui_component.h" // Assuming GuiComponent is in electrical/gui/gui_component.h

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.main_app");

    // Create and show the splash screen
    SplashScreen splashScreen;

    // Timeout to close splash screen after 8 seconds
    Glib::signal_timeout().connect([&]() {
        splashScreen.close();
        return false; // Return false to stop the timeout after the first invocation
    }, 8000); // 8000 milliseconds = 8 seconds

    // Run the application main loop
    int status = app->run(splashScreen);

    if (status != 0) {
        // Handle initialization failure if needed
        return status;
    }

    // Create main application window
    Gtk::Window mainWindow;
    mainWindow.set_title("Main Application");

    // Create an instance of GuiComponent
    GuiComponent guiComponent;
    mainWindow.add(guiComponent);

    // Show window and run application
    mainWindow.show_all();
    return app->run(mainWindow);
}
