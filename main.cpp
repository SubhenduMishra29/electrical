#include <gtkmm.h>
#include "electrical/gui/gui_component.cpp"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.main_app");

    Gtk::Window window;
    window.set_title("Main Application");

    // Use the GUI module component
    GuiComponent guiComponent;
    window.add(guiComponent);

    return app->run(window);
}
