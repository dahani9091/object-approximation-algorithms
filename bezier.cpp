#include <gtk/gtk.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include "bezier.h"
//  entries
GtkWidget* input_x1;GtkWidget* input_y1;GtkWidget* input_x2;GtkWidget* input_y2;
GtkWidget* input_x3;GtkWidget* input_y3;GtkWidget* input_x4;GtkWidget* input_y4;

void bezier(GtkButton* btn, GtkWidget* win){
    gtk_widget_hide(win);
    //points
    int x[4],y[4];
	x[0] = atoi(gtk_entry_get_text(GTK_ENTRY(input_x1))) ; y[0] = atoi(gtk_entry_get_text(GTK_ENTRY(input_y1))) ;
    x[1] = atoi(gtk_entry_get_text(GTK_ENTRY(input_x2))) ; y[1] = atoi(gtk_entry_get_text(GTK_ENTRY(input_y2))) ;
	x[2] = atoi(gtk_entry_get_text(GTK_ENTRY(input_x3))) ; y[2] = atoi(gtk_entry_get_text(GTK_ENTRY(input_y3))) ;
	x[3] = atoi(gtk_entry_get_text(GTK_ENTRY(input_x4))) ; y[3] = atoi(gtk_entry_get_text(GTK_ENTRY(input_y4))) ;
	int gr = DETECT, gm, i;
	double t, xt, yt;
	initgraph(&gr, &gm,NULL);
	for(t=0.0;t<1.0;t+=0.0005){
		xt=pow((1.0-t),3)*x[0]+3*t*pow((1.0-t),2)*x[1]+3*pow(t,2)*(1.0-t)*x[2]+pow(t,3)*x[3];
		yt=pow((1.0)-t,3)*y[0]+3*t*pow((1.0)-t,2)*y[1]+3*pow(t,2)*(1.0-t)*y[2]+pow(t,3)*y[3];
		putpixel(xt,yt,4);

	}
	for(i=0;i<4;i++){
		putpixel(x[i],y[i],5);
		circle(x[i],y[i],2);
		delay(2);
	}
	getch();
	closegraph();
}

void bezier_curve(GtkButton* btn, GtkWidget* win_menu){


    /// hide the menu window
    gtk_widget_hide(win_menu);

    /// get widgets
    //builder
    GtkBuilder* builder = gtk_builder_new_from_file ("glade/main.glade");
    //window
    GtkWidget* win_bezier = GTK_WIDGET(gtk_builder_get_object(builder,"win_bezier"));
    // draw button
    GtkWidget* btn_drawB = GTK_WIDGET(gtk_builder_get_object(builder,"btn_drawB"));
	//  entries
    input_x1 = GTK_WIDGET(gtk_builder_get_object(builder,"input_x1"));
    input_y1 = GTK_WIDGET(gtk_builder_get_object(builder,"input_y1"));
    input_x2 = GTK_WIDGET(gtk_builder_get_object(builder,"input_x2"));
    input_y2 = GTK_WIDGET(gtk_builder_get_object(builder,"input_y2"));
    input_x3 = GTK_WIDGET(gtk_builder_get_object(builder,"input_x3"));
    input_y3 = GTK_WIDGET(gtk_builder_get_object(builder,"input_y3"));
    input_x4 = GTK_WIDGET(gtk_builder_get_object(builder,"input_x4"));
    input_y4 = GTK_WIDGET(gtk_builder_get_object(builder,"input_y4"));


	//printf("Enter the four control points :");
	//for(i=0;i<4;i++){

		//scanf("%d %d",&x[i],&y[i]);
	//}
    /// connect signals
    g_signal_connect(btn_drawB,"clicked",G_CALLBACK(bezier),win_bezier);

    /// show window
    gtk_widget_show(win_bezier);
}


