#ifndef SCANLINE_H
#define SCANLINE_H

typedef struct {
   int x; int y;
} point;

void scanline();
void main_scanline(GtkButton* btn, GtkWidget* win_menu);

#endif
