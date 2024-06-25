#include "splash_screen.h"
#include "splash_image.h"  // Include the generated header file

SplashScreen::SplashScreen()
    : Gtk::Window(Gtk::WINDOW_POPUP),  // Create a popup window without decorations
      box(Gtk::ORIENTATION_VERTICAL) {
    set_title("Splash Screen");

    // Create GdkPixbuf from embedded image data
    Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_data(
        splash_image_jpg, Gdk::Colorspace::COLORSPACE_RGB,
        false, 8, splash_image_jpg_len);

    // Set the pixbuf to the Gtk::Image
    splashImage.set(pixbuf);

    // Get screen dimensions
    Gdk::Rectangle screenRect;
    auto display = get_display();
    auto monitor = display->get_primary_monitor();
    monitor->get_geometry(screenRect);

    // Calculate image position
    int imageWidth = pixbuf->get_width();
    int imageHeight = pixbuf->get_height();
    int alignmentX = (screenRect.get_width() - imageWidth) / 2;
    int alignmentY = (screenRect.get_height() - imageHeight) / 2;

    // Center the image inside the box
    box.pack_start(splashImage);
    box.set_homogeneous(false);
    box.set_margin_top(alignmentY);
    box.set_margin_bottom(alignmentY);
    box.set_margin_start(alignmentX);
    box.set_margin_end(alignmentX);

    add(box);

    // Set the window size to match the image size
    set_default_size(imageWidth, imageHeight);

    // Position the window at the center of the screen
    set_position(Gtk::WIN_POS_CENTER_ALWAYS);

    // Show the window and its contents
    show_all();

    // Timeout to close splash screen after 8 seconds
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &SplashScreen::on_timeout), 8000);
}

SplashScreen::~SplashScreen() {}

void SplashScreen::on_timeout() {
    close();
}
