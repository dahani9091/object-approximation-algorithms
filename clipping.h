#ifndef CLIPPING_H
#define CLIPPING_H

// Lines where co-ordinates are (x1, y1) and (x2, y2)
struct lines {
    int x1, y1, x2, y2;
};

int sign(int x);
void clip(struct lines mylines);
void clipping(GtkButton* btn, GtkWidget* win_menu);
#endif
