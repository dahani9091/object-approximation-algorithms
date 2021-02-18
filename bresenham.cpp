

#include "graphics.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <gtk/gtk.h>
#include "bresenham.h"

// bresenham line entries
GtkWidget* entry_x1;  GtkWidget* entry_y1; GtkWidget* entry_x2 ; GtkWidget* entry_y2;
// bresenham circle entries
GtkWidget* entry_x;  GtkWidget* entry_y; GtkWidget* entry_r;

void bresenham_line(GtkButton* btn, GtkWidget* win_menu)
{
    /// hide the menu window
    gtk_widget_hide(win_menu);

    /// get widgets
    //builder
    GtkBuilder* builder = gtk_builder_new_from_file ("glade/main.glade");
    //window
    GtkWidget* win_bresenhamL = GTK_WIDGET(gtk_builder_get_object(builder,"win_bresenhamL"));
    // draw button
    GtkWidget* btn_drawL = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawL"));
    // entries
    entry_x1 = GTK_WIDGET(gtk_builder_get_object(builder,"entry_x1"));
    entry_y1 = GTK_WIDGET(gtk_builder_get_object(builder,"entry_y1"));
    entry_x2 = GTK_WIDGET(gtk_builder_get_object(builder,"entry_x2"));
    entry_y2 = GTK_WIDGET(gtk_builder_get_object(builder,"entry_y2"));
    /// connect signals
    g_signal_connect(btn_drawL,"clicked",G_CALLBACK(bresenham_line_start),win_bresenhamL);

    /// show window
    gtk_widget_show(win_bresenhamL);

}

void bresenham_line_start(GtkButton* btn, GtkWidget* win){
    gtk_widget_hide(win);
    int gd,gm,x,y,end,p,x1,x2,y1,y2,dx,dy;
	detectgraph(&gd,&gm);

    /// get the entries input
    x1 = atoi(gtk_entry_get_text(GTK_ENTRY(entry_x1)));
    y1 = atoi(gtk_entry_get_text(GTK_ENTRY(entry_y1)));
    x2 = atoi(gtk_entry_get_text(GTK_ENTRY(entry_x2)));
    y2 = atoi(gtk_entry_get_text(GTK_ENTRY(entry_y2)));



	initgraph(&gd,&gm,nullptr);
	dx=abs(x1-x2);
	dy=abs(y1-y2);
	p = 2*dy-dx;

	if(x1>x2)
	{
		x=x2;
		y=y2;
		end=x1;
	}
	else
	{
		x=x1;
		y=y1;
		end=x2;
	}
	putpixel(x,y,WHITE);

	while(x<=end)
	{
		if(p<0)
		{
			x++;
			p=p+2*dy;
		}
		else
		{
			x++;
			y++;
			p=p+2*(dy-dx);
		}
		putpixel(x,y,WHITE);
		delay(100);
	}

	getch();
	closegraph();
}

void bresenham_circle(GtkButton* btn, GtkWidget* win)
{
    /// hide the menu window
    gtk_widget_hide(win);

    /// widgets
    GtkBuilder* builder = gtk_builder_new_from_file ("glade/main.glade");
    //window
    GtkWidget* win_bresenhamC = GTK_WIDGET(gtk_builder_get_object(builder,"win_bresenhamC"));
    // "draw" button
    GtkWidget* btn_drawC = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawC"));
    // entries
    entry_x = GTK_WIDGET(gtk_builder_get_object(builder,"entry_x"));
    entry_y = GTK_WIDGET(gtk_builder_get_object(builder,"entry_y"));
    entry_r = GTK_WIDGET(gtk_builder_get_object(builder,"entry_r"));
    /// connect signals
    g_signal_connect(btn_drawC,"clicked",G_CALLBACK(bresenham_circle_start),win_bresenhamC);

    /// show window
    gtk_widget_show(win_bresenhamC);


}

void bresenham_circle_start(GtkButton* btn, GtkWidget* win){
    gtk_widget_hide(win);
    int gd,gm,xc,yc,r,x,y,p;
	detectgraph(&gd,&gm);

    /// get the entries input
    xc = atoi(gtk_entry_get_text(GTK_ENTRY(entry_x)));
    yc = atoi(gtk_entry_get_text(GTK_ENTRY(entry_y)));
    r = atoi(gtk_entry_get_text(GTK_ENTRY(entry_r)));


	initgraph(&gd,&gm,"C://TurboC3//BGI");
	x=0;
	y=r;
	p=3-2*r;
	pixel(xc,yc,x,y);

	while(x<y)
	{
		if(p<0)
		{
			x++;
			p=p+4*x+6;
		}
		else
		{
			x++;
			y--;
			p=p+4*(x-y)+10;
		}
		pixel(xc,yc,x,y);
	}

	getch();
	closegraph();
}

void pixel(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}



