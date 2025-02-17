#include "gui.h"
#include <gtk/gtk.h>

GtkBuilder *builder;
GtkWidget *window;

void on_window_destroy() {
    gtk_main_quit();
}

void init_gui(int *argc, char ***argv) {
    gtk_init(argc, argv);
    
    builder = gtk_builder_new_from_file("gui/glade/avr_simulator.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    
    gtk_builder_connect_signals(builder, NULL);
}

void run_gui() {
    gtk_widget_show_all(window);
    gtk_main();
}
