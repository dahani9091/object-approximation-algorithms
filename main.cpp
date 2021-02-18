
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "graphics.h"
#include "bresenham.h"
#include "bezier.h"
void load_css(void);



int main(int argc,char* argv[]){
    gtk_init(&argc,&argv);

    /// loading css
    load_css();

    ///  create and get builder from 'glade' files
    GtkBuilder* builder = gtk_builder_new_from_file ("glade/main.glade");

    ///  create and get other widjets from 'glade' files  btn_bresenhamL
    GtkWidget* win_menu;
    win_menu = GTK_WIDGET(gtk_builder_get_object(builder,"win_menu"));
    GtkWidget* btn_bresenhamL=GTK_WIDGET(gtk_builder_get_object(builder,"btn_bresenhamL"));
    GtkWidget* btn_bresenhamC=GTK_WIDGET(gtk_builder_get_object(builder,"btn_bresenhamC"));
    GtkWidget* btn_bezier=GTK_WIDGET(gtk_builder_get_object(builder,"btn_bezier"));

    ///connect signals
    g_signal_connect(btn_bresenhamL,"clicked",G_CALLBACK(bresenham_line),win_menu);
    g_signal_connect(btn_bresenhamC,"clicked",G_CALLBACK(bresenham_circle),win_menu);
    g_signal_connect(btn_bezier,"clicked",G_CALLBACK(bezier_curve),win_menu);


    ///show what was made
    gtk_widget_show_all(win_menu);

    gtk_main();
    return 0;
}


void load_css(void)
{
    GtkCssProvider *provider;
    GdkDisplay     *display;
    GdkScreen      *screen;
    //
    const gchar *css_style_file = "main.css";
    GFile       *css_fp         = g_file_new_for_path(css_style_file);
    GError      *error          = 0;
    //
    provider = gtk_css_provider_new();
    display  = gdk_display_get_default();
    screen   = gdk_display_get_default_screen(display);
    //
    gtk_style_context_add_provider_for_screen(screen,GTK_STYLE_PROVIDER(provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(provider,css_fp,&error);
    //
    g_object_unref(provider);
}

