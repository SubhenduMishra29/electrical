#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include <gtkmm.h>

class SplashScreen : public Gtk::Window {
public:
    SplashScreen();
    virtual ~SplashScreen();

private:
    Gtk::Image splash_image; // Example: Use Gtk::Image for displaying an image
    Gtk::Box splash_box;     // Container for layout

    void on_timeout();       // Timeout handler for closing the splash screen
};

#endif // SPLASH_SCREEN_H
