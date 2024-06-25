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

    // Run the application main loop with splashScreen
    int status = app->run(splashScreen);

    if (status != 0) {
        // Handle initialization failure if needed
        return status;
    }

    // Create main application window
    Gtk::Window mainWindow;
    mainWindow.set_title("Main Application");
    mainWindow.set_default_size(800, 600); // Set a default size for the window

    // Create a vertical box container for main window
    Gtk::Box mainBox(Gtk::ORIENTATION_VERTICAL);
    mainWindow.add(mainBox);

    // Create a menu bar
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuFile("File");
    Gtk::Menu menu;
    Gtk::MenuItem menuExit("Exit");
    menu.append(menuExit);
    menuFile.set_submenu(menu);
    menuBar.append(menuFile);
    mainBox.pack_start(menuBar, Gtk::PACK_SHRINK);

    // Handle exit menu item
    menuExit.signal_activate().connect([&]() {
        mainWindow.close();
    });

    // Create a label
    Gtk::Label label("Welcome to Main Window!");
    label.set_margin_top(20);
    label.set_margin_bottom(20);
    label.set_halign(Gtk::ALIGN_CENTER);
    mainBox.pack_start(label, Gtk::PACK_SHRINK);

    // Create a button
    Gtk::Button button("Click Me!");
    button.signal_clicked().connect([&]() {
        Gtk::MessageDialog dialog(*mainWindow, "Button Clicked!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
        dialog.run();
    });
    mainBox.pack_start(button, Gtk::PACK_SHRINK);

    // Show all widgets
    mainWindow.show_all();

    // Run the application main loop with mainWindow
    return app->run(mainWindow);
}
