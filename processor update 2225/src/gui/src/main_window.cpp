#include "main_window.h"
#include <gtk/gtk.h>

MainWindow::MainWindow() {
    // Load the UI from the Glade file
    builder = gtk_builder_new_from_file("gui/glade/avr_simulator.glade");

    // Get the main window widget
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    
    // Connect signals (like button clicks)
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // Get references to important UI elements
    startButton = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));
    stopButton = GTK_WIDGET(gtk_builder_get_object(builder, "stop_button"));
    resetButton = GTK_WIDGET(gtk_builder_get_object(builder, "reset_button"));
    statusLabel = GTK_WIDGET(gtk_builder_get_object(builder, "status_label"));
    
    // Connect button signals
    g_signal_connect(startButton, "clicked", G_CALLBACK(on_start_button_clicked), this);
    g_signal_connect(stopButton, "clicked", G_CALLBACK(on_stop_button_clicked), this);
    g_signal_connect(resetButton, "clicked", G_CALLBACK(on_reset_button_clicked), this);
}

void MainWindow::show() {
    gtk_widget_show_all(window);
}

// Button click handlers
void MainWindow::on_start_button_clicked(GtkWidget *widget, gpointer data) {
    MainWindow *self = static_cast<MainWindow*>(data);
    gtk_label_set_text(GTK_LABEL(self->statusLabel), "Simulation Started...");
}

void MainWindow::on_stop_button_clicked(GtkWidget *widget, gpointer data) {
    MainWindow *self = static_cast<MainWindow*>(data);
    gtk_label_set_text(GTK_LABEL(self->statusLabel), "Simulation Stopped.");
}

void MainWindow::on_reset_button_clicked(GtkWidget *widget, gpointer data) {
    MainWindow *self = static_cast<MainWindow*>(data);
    gtk_label_set_text(GTK_LABEL(self->statusLabel), "Simulation Reset.");
}
