

#include "graphics.h"
#include<stdio.h>
#include<math.h>
#include <gtk/gtk.h>
#include "bresenham.h"

void bresenham_line(GtkButton* btn, GtkWidget* win_menu)
{
    //hide the menu window
    gtk_widget_hide(win_menu);


    GtkBuilder* builder = gtk_builder_new_from_file ("glade/main.glade");
    GtkWidget* win_bresenhamL = GTK_WIDGET(gtk_builder_get_object(builder,"win_bresenhamL"));
    GtkWidget* btn_drawL = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawL"));

    GtkWidget* entry_x1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawL"));
    GtkWidget* entry_y1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawL"));
    GtkWidget* entry_x2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawL"));
    GtkWidget* entry_y2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawL"));

    // get the entries input

	int gd,gm,x,y,end,p,x1,x2,y1,y2,dx,dy;
	detectgraph(&gd,&gm);


	printf("Enter the value of x1 : ");
	scanf("%d",&x1);
	printf("Enter the value of y1 : ");
	scanf("%d",&y1);
	printf("Enter the value of x2 : ");
	scanf("%d",&x2);
	printf("Enter the value of y2 : ");
	scanf("%d",&y2);
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

void bresenham_circle()
{
	int gd,gm,xc,yc,r,x,y,p;
	detectgraph(&gd,&gm);


	printf("Enter center of circle :\n");
	scanf("%d\n%d",&xc,&yc);
	printf("Enter radius of circle :\n");
	scanf("%d",&r);
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



