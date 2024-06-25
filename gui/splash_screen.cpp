#include "splash_screen.h"

SplashScreen::SplashScreen()
    : splash_box(Gtk::ORIENTATION_VERTICAL) {
    set_title("Splash Screen");
    set_default_size(400, 300);

    // Load an image for splash screen (replace with your image path)
    splash_image.set("path_to_your_splash_image.png");
    splash_box.pack_start(splash_image);

    add(splash_box);
    show_all();

    // Timeout to close splash screen after 3 seconds (adjust as needed)
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &SplashScreen::on_timeout), 3000);
}

SplashScreen::~SplashScreen() {}

void SplashScreen::on_timeout() {
    close();
}
