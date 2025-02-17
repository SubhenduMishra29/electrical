#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtk/gtk.h>

class MainWindow {
public:
    MainWindow();
    void show();

private:
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *startButton;
    GtkWidget *stopButton;
    GtkWidget *resetButton;
    GtkWidget *statusLabel;

    static void on_start_button_clicked(GtkWidget *widget, gpointer data);
    static void on_stop_button_clicked(GtkWidget *widget, gpointer data);
    static void on_reset_button_clicked(GtkWidget *widget, gpointer data);
};

#endif
