#ifndef BRESENHAM_H
#define BRESENHAM_H



void bresenham_line(GtkButton* btn, GtkWidget* win_menu);
void bresenham_line_start(GtkButton* btn, GtkWidget* win);
void bresenham_circle(GtkButton* btn, GtkWidget* win);
void bresenham_circle_start(GtkButton* btn, GtkWidget* win);
//helpful functions
void pixel(int xc,int yc,int x,int y);
void back_to_menu (GtkButton* btn, GtkWidget* win);
#endif
